#include "LoadResources.h"
#include <Windows.h>
#include <iostream>

LoadResources::LoadResources()
{
	openFile(FILE_NAME);
	m_textures.resize(NUM_OF_TEXTURES);

	loadTexture(m_textures[T_BACKGROUND], "back.png");
	loadTexture(m_textures[T_MENUBTN], "start.png");
	loadTexture(m_textures[T_EXIT], "exit.png");
	loadTexture(m_textures[T_DIGGER], "digger.png");
	loadTexture(m_textures[T_TILE], "tile.png");
	loadTexture(m_textures[T_WALL], "wall.png");
	loadTexture(m_textures[T_ROCK], "rock.png");
	loadTexture(m_textures[T_DIAMOND], "diamond.png");
	loadTexture(m_textures[T_CLOCK], "clock.png");
	loadTexture(m_textures[T_INFINITY], "infinity.png");
	loadTexture(m_textures[T_MONSTER], "monster.png");
	loadTexture(m_textures[T_LIFE], "life.png");
	loadTexture(m_textures[T_LEVEL], "level.png");
	loadTexture(m_textures[T_SCORE], "score.png");
	loadTexture(m_textures[T_ROCK_COUNTER], "rockCounter.png");
	loadTexture(m_textures[T_SMART_MONSTER], "smartMonster.png");
	loadTexture(m_textures[T_WINNER], "winner.png");
	loadTexture(m_textures[T_OVER], "gameOver.png");
	loadTexture(m_textures[T_EXIT_BTN], "ExitBtn.png");
	loadTexture(m_textures[T_LOCITION], "locition.png");
	loadTexture(m_textures[T_MAP], "map.png");
	loadTexture(m_textures[T_SOUND], "sound.png");
	loadTexture(m_textures[T_MUTE], "mute.png");
	loadTexture(m_textures[T_COIN], "coin.png");
	loadTexture(m_textures[T_HEART], "heart.png");
	loadTexture(m_textures[T_PRES_SCORE], "presScore.png");
	loadTexture(m_textures[T_PRES_TIME], "presTime.png");
	loadTexture(m_textures[T_PRES_ROCK], "presRock.png");
	loadTexture(m_textures[T_LOSER], "lose.png");
	loadTexture(m_textures[T_BACK_END], "backend.png");
	loadFont(m_font, "pixel.ttf");

}

LoadResources::~LoadResources()
{
}

ifstream& LoadResources::getFile()
{
	return m_file;
}

const Texture& LoadResources::getBackground() const
{
	return m_textures[T_BACKGROUND];
}

const Texture& LoadResources::getWinner() const
{
	return m_textures[T_WINNER];
}
//
const Texture& LoadResources::getMenuBtn() const
{
	return m_textures[T_MENUBTN];
}

const Texture& LoadResources::getExitBtn() const
{
	return m_textures[T_EXIT];
}
const Texture& LoadResources::getPlayer() const
{
	return m_textures[T_DIGGER];
}

const Texture& LoadResources::getWall() const
{
	return m_textures[T_WALL];
}
//
const Texture& LoadResources::getRock() const
{
	return m_textures[T_ROCK];
}

const Texture& LoadResources::getDiamond() const
{
	return m_textures[T_DIAMOND];
}

const Texture& LoadResources::getTile() const
{
	return m_textures[T_TILE];
}

const Texture& LoadResources::getMonster() const
{
	return m_textures[T_MONSTER];
}

const Texture& LoadResources::getLevel() const
{
	return m_textures[T_LEVEL];
	// TODO: insert return statement here
}

const Texture& LoadResources::getScore() const
{
	return m_textures[T_SCORE];
}

const Texture& LoadResources::getSmartMonster() const
{
	return m_textures[T_SMART_MONSTER];
}

const Texture& LoadResources::getLife() const
{
	return m_textures[T_LIFE];
}

const Texture& LoadResources::getClock() const
{
	return m_textures[T_CLOCK];
}

const Texture& LoadResources::getInfinity() const
{
	return m_textures[T_INFINITY];
}

const Texture& LoadResources::getRockCounter() const
{
	return m_textures[T_ROCK_COUNTER];
}

const Texture& LoadResources::getGameover() const
{
	return m_textures[T_OVER];
}


const Texture& LoadResources::getExit() const
{
	return m_textures[T_EXIT_BTN];
}

const Texture& LoadResources::getLoction() const
{
	return m_textures[T_LOCITION];
}

const Texture& LoadResources::getMap() const
{
	return m_textures[T_MAP];
}

const Texture& LoadResources::getSound() const
{
	return m_textures[T_SOUND];
}

const Texture& LoadResources::getMute() const
{
	return m_textures[T_MUTE];
}

const Texture& LoadResources::getCoin() const
{
	return m_textures[T_COIN];
}

const Texture& LoadResources::getHeart() const
{
	return m_textures[T_HEART];
}

const Texture& LoadResources::getScorePres() const
{
	return m_textures[T_PRES_SCORE];
}

const Texture& LoadResources::getTimePres() const
{
	return m_textures[T_PRES_TIME];
}

const Texture& LoadResources::getRockPres() const
{
	return m_textures[T_PRES_ROCK];
}

const Texture& LoadResources::getLoser() const
{
	return m_textures[T_LOSER];
}

const Texture& LoadResources::getEndBack() const
{
	return m_textures[T_BACK_END];
}

const Font& LoadResources::getFont() const
{
	return m_font;
}





//open file board.txt
void LoadResources::openFile(string fileName)
{
	m_file.open(fileName);
	if (!m_file.is_open())	
	{
		std::cerr << "cannot open file";
		exit(EXIT_FAILURE);
	}
}

//loard texture from vector of textures
void LoadResources::loadTexture(Texture& texture, string path)
{
	if (!texture.loadFromFile(path))	
	{
		std::cout << "Error loading texture!";
		exit(EXIT_FAILURE);
	}
}
//load font
void LoadResources::loadFont(Font& font, string path)
{
	if (!font.loadFromFile(path))
	{
		std::cerr << "cannot open font";
		exit(EXIT_FAILURE);
	}
}

sf::Sound LoadResources::loadMusic(string fileName)
{
	sf::SoundBuffer music;
	
	if (!music.loadFromFile(fileName))
	{
		std::cerr << "cannot open file";
		exit(EXIT_FAILURE);
	}

	sf::Sound sound;
	sound.setBuffer(music);
	return sound;

}



