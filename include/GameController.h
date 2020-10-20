#pragma once
//----------------------Includes----------------------
#include "LoadResources.h"
#include <SFML/Graphics.hpp>      
#include "StaticObject.h"
#include "Data.h"
#include "SmartMonster.h"
#include "NormalMonster.h"
#include "MainMenu.h"
#include "LifePresent.h"
#include "RocksPresent.h"
#include "TimePresent.h"
#include "ScorePresent.h"

//----------------------Using's----------------------
using sf::RenderWindow;
using std::unique_ptr;
using sf::Event;
using sf::Clock;
using sf::View;

class GameController
{
public:
	
	GameController(LoadResources& resource); //c-tor
	~GameController();// D-tor
	//creating/Drawing window ,creat game board, checks for collision's,and game logic.
	void startPlay();
	void drawOject(); //draw function
	// Moving The Digger and monsters according clock Time 
	void moveObject();
	void handleEvents();
	void collision();// Check collisons( Digger-items ),( Monster-items ), ( Monster-Digger )
	void resetGame();//reset level
	void  checkGameObject();// Handle game event after colision and remove
	void updateScore(); //update score 
	void getPresentType();//Different presents for digger
	void updateCamera();// move the view with Digger
	void addTextureFont();



	
private:
	void preGameStart(); //start game
	void checkGameTimer(); //check timer limit
	void createPresent(const Vector2f& currPos); // create present
	void getGameElements(int col, int row); //read all Objects from file
	bool winLevel(); // Check if player win level
	bool readLevel(); //read all data of level
	vector<Texture> textureMenue;


	vector<unique_ptr<StaticObject>> m_staticObj; 
	vector<unique_ptr<Monster>> m_monster;
	unique_ptr<Digger> m_digger; 
	unique_ptr<MenuBtn> m_exit;// Exit Button

 	Data m_data; // To update and draw the game Data(rocks,score,timer,level)
	Board m_board; // The main board to create window and print messages
	RenderWindow m_window; 
	ifstream& m_file; // To read file 
	LoadResources& m_resource; // To load resources from LoadResources class
	Clock m_gameClock; // Timer for the Game
	bool m_keepRocks = false;
	bool is_win;
	int m_rocks; //Number of rocks
	float m_timer; // The game start time
	int m_diamonds; // Number of Dimanonds
	MainMenu m_menu; //to start the game from menu or exit 
	sf::Music m_backroundMusic;
	sf::Music m_music;
};

