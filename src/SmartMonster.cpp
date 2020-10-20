#include "SmartMonster.h"
#include <iostream>

Vector2f SmartMonster::setDirection(float deltaTime, const Vector2f diggerPos, const Vector2f monsterPos)
{

	float xDis = diggerPos.x - monsterPos.x;
	float yDis = diggerPos.y - monsterPos.y;
	
	
	float distance = sqrt((xDis * xDis) + (yDis * yDis));
	

	if (distance <= 250.0f)
		dontMoveRand = true;
	else
		dontMoveRand = false;

	if (dontMoveRand)
	{
		//for chane direction of monster
		if ((m_clock.getElapsedTime().asSeconds()) >= 0.5)
		{
			if (abs(xDis) >=abs(yDis)) 
			{
				if (xDis >= 0)	
					m_direction.x = m_speed  * deltaTime;	// Right
				else
					m_direction.x = -m_speed * 2 * deltaTime;	// Left

				return { m_direction.x , 0 };
			}

			else
			{
				if (yDis >= 0)	// Configure Y axis
					m_direction.y = m_speed * 2 * deltaTime;	// Down
				else
					m_direction.y = -m_speed * deltaTime;	// U
				return { 0 , m_direction.y };
			}

	
			m_clock.restart();
		}
		
	}
	else
		monsterDirection(deltaTime);
	return m_direction;

}

