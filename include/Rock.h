#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Digger.h"

class Rock : public StaticObject
{
public:
	//c-tor
	using StaticObject::StaticObject;
	//d-tor
	~Rock();

	//collision between rock and digger
	virtual void collisionObj(Digger& digger) override;
	//collision between rock and wall
	virtual void collisionObj(Wall& wall) override;
	//collision between rock and rock
	virtual void collisionObj(Rock& rock) override;
	//collision between rock and diamond
	virtual void collisionObj(Diamond& diamond) override;
	//collision between rock and present
	virtual void collisionObj(Present& present) override;
	//collision between rock and monster
	virtual void collisionObj(Monster& monster) override;

};
