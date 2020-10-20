#include"NormalMonster.h"


Vector2f NormalMonster::setDirection(float deltaTime, const Vector2f diggerPos, const Vector2f monsterPos)
{
	monsterDirection(deltaTime); // get randomly direction for normal monster
	return m_direction;
}
