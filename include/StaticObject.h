#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>


class StaticObject : public GameObject
{
public:

	//c-tor
	using GameObject::GameObject;
	//d-tor
	virtual ~StaticObject();

	//get if static object is removed from the game
	bool getIsRemove() const;


};
