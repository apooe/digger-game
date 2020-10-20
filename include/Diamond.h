#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Digger.h"


class Diamond : public StaticObject
{
public:

	// Daimond is a static object
	using StaticObject::StaticObject;
	
	// Default Constructor
	~Diamond();


	//------- Collision Diamond with all Objects -------------------

     // Delete Diamond if hit by Digger
	virtual void collisionObj(Digger& digger) override;

	// Diamond is a static Object Cannot Collision with other Objects
	virtual void collisionObj(Wall& wall) override;
	virtual void collisionObj(Rock& rock) override;
	virtual void collisionObj(Diamond& diamond) override;
	virtual void collisionObj(Present& present) override;
	virtual void collisionObj(Monster& monster) override;



};
