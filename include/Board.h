#pragma once
//--------------------Include's-----------------------
#include <SFML/Graphics.hpp>
#include <experimental/vector>
#include <memory>
#include "Tile.h"
#include "LoadResources.h"
//----------------------Using's-----------------------
using sf::Color;
using sf::Sprite;
using sf::RenderWindow;
using sf::RenderTexture;
using sf::Texture;
using sf::Vector2f;
using sf::RectangleShape;
//--------------------Board Class--------------------------
class Board
{
public:
	
	Board();// C-tor
	~Board();	// D-tor
	void loadBoard(const Texture& texture) ;// Get the Board image from the LoadResources class
	RenderTexture& getWindowSpace() ;// return render texture of Board
	// Creating a Board with width and hright and set it on positon 
	void create(const Vector2f& pos, unsigned width, unsigned height);
	// Draw The Board after getting the image and the size
	 void draw() ;
	void display(RenderWindow& window);// display window after drawing it
	void clearBoard();// Clear the Board using color
	RectangleShape createWindowMsg(const Vector2f& pos);//create window for last message
	void updateStatus(std::string text,  RenderWindow & window, const Font& font);//update status of game
	void gameMessage(string m, Vector2f pos, RenderWindow& window, bool isWin, const Font& font);//create andprint message
	sf::Text setMsg(string m, Vector2f pos, bool statusPlayer, const Font& font);//set the string message
	void waitEventGame(RenderWindow& window);//wait event from player
	//lose msg or win message with score
	void endMsg(RenderWindow& window, bool isWin, int score, const Texture& resource, const Texture& back, const Font& font);

protected:

	RenderTexture m_windowSpace;   // render texture of window
	Sprite m_sprite;// To set the board at the Right Position

private:
	
	RectangleShape m_board;//rectangle board

	
};

