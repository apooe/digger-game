#include "RocksPresent.h"


RocksPresent::~RocksPresent()
{
}

void RocksPresent::collisionObj(Digger& digger)
{
	m_isRemove = true;
	digger.bonus(1); //rocks
	digger.collisionObj(*this);
}