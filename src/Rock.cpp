#include "Rock.h"

Rock::~Rock()
{
}

void Rock::collisionObj(Digger& digger)
{
	m_isRemove = true;	 //to remove it from game
	digger.collisionObj(*this);

}

void Rock::collisionObj(Wall& wall)
{
}

void Rock::collisionObj(Rock& rock)
{

}

void Rock::collisionObj(Diamond& diamond)
{
}

void Rock::collisionObj(Present& present)
{
}

void Rock::collisionObj(Monster& monster)
{
	monster.collisionObj(*this); //for stoping monster
}
