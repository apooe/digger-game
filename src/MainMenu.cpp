#include "MainMenu.h"
#include <iostream>

using sf::VideoMode;
using std::make_unique;
using sf::Vector2f;
using sf::Event;


//default d-tor
MainMenu::MainMenu(){}

MainMenu::~MainMenu(){}

void MainMenu::open(const vector <Texture> textures)
{

	sf::Music music;

	 (music.openFromFile("gameSound.wav"));

	music.play();

	//create the background
	m_window.create(VideoMode(), "Crazy Digger", sf::Style::Fullscreen);
	m_background.setSize(Vector2f((float)m_window.getSize().x, (float)m_window.getSize().y));
	m_background.setTexture(&textures[0]);


	m_playBtn = (make_unique<MenuBtn>(textures[1], m_window.getView().getCenter(), BUTTON_SIZE, "PLAY"));
	m_exitBtn = (make_unique<MenuBtn>(textures[1], Vector2f(m_playBtn->getPosition().x, m_playBtn->getPosition().y + (1.2 * BUTTON_SIZE)), BUTTON_SIZE, "EXIT"));
	m_mapView = (make_unique<MenuBtn>(textures[2], Vector2f(m_playBtn->getPosition().x + 100, BUTTON_SIZE * 6), 35));
	m_mapView2 = (make_unique<MenuBtn>(textures[3], Vector2f(m_playBtn->getPosition().x -100 , BUTTON_SIZE * 6), 35));
	m_music = (make_unique<MenuBtn>(textures[4], Vector2f( m_playBtn->getPosition().x + 100 ,BUTTON_SIZE * 7 ), 35));
	m_mute = (make_unique<MenuBtn>(textures[5], Vector2f(m_playBtn->getPosition().x - 100, BUTTON_SIZE * 7), 35));
	
	while (m_window.isOpen())	
	{
		draw(); // draw buttons and back

		handleEvents();

		if (m_gameSound == false) {
			music.stop();
			music.play();
		}
		else
		{
			music.getLoop();
		}
		
	}
}
void setSound() {

}
//update status and step of game
void MainMenu::updateStatus(std::string text)
{

		m_status.setString(text);
		m_status.setOrigin(m_status.getLocalBounds().width / 2.0f, m_status.getLocalBounds().height / 2.0f);
	
}



bool MainMenu::getView() const
{
	return m_diggerView;
}

bool MainMenu::getSound() const
{
	return m_gameSound;
}


void MainMenu::draw()
{
	m_window.clear();	

	//draw buttons and back
	m_window.draw(m_background);	
	m_playBtn->draw(m_window);	
	m_exitBtn->draw(m_window);
	m_mapView->draw(m_window);
	m_mapView2->draw(m_window);
	m_music->draw(m_window);
	m_mute->draw(m_window);

	m_window.display();	
}

void MainMenu::handleEvents()
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
				//position of the mouse
				const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				//start the game
				if (m_playBtn->contains(mousePos))
				{
		
					m_startGame = true;
					m_window.close();
	
				}
				else if (m_exitBtn->contains(mousePos)) {
		
					m_window.close();
					exit(EXIT_FAILURE);
				}
				if (m_mapView->contains(mousePos)) {
					//m_board.gameMessage("DIGGER VIEWR MODE ", Vector2f(m_playBtn->getPosition().x, m_playBtn->getPosition().y + (-1.2 * BUTTON_SIZE)), m_window, false, );
						m_diggerView = true;
				}
					
	
				else if (m_mapView2->contains(mousePos)) {
					//m_board.gameMessage("FULL MAP VIEWR MODE ", Vector2f(m_playBtn->getPosition().x, m_playBtn->getPosition().y + (-1.2 * BUTTON_SIZE)), m_window, false);
					m_diggerView = false;
				}
					

				if (m_music->contains(mousePos)) {
	
					m_gameSound = true;
					
				}

					
				else if (m_mute->contains(mousePos))
				{
					
					m_gameSound = false;
				}

			}
			break;

		case Event::MouseMoved:
			
			const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });

			if (m_playBtn->contains(mousePos)) // if btn contains the mouse	
				m_playBtn->highlight();		//highlight btn
			else
				m_playBtn->unhighlight(); //unhighlight btn

			if (m_exitBtn->contains(mousePos))	// if btn contains the mouse
				m_exitBtn->highlight();  //highlight btn
			else
				m_exitBtn->unhighlight(); //unhighlight btn

			if (m_mapView->contains(mousePos)) {
				m_mapView->highlight();
			}
				
			else
				m_mapView->unhighlight(); //unhighlight btn
			break;
		}
	}
}

