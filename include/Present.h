#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "digger.h"


using sf::Vector2f;
using sf::Texture;
using sf::Keyboard;

class Present : public StaticObject
{
public:
	//c-tor
	Present(const Texture& texture, const Vector2f& position, float size);
	//d-tor
	~Present();

	void collisionObj(Digger& digger);


	void collisionObj(Monster& monster);

	void collisionObj(Wall& wall);

	void collisionObj(Rock& rock);


	void collisionObj(Diamond& diamond);


	void collisionObj(Present& present);
	
	




private:

};

