#include "Digger.h"
#include <iostream>
#include <stdlib.h>   
#include <time.h> 
using sf::Keyboard;


Digger::Digger(const Texture& texture, const Vector2f& position , float size)
	: MovingObject(texture, position, size), m_rocksEatable(0), m_levelFinished(false) , m_diamonds(0)
{
	m_speed = SPEED; //speed of digger
}

Digger::~Digger()
{
}
//set rocks eatable
void Digger::setRocks(int rocks)
{
	m_rocksEatable = rocks; 
}
//set diamonds number to eat
void Digger::setDiamonds(int diamonds)
{



	m_diamonds = diamonds;
}

//set the start pos of digger
void Digger::setStartPosition(const Vector2f& position)
{
	m_startingPos = position;
	m_object.setPosition(position);
}
//reset game for digger
void Digger::reset()
{
	m_levelFinished = false;
	MovingObject::reset();
	//m_object.setPosition(m_startingPos);
	
}
//get position of digger
Vector2f Digger::getPosition() const
{
	return m_object.getPosition();	
}
//get num of rocks eatable
int Digger::getRocksEatable() const
{
	return m_rocksEatable;
}
//return num of diamond
int Digger::getDiamonds() const
{
	return m_diamonds;
}
//get how many diamond is eaten
bool Digger::getDiamondsEaten() const
{
	return m_diamondIsEaten;
}
//set how many diamond is eaten
void Digger::setDiamondsEaten()
{
	m_diamondIsEaten = false;
}


void Digger::collisionObj(Digger& digger)
{
}

void Digger::collisionObj(Wall& wall)
{
	stop();
}

void Digger::collisionObj(Rock& rock)
{
	m_rocksEatable--;
}

void Digger::collisionObj(Diamond& diamond)
{
	m_diamondIsEaten = true;
	m_diamonds--; // digger eat it
}

void Digger::collisionObj(Present& present)
{
}

void Digger::collisionObj(Monster& monster)
{
	m_isRemove = true; //to reset level
	monster.collisionObj(*this);
}



void Digger::bonus(int bonus) 
{
	m_bonus = bonus; 
}

int Digger::getBonus() const 
{
	return m_bonus;
}

void Digger::initiazeBonus()
{
	m_bonus = DEFAULT_CASE; 
}

//return direction of digger
Vector2f Digger::setDirection(float deltaTime, const Vector2f diggerPos, const Vector2f monsterPos)
{
	sf::Sprite sprit;
	if (Keyboard::isKeyPressed(Keyboard::Up)){
		return { 0, -m_speed * deltaTime }; //up
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) //down
		return { 0, m_speed * deltaTime };			
	
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		
		return { -m_speed * deltaTime, 0 }; //left
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
	   
		return { m_speed * deltaTime, 0 }; //right
	}

	return { 0,0 }; 
}
