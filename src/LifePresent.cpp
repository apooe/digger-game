#include "LifePresent.h"


LifePresent::~LifePresent()
{
}

void LifePresent::collisionObj(Digger& digger)
{
	m_isRemove = true;
	digger.bonus(0); //life
	digger.collisionObj(*this);
}