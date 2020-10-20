#include "Board.h"
#include "GameController.h"

Board::Board()
{
}

Board::~Board()
{
}
// Get the Board image from the LoadResources class
// Set the size of Board game Window
void Board::loadBoard(const Texture& texture)
{
	m_board.setSize({ (float)m_windowSpace.getSize().x, (float)m_windowSpace.getSize().y });
	m_board.setTexture(&texture);
}

// Draw the game Board using draw SFML function 
void Board::draw()
{
	m_windowSpace.draw(m_board);
}


// Size of Board Game Window
RenderTexture& Board::getWindowSpace()  
{
	return m_windowSpace;
}

// Creating game board window at the rigth postion
// with width and height
void Board::create(const Vector2f& pos, unsigned width, unsigned height)
{
	m_windowSpace.create(width, height);
	m_sprite.setPosition(pos);	
	m_sprite.setTexture(m_windowSpace.getTexture(), true);
}

// Display game window Board 
void Board::display(RenderWindow& window)
{
	window.draw(m_sprite);
	m_windowSpace.display();
}

// Clear The Board to use it again
void Board::clearBoard()
{
	m_windowSpace.clear(Color::Black);
}


// CREATING THE WON BOARD STATUS
RectangleShape Board::createWindowMsg(const Vector2f& pos)
{
	RectangleShape windowMsg;
	windowMsg.setSize(sf::Vector2f(800, 700));
	windowMsg.setOutlineColor(sf::Color::Red);
	windowMsg.setOutlineThickness(1.5);
	
	windowMsg.setPosition(pos);
	windowMsg.setOrigin(windowMsg.getGlobalBounds().width / 2, windowMsg.getGlobalBounds().height / 2);

	return windowMsg;
}
////update status of game
void Board::updateStatus(std::string text,  RenderWindow &window, const Font& font)
{

	std::string getReady;
	float time = 0;
	sf::Clock clock;
	clock.restart();
	for (int i = 0; i < 5;)
	{
		getReady = text + " " + std::to_string(5 - i);
		time += clock.getElapsedTime().asSeconds();
		Text message(getReady, font, 40);
		message.setPosition(window.getView().getCenter());
		message.setOutlineColor(Color::Black);
		message.setOutlineThickness(4);
		message.setOrigin(message.getGlobalBounds().width / 2, message.getGlobalBounds().height / 2);

		window.draw(message);	// draw the message to the window
		window.display();
		window.clear(sf::Color(96, 168, 48));
		if (time >= 45)
		{
			i++;
			time = 0;
			clock.restart();
		}

	}
}
//create and print message
void Board::gameMessage(string m, Vector2f pos, RenderWindow& window, bool isWin, const Font& font)
{
	Text msg;	
	string s = m;
	s.append("\nPRESS ENTER TO CONTINUE..."); //append string to m
	m = s;
	msg = setMsg(m, pos, isWin, font); //create msg
	window.draw(msg);
	window.display();

	waitEventGame(window);
}
//create the text 
sf::Text Board::setMsg(string m, Vector2f pos, bool statusPlayer, const Font& font)
{
	Text msg(m, font, 35.0f);
	msg.setPosition(pos);
	msg.setFillColor(sf::Color::Yellow);
	msg.setOutlineThickness(2);
	msg.setOutlineColor(sf::Color::Red);

	if (statusPlayer) { //different if it's message winner or loser
		msg.setCharacterSize(TEXT_SIZE - 10);
		msg.setFillColor(sf::Color::White);
		msg.setOutlineThickness(1);
	}
	msg.setOrigin(msg.getGlobalBounds().width / 2, msg.getGlobalBounds().height / 2);
	return msg;
}


//wait even from player
void Board::waitEventGame(RenderWindow& window)
{
	Event event;

	while (window.waitEvent(event))
		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Enter)
				break;
			if (event.key.code == Keyboard::Escape) {
				window.close();
				break;
			}
		}
}
//print message you lose or you win
void Board::endMsg(RenderWindow& window, bool isWin, int score, const Texture& resource, const Texture& back, const Font& font)
{
	RectangleShape background;
	background.setSize(Vector2f((float)window.getSize().x, (float)window.getSize().y));

	background.setTexture(&back);
	window.clear();
	window.draw(background);

	sf::RectangleShape windowMsg = createWindowMsg(window.getView().getCenter());
	windowMsg.setTexture(&resource);//winner texture 
	
	window.draw(windowMsg);
	//score
	Text scoreMsg = setMsg("DIGGER SCORE: " + to_string((int)(score)), { X_AXE, X_AXE + 50 }, true, font);
	scoreMsg.setOrigin(X_AXE_ORI, X_AXE_ORI + 50);
	window.draw(scoreMsg);

	Text exitStr = setMsg("\npress enter to exit......", { X_AXE , X_AXE + 100 }, true, font);
	exitStr.setOrigin(X_AXE_ORI, X_AXE_ORI + 90);

	window.draw(exitStr);
	window.display();
	waitEventGame(window); //wait even from player
}