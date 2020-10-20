#include "GameController.h"
#include <iostream>
#include <stdlib.h>

using sf::Keyboard;
using sf::VideoMode;
using std::make_unique;




GameController::GameController(LoadResources& resource)
	: m_resource(resource), m_file(resource.getFile()) {
	addTextureFont();
}

GameController::~GameController() {}

void GameController::startPlay()
{

	m_menu.open(textureMenue); // open the start game menu

	preGameStart(); // Before the game start create window , dataBar and start message

	while (readLevel()) // Reading from file
	{
		is_win = false;
		while (m_window.isOpen())
		{

			drawOject(); // Draw all the Objects and dataBar
			handleEvents(); // To handle all the events (Exit/continue)
			moveObject(); // The Movment of digger and Monsters

			if (m_menu.getView() == true) //If user Want to play with Digger Viewr
			 updateCamera();

			collision(); //Handle the game collisions
			updateScore(); // Adding 15 to score if Digger eat a DIAMOND or 20 if pass a level
			checkGameObject(); // Check ALL the game object after collosions
			checkGameTimer(); // check the timer of the game

			if (winLevel())
			{
				m_backroundMusic.play();
				m_board.gameMessage("GOOD JOB ! next level ", m_window.getView().getCenter(),m_window,false, m_resource.getFont());
				m_board.updateStatus(LEVELPASSEDMSG, m_window, m_resource.getFont());

				break;
			}
		}

	}
}

bool GameController::winLevel()
{
	if (m_digger->getDiamonds() == 0) // if digger ate all the Diamonds
	{
		is_win = true;
		drawOject();
		m_data.updateScore(LEVEL_ACCOMPLIED); //+20 points
		m_data.updateLevel(); //next level
		return true;
	}
	return false;
}
//draw function 
void GameController::drawOject()
{
	m_data.setRocksEatable(m_digger->getRocksEatable());
	m_window.clear(sf::Color(96, 168, 48));

	m_data.clearBoard();
	m_data.draw(); //draw data bar

	m_data.display(m_window);

	m_board.clearBoard();
	m_board.draw();//draw borad

	for (auto& staticObj : m_staticObj)
		staticObj->draw(m_board.getWindowSpace()); //draw static objects

	m_digger->draw(m_board.getWindowSpace()); //draw digger

	for (auto& monster : m_monster)
		monster->draw(m_board.getWindowSpace());

	m_board.display(m_window);
	m_exit->draw(m_window); //draw button exit

	if(!is_win)
		m_window.display();
}
//move digger and monsters
void GameController::moveObject() 
{
	float dt = m_gameClock.restart().asSeconds();
	m_digger->move({ 0,0 }, { 0,0 }, dt, m_board.getWindowSpace());

	for (auto& monster : m_monster) // move each monster
		monster->move(m_digger->getPosition(), (monster)->getPosition(), dt, m_board.getWindowSpace());
}

void GameController::handleEvents()
{
	Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			m_window.close();
			break;

		case Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (m_exit->contains(mousePos)) { //pressed exit

					m_board.gameMessage("YOU ARE LIVING THE GAME..", m_window.getView().getCenter(), m_window, false, m_resource.getFont());
					m_window.close();
				}
			}

			break;
		default: break;
		}
	}
}
//collisions
void GameController::collision()
{
	// collision for digger and items
	for (auto& staticObj : m_staticObj)
	{
		if (staticObj->getRect().intersects(m_digger->getRect()))
		{
			staticObj->collisionObj(*m_digger);
		}
		// // collisions for monsters and items
		for (auto& monster : m_monster)
		{
			if (staticObj->getRect().intersects(monster->getRect()))
				staticObj->collisionObj(*monster);
		}
	}

	// // collision for monsters and digger
	for (auto& monster : m_monster)
	{
		if (m_digger->getRect().intersects(monster->getRect())){
			m_keepRocks = true;
			m_digger->collisionObj(*monster);
			if ((monster)->getIsRemove())
				break;
		}
	}

}
//reset game level
void GameController::resetGame()
{
	if (m_data.getLives() == 1) // if the game is Over
	{
		m_backroundMusic.stop();
	
		m_music.play();
		m_board.endMsg(m_window, false, m_data.getScoer(), m_resource.getLoser(), m_resource.getEndBack(), m_resource.getFont()); //lost msg
		exit(EXIT_FAILURE);
	}
	m_digger->reset(); //digger reset from start Position

	for (auto& monster : m_monster) // monster reset from start Position
		monster->reset();

	m_data.decreaseLife(); // decrease digger lifes



	m_digger->setRocks(m_rocks);
	
	// Update the game timer
	m_data.updateTimer(m_timer);
	m_gameClock.restart();
}

void GameController::checkGameObject()
{
	//check for all static objects if remove
	for (auto item = m_staticObj.begin(); item != m_staticObj.end(); )
	{
		if ((*item)->getIsRemove()) {
			item = m_staticObj.erase(item); //remove it
			// get type of present
			//if -1 item is not a prensent
			getPresentType(); 
		}
		else
			item++; //next item
	}

	if ((m_digger)->getIsRemove()){ // collision digger - monster - reset level and msg
		m_board.gameMessage("MONSTER ATTACKED YOU!", m_window.getView().getCenter(), m_window, false, m_resource.getFont());
		resetGame();
	}

	if (m_digger->getRocksEatable() <= 0) { //digger eat all rocks eatable - reset level and msg
		m_board.gameMessage("CAN NOT DIGGING MORE ROCKS!", m_window.getView().getCenter(), m_window, false, m_resource.getFont());
		resetGame();
		
	}

}

//if digger ate diamond, update score of databar 
//update num that rest to eat for digger
void GameController::updateScore()
{
	if (m_digger->getDiamondsEaten())
	{
		m_data.updateScore(DIAMONDS_SCORE);
		m_digger->setDiamondsEaten();
	}
}

//get type present from digger and change data bar and/or digger statement 
void GameController::getPresentType() {

	if (m_digger->getBonus() != -1) {
		switch (m_digger->getBonus()) {
		case 0: 
			m_data.setLives();
			break;
			case 1: // +3 rocks eatable
			{
				m_data.setRocksEatable(m_digger->getRocksEatable() + 3);
				m_digger->setRocks(m_digger->getRocksEatable() + 3);
				break;
			}
				
			case 2: {
				m_data.updateScore(5); // +5 points
				break;
			}
			default: { // +10 seconds
				if(m_timer != -1) 
				m_data.updateTimer(m_data.getTimer() + 10);
				break;
			}
		}
		m_digger->initiazeBonus(); // initialize the type bonus
	}
}
//update the camera mvt
void GameController::updateCamera()
{
	sf::Vector2f position(0, 0);
	sf::View view, toolsView;

	position.x = m_digger->getPosition().x + 10 - (m_board.getWindowSpace().getSize().x / 2);
	position.y = m_digger->getPosition().y + 10 - (m_board.getWindowSpace().getSize().y / 2);

	if (position.x < 0)
		position.x = 0;

	if (position.y < 0)
		position.y = 0;

	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	view.reset(sf::FloatRect(position.x, position.y, m_board.getWindowSpace().getSize().x, m_board.getWindowSpace().getSize().y + 2.5f));
	m_window.setView(view);
}

void GameController::addTextureFont()
{
	textureMenue = { m_resource.getBackground(),m_resource.getMenuBtn(), m_resource.getLoction(), m_resource.getMap(), m_resource.getSound(), m_resource.getMute() };
}

//before start the game, display messages, create window, databar, do sound
void GameController::preGameStart()
{
	m_backroundMusic.openFromFile("gameSound.wav");
	m_music.openFromFile("gameOverSound.wav");
	m_backroundMusic.setLoop(true);
	m_backroundMusic.play();

	m_data.loadDataIcons(CELL, m_resource); // loading icon
	m_window.create(sf::VideoMode(), "Crazy Digger", sf::Style::Fullscreen); //create window

	m_data.create({ 0 , 0 }, m_window.getSize().x, HEIGHT * 8); // create data bar

	//create btn exit for data bar
	m_exit = (make_unique<MenuBtn>(m_resource.getExit(), Vector2f( CLOCK_SPACE + 130 ,50 ), EXITBTN_SIZE));

	m_board.updateStatus(LEVELSTART,m_window, m_resource.getFont());
}

//check time limit of game
void GameController::checkGameTimer()
{
	//---------------------TIMER-----------------
	if (m_data.getTimer() <= 0 && m_data.getTimer() != NO_LIMIT) 
	{
		m_board.gameMessage("TIME'S UP!", m_window.getView().getCenter(), m_window, false, m_resource.getFont());
		resetGame(); //reset level
	}
}

//create different presents for the game
void GameController::createPresent(const Vector2f& currPos)
{
	switch (rand() % 4){
	case 0:
		m_staticObj.push_back(make_unique<LifePresent>(m_resource.getHeart(), currPos, PRESENTSIZE));
		break;

	case 1:
		m_staticObj.push_back(make_unique<RocksPresent>(m_resource.getRockPres(), currPos, PRESENTSIZE));
		break;
	case 2:
		m_staticObj.push_back(make_unique<ScorePresent>(m_resource.getScorePres(), currPos, PRESENTSIZE));
		break;
	case 3:
		m_staticObj.push_back(make_unique<TimePresent>(m_resource.getTimePres(), currPos, PRESENTSIZE));
		break;

	}
}
// false while end of game
bool GameController::readLevel()
{
	m_staticObj.clear(); 
	m_monster.clear();

	int rows, cols; //for board
	m_file >> rows >> cols >> m_rocks >> m_timer;

	std::cout << rows << " " << cols << std::endl;
	if (m_file.eof()) {
		m_board.endMsg(m_window, true, m_data.getScoer(), m_resource.getWinner(), m_resource.getEndBack(), m_resource.getFont());
		return false;
	}

	m_board.create(Vector2f(0.f, HEIGHT), (cols * (unsigned)CELL), (rows * (unsigned)CELL));
	m_board.loadBoard(m_resource.getTile()); // create base board of game

	m_data.updateTimer((float)m_timer);

	getGameElements(rows, cols); //read element for game from file
	return true;
}

//get game element from file
void GameController::getGameElements(int row, int col)
{
	int diamondsCounter = 0;
	bool isSmart = false;

	m_file.get();
	for (unsigned i = 0; i < row; i++){
		string line;
		getline(m_file, line);

		for (unsigned j = 0; j < col; j++) //each cell
		{
			Obj_t c = (Obj_t)line[j];
			const Vector2f currPos = Vector2f((float)j * CELL, (float)i * CELL); //current pos into file
			switch (c){
			case O_DIGGER: //digger
				if (!m_digger){
					m_digger = (make_unique<Digger>(m_resource.getPlayer(), currPos, CELL - 18));
					m_digger->setRocks(m_rocks);
				}
				else{ 
					m_digger->setStartPosition(currPos);
					m_digger->reset();
					m_digger->setRocks(m_rocks);
				}
				break;

			case O_WALL:
				m_staticObj.push_back(make_unique<Wall>(m_resource.getWall(), currPos, CELL));
				break;
			case O_DIAMONDS:
				diamondsCounter++;
				m_staticObj.push_back(make_unique<Diamond>(m_resource.getDiamond(), currPos, CELL));
				break;
			case O_ROCK:
				m_staticObj.push_back(make_unique<Rock>(m_resource.getRock(), currPos, CELL));
				break;
			case O_PRESENT: //create each type of presents
				createPresent(currPos);
				break;

			case O_MONSTER:
			{
					if (rand() % 2 == 0) 
						m_monster.push_back(make_unique<SmartMonster>(m_resource.getSmartMonster(), currPos, CELL - 20));
					else 
						m_monster.push_back(make_unique<NormalMonster>(m_resource.getMonster(), currPos, CELL - 25));
			}
			break;
			
			case O_ROCK_PRESENT:	
			
				createPresent(currPos);
				m_staticObj.push_back(make_unique<Rock>(m_resource.getRock(), currPos, CELL));
				break;
			default:
				break;
			}
		}
	}
	m_digger->setDiamonds(diamondsCounter);
}




