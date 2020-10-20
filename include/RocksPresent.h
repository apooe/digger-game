#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Digger.h"


class RocksPresent : public Present
{
public:
	//c-tor
	using Present::Present;

	//d-tor
	~RocksPresent();

	virtual void collisionObj(Digger& digger);

private:


};

