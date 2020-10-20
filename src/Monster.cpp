#include "Monster.h"

Monster::Monster(const Texture& texture, const Vector2f& position, float size)
	: MovingObject(texture, position, size)
{
	m_speed = 75; //speed of the monster
}


void Monster::setStartPosition(const Vector2f& position)
{
	m_startingPos = position; 
	m_object.setPosition(position); //object monster from moving object
}

void Monster::reset()
{
	//m_levelFinished = false;
	MovingObject::reset();
	//m_object.setPosition(m_startingPos);

}
Monster::~Monster()
{
}

Vector2f Monster::getPosition() const
{
	return m_object.getPosition(); 
}

void Monster::collisionObj(Digger& digger)
{
	m_isRemove = true; // to decrease life and reset level
}

void Monster::collisionObj(Monster& monster)
{
}

void Monster::collisionObj(Wall& wall)
{
	 m_wall = true;
	stop(); //can not pass

}

void Monster::collisionObj(Rock& rock)
{
	 m_rock = true;
	stop(); //can not pass

}

void Monster::collisionObj(Diamond& diamond)
{
}

void Monster::collisionObj(Present& present)
{
}

void Monster::setIsRemove()
{
	m_isRemove = true; 
}

void Monster::monsterDirection(float dt)
{
	//for chane direction of monster
	if ((m_clock.getElapsedTime().asSeconds()) >= 1)	
	{
		int direction = rand() % 4; //randomly choose direction
		switch (direction) {
		case 0:
			m_direction = Vector2f(0, -m_speed * dt);
			break;
		case 1:
			m_direction = Vector2f(0, m_speed * dt);
			break;
		case 2:
			m_direction = Vector2f(-m_speed * dt, 0);
			break;
		case 3:
			m_direction = Vector2f(m_speed * dt, 0);
			break;
		default:
			m_direction = Vector2f(0, 0);
			break;
		}
		m_clock.restart(); 
	}
}



