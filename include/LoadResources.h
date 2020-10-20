#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Constant.h"
#include <SFML/Audio.hpp>
#include <memory>


using std::ifstream;
using std::vector;
using std::string;
using sf::Texture;
using sf::Font;
const string FILE_NAME = "board.txt";

class LoadResources
{
public:
	//c=tor
	LoadResources();
	//d-tor
	~LoadResources();

	//get the file 
	ifstream& getFile();

	const Texture& getBackground() const;	// Background texture
	const Texture& getMenuBtn() const;		//menu button texture
	const Texture& getExitBtn() const;		// exit button texture
	const Texture& getPlayer() const;		// digger texture
	const Texture& getWall() const;		// Wall texture
	const Texture& getRock() const;		// Rock texture
	const Texture& getDiamond() const;		// diamond texture
	const Texture& getWinner() const;		// Present texture
	const Texture& getLife()const;			// life texture
	const Font & getFont() const;		// font
	const Texture& getClock() const;		// Clock texture
	const Texture& getInfinity() const;	// Infinity  texture
	const Texture& getTile() const; // tile texture
	const Texture& getMonster() const; 	// monster  texture
	const Texture& getLevel() const; 	// level icon  texture
	const Texture& getScore() const; //	score icon  texture
	const Texture& getSmartMonster() const;    // smart monster texture
	const Texture& getRockCounter() const; //rock icon texture
	const Texture& getGameover() const; //game over texture
	const Texture& getExit() const; // get exit texture
	const Texture& getLoction() const; // get Locition texture
	const Texture& getMap() const; // get Map texture
	const Texture& getSound() const; // get Map texture
	const Texture& getMute() const; // get Map texture
	const Texture& getCoin() const; // get Map texture
	const Texture& getHeart() const; //get score p
	const Texture& getScorePres() const; 
	const Texture& getTimePres() const;
	const Texture& getRockPres() const;
	const Texture& getLoser() const;
	const Texture& getEndBack() const;
	

	sf::Sound  loadMusic(string fileName);
private:
	//open fle to read into
	void openFile(string fileName);	

	//load all texture and check
	void loadTexture(Texture& texture,	string path);
	//load the font  of game
	void loadFont(Font& font, string path);	

	
	ifstream m_file; // file board.txt			
	vector<Texture> m_textures;	//vector of textures
	Font m_font; //the font for game
	
};

