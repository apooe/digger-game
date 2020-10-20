#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Digger.h"


class LifePresent : public Present
{
public:
	//c-tor
	using Present::Present;

	//d-tor
	~LifePresent();

	virtual void collisionObj(Digger& digger);
private:
	
};
