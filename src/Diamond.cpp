#include "Diamond.h"

// Defualt
Diamond::~Diamond()
{
}
// If Digger hit Diamond, Remove the Dimaond and go to Digger collison
void Diamond::collisionObj(Digger& digger)
{
	m_isRemove = true;
	digger.collisionObj(*this);
}

void Diamond::collisionObj(Wall& wall)
{
}

void Diamond::collisionObj(Rock& rock)
{
}

void Diamond::collisionObj(Diamond& diamond)
{
}

void Diamond::collisionObj(Present& present)
{
}

void Diamond::collisionObj(Monster& monster)
{
}

