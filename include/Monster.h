#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include"Wall.h"
#include"Diamond.h"
#include"Present.h"
#include"Rock.h"

using sf::Vector2f;
using sf::Keyboard;

class Monster : public MovingObject
{
public:
	//c-tor
	Monster(const Texture& texture, const Vector2f& position, float size);
	//d-tor
	~Monster();

	//set the start position of monster
	void setStartPosition(const Vector2f& position);
	//reset with start position of monster
	void reset();

	//get position of monster
	Vector2f getPosition() const;

	// collision between monster and digger
	virtual void collisionObj(Digger& digger) override;

	// collision between monster and monster
	virtual void collisionObj(Monster& monster) override;

	// collision between monster and wall
	virtual void collisionObj(Wall& wall) override;

	// collision between monster and rock
	virtual void collisionObj(Rock& rock) override;

	// collision between monster and diamond
	virtual void collisionObj(Diamond& diamond) override;

	// collision between monster and present
	virtual void collisionObj(Present& present) override;

	//boolean isRemove became true
	void setIsRemove();
	;

protected:

	//for direction of the monster
	void monsterDirection(float dt);

	
private:
	//for collision with wall
	bool m_wall;
	//for collision with rock
	bool m_rock;
	sf::Clock m_clock;
	sf::Time m_movementTime = sf::milliseconds(40);;


};


