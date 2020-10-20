#include "Present.h"

Present::Present(const Texture& texture, const Vector2f& position, float size)
	: StaticObject(texture, position, size)
{
}

Present::~Present()
{
}

void Present::collisionObj(Digger& digger)
{
	m_isRemove = true;
	digger.collisionObj(*this);

}

void Present::collisionObj(Monster& monster)
{
}

void Present::collisionObj(Wall& wall)
{

}
void Present::collisionObj(Rock& rock)
{

}

void Present::collisionObj(Diamond& diamond)
{
}

void Present::collisionObj(Present& present)
{
}