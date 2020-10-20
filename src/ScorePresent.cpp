#include "ScorePresent.h"


ScorePresent::~ScorePresent()
{
}

void ScorePresent::collisionObj(Digger& digger)
{
	m_isRemove = true;
	digger.bonus(2); //rocks
	digger.collisionObj(*this);
}