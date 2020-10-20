#include "GameObject.h"

GameObject::GameObject(const Texture& texture, const Vector2f& position, float objectSize)
	:m_isRemove(false), m_object({ objectSize, objectSize })
{
	m_object.setTexture(&texture); //texture
	m_object.setPosition(position); // object position	
}

GameObject::~GameObject()
{
}

bool GameObject::getIsRemove() const
{
	return m_isRemove; 
}
//draw function
void GameObject::draw(RenderTexture& obj)
{
	obj.draw(m_object);
}

//return bounds of object
FloatRect GameObject::getRect()
{
	return m_object.getGlobalBounds();
}


void GameObject::collisionObj(Monster& monster)
{
}

