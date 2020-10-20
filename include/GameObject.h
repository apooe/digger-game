#pragma once
#include <SFML/Graphics.hpp>

class Digger;
class Wall;
class Rock;
class Present;
class Diamond;
class Monster;

using sf::RenderTexture;
using sf::RectangleShape;
using sf::FloatRect;
using sf::Vector2f;
using sf::Texture;


class GameObject
{
public:
	//c-tor
	GameObject(const Texture& texture, const Vector2f& position, float objectSize);
	//d-tor
	virtual ~GameObject();
	bool getIsRemove() const; // return if remove
	void draw(RenderTexture& obj); // draw object
	FloatRect getRect(); // return bounds of object

	//virtual functions- collisions between objects
	virtual void collisionObj(Digger & digger) = 0;
	virtual void collisionObj(Wall & wall) = 0;
	virtual void collisionObj(Rock& rock) = 0;
	virtual void collisionObj(Diamond& diamond) = 0;
	virtual void collisionObj(Present& present) = 0;
	virtual void collisionObj(Monster& monster) = 0;



protected:
	RectangleShape m_object; // object
	bool m_isRemove; // if must remove object


};

