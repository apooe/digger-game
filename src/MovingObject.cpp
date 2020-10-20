#include "MovingObject.h"

MovingObject::MovingObject(const Texture& texture, const Vector2f& position, float size)
	: GameObject(texture, position, size), m_speed(0), m_startingPos(position)
{

}

MovingObject::~MovingObject()
{
}

void MovingObject::reset()
{
	m_isRemove = false; // to know if digger is dead
	m_object.setPosition(m_startingPos); //reset with start position
}

void MovingObject::move(const Vector2f &diggerPos, const Vector2f& monsterPos,float deltaTime, const RenderTexture& panel)
{
	//direction of monsters and digger
	m_direction = setDirection(deltaTime, diggerPos, monsterPos);
	m_object.move(m_direction); //movement

	//if collision with statics objects
	if (!isInBounds(panel)) {
		stop();
	}
}

//stop the moving object
void MovingObject::stop()
{
	m_object.move(-m_direction);	
}

// for collision and to stop moving object
bool MovingObject::isInBounds(const RenderTexture& panel)
{
	if (m_object.getPosition().x < 0 || m_object.getPosition().y < 0 ||			
		m_object.getPosition().x >(panel.getSize().x - m_object.getSize().x) ||	
		m_object.getPosition().y >(panel.getSize().y - m_object.getSize().y))	
		return false;//collision - return false to stop moving object

	return true; // no collision
}


