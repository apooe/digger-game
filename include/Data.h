#pragma once
//------------------ Include's---------------
#include"Board.h"
#include"LoadResources.h"
#include <SFML/Graphics.hpp>

//------------------ Using's-------------------
using std::to_string;
using sf::Text;
using sf::Font;

//-------------------Data Class----------------------------
class Data :public Board
{
public:
	// Building Board for data tools
	using Board::Board;
	// Defualt Constructor
	~Data();
   // Get the icon image from LoadResources Class
	void loadDataIcons(float icon, const LoadResources& m_resource);

	// Get the Number of lifes lift for Digger
	int getLives() const;
	// Get the score game
	int getScoer() const;

	// Get current time of the game
	float getTimer() const;

	// Update the score of digger
	void updateScore(int score);

	// Update the Level of game
	void updateLevel();

	// Update Clock for the game
	void updateTimer(float deltaTime);

	// Add/LESS Rocks for digger
	void setRocksEatable(int rocks);

	//Decrease life for the digger
	void decreaseLife();

	//Decrease life for the digger
	void setLives();

	// Draw all Date about the game
	void draw();
	
private:
	// Set Icons and Get Icons Images 
	RectangleShape setIcon(const Vector2f& size, const Texture& texture, const Vector2f& position);

	// Set Text for icon of databar
	Text setText(const Font& font, const Vector2f& position, unsigned size, const Color& color);

	int m_lives = NUM_OF_LIFE ; // Digger has 3 lifes
	int m_score = 0; // game score
	float m_timer = 0; // the timer for the game
	int m_rock = 0; // Rocks Digger can eat
	int m_level = 0; // the current Level Game

	sf::Clock m_gameTime; // To set timer for the Game


	// Icons and Text for time.
	RectangleShape m_clockIcon;	
	Text m_timerCounter;
	RectangleShape m_infinityIcon;	

	// Icons and Text for Digger lifes.
	RectangleShape m_livesPicCounter;
	Text m_livesCounter;

	// Icons and Text for Level.
	RectangleShape m_levelPic;
	Text m_levelIcon;

	// Icons and Text for Score.
	RectangleShape m_scorePic;
	Text m_scoreCounter;

	// Icons and Text for Rocks.
	RectangleShape m_rockPic;
	Text m_rockCounter;

	Text m_text; // set a text
	

	
};

