#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "LoadResources.h"
#include "MenuBtn.h"
#include "Board.h"
using std::unique_ptr;
using sf::RenderWindow;
using sf::RectangleShape;

using std::vector;
class MainMenu
{
public:
	//c-tor
	MainMenu();
	//d-tor
	~MainMenu();
	//open the menu window
	void open(const vector <Texture> textures);
	//update status of game
	void updateStatus(std::string text);

	bool getView() const;

	bool getSound() const;

private:
	bool m_startGame = false ;
	bool m_diggerView = false;
	bool m_gameSound = true;
	sf::Text m_status; //step game
	void draw(); // draw menu
	void handleEvents(); 
	RenderWindow m_window; 	//window for menu
		
	RectangleShape m_background; // rectangle background

	unique_ptr<MenuBtn> m_playBtn; //play btn in main menu
	unique_ptr<MenuBtn> m_exitBtn; //exit btn in main menu
	unique_ptr<MenuBtn> m_mapView2;
	unique_ptr<MenuBtn> m_mapView;
	unique_ptr<MenuBtn> m_music;
	unique_ptr<MenuBtn> m_mute;

	sf::Sound m_sound;
	Board m_board;
};

