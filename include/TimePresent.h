#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Digger.h"


class TimePresent : public Present
{
public:
	//c-tor
	using Present::Present;

	//d-tor
	~TimePresent();

	virtual void collisionObj(Digger& digger);
private:

};
