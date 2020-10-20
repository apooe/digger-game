#include"Data.h"
#include <iostream>

Data::~Data()
{
}

// Set the Number of rocks Digger can Eat
void Data::setRocksEatable(int rocks)
{
	m_rock = rocks;
}

// Add score to the Current score (15/20)
void Data::updateScore(int score)
{	
	m_score += score;
}

// Next Level
void Data::updateLevel()
{
	m_level++;
}

// Update the timer of game
void Data::updateTimer(float deltaTime)
{
	m_gameTime.restart();
	m_timer = deltaTime;
}


// Make text to show it to user
Text Data::setText(const Font& font, const Vector2f& position, unsigned size, const Color& color)
{
	m_text.setFont(font);
	m_text.setCharacterSize(FONTSIZE);
	m_text.setFillColor(color);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition({ position.x, position.y + 50 - FONTSIZE });
	m_text.setOrigin(-m_sprite.getGlobalBounds().width / 2 + m_text.getGlobalBounds().width / 2, 0);	
	return m_text;
}

// Make icons for Data
RectangleShape Data::setIcon(const Vector2f& size, const Texture& texture, const Vector2f& position)
{
	RectangleShape shape(size);
	shape.setTexture(&texture);
	shape.setPosition(position);
	shape.setOrigin(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2);
	
	return shape;
}
// Get the Number of lifes for digger
int Data::getLives() const
{
	return m_lives;
}
//get score of digger
int Data::getScoer() const
{
	return m_score;
}

// Get the current game time
float Data::getTimer() const
{
	return m_timer;
}

// Draw icons and text for game dama
void Data::draw()
{
	m_levelIcon.setString( to_string((int)m_level +1));
	m_windowSpace.draw(m_levelIcon);
	m_windowSpace.draw(m_levelPic);
//--------------------------------------------------------------
	m_scoreCounter.setString(to_string((int)m_score));
	m_windowSpace.draw(m_scoreCounter);
	m_windowSpace.draw(m_scorePic);
//--------------------------------------------------------------
	m_rockCounter.setString(to_string((int)m_rock));
	m_windowSpace.draw(m_rockCounter);
	m_windowSpace.draw(m_rockPic);
//--------------------------------------------------------------
	m_livesCounter.setString(to_string((int)m_lives));
	if (m_lives < NUM_OF_LIFE) {
		m_livesCounter.setColor(Color::Red);
	}

	else
		m_livesCounter.setColor(Color::White);
	m_windowSpace.draw(m_livesCounter);
	m_windowSpace.draw(m_livesPicCounter);
//------------------------------------------------------------

	m_windowSpace.draw(m_clockIcon);

	if (m_timer == -1)	{
		m_infinityIcon.setPosition(m_clockIcon.getPosition().x + m_clockIcon.getSize().x, m_infinityIcon.getPosition().y);
		m_windowSpace.draw(m_infinityIcon);	
	}

	else{
		float dt = m_gameTime.restart().asSeconds();	
		m_timer -= dt;	
		m_timerCounter.setString(to_string((int)m_timer));
		if (m_timer > 10)
			m_timerCounter.setColor(Color::White);
		else
			m_timerCounter.setColor(Color::Red);
		
		m_windowSpace.draw(m_timerCounter);
	}
}
// Decrease life number
void Data::decreaseLife()
{
	m_lives--;
}
//increase life number
void Data::setLives()
{
	m_lives++;
}

// make icons and text for each data
void Data::loadDataIcons(float icon, const LoadResources& m_resource)
{
	const float middleHeight = (float)m_windowSpace.getSize().y / 2;

	m_levelIcon = setText(m_resource.getFont(), { LEVEL_SPACE - 7, middleHeight + 70 }, TEXT_SIZE, Color::White);
	m_levelPic = setIcon({ icon * 2, icon * 2 }, m_resource.getLevel(), { LEVEL_SPACE  , middleHeight + 50 });

	m_scoreCounter = setText(m_resource.getFont(), { SCORE_SPACE - 12 ,  middleHeight + 70 }, TEXT_SIZE, Color::White);
	m_scorePic = setIcon({ icon , icon }, m_resource.getScore(), { SCORE_SPACE  , middleHeight + 50 });

	m_rockCounter = setText(m_resource.getFont(), { ROCKS_SPACE - 8 , middleHeight + 70 }, TEXT_SIZE, Color(220, 220, 220));
	m_rockPic = setIcon({ icon , icon }, m_resource.getRockCounter(), { ROCKS_SPACE  , middleHeight + 50 });

	m_timerCounter = setText(m_resource.getFont(), { CLOCK_SPACE - 2 , middleHeight + 70 }, TEXT_SIZE, Color(0, 255, 255));
	m_clockIcon = setIcon({ icon, icon }, m_resource.getClock(), { CLOCK_SPACE , middleHeight + 50 });

	m_livesCounter = setText(m_resource.getFont(), { LIVES_SPACE - 4, middleHeight + 70 }, TEXT_SIZE, Color::White);
	m_livesPicCounter = setIcon({ icon, icon }, m_resource.getLife(), { LIVES_SPACE , middleHeight + 50 });

	m_infinityIcon = setIcon({ icon, icon }, m_resource.getInfinity(), { 0, middleHeight });
}


