#pragma once
#include <SFML/Graphics.hpp>
#include"GameObject.h"

using sf::Vector2f;

class MovingObject : public GameObject
{
public:
	//c-tor
	MovingObject(const Texture& texture, const Vector2f& pos, float size);
	//d-tor
	~MovingObject();

	//reset the position object 
	void reset();

	//function move for smart monsters 
	void move(const Vector2f& diggerPos, const Vector2f& monsterPos, float deltaTime, const RenderTexture& panel);


protected:
	//set direction of objects
	virtual Vector2f setDirection(float deltaTime, const Vector2f diggerPos, const Vector2f monsterPos) = 0;
	//stop the object
	void stop();
	//vertex of start position in the game
	Vector2f m_startingPos;

	//speed of moving object
	float m_speed;

	//direction for object
	Vector2f m_direction;


private:
	bool isInBounds(const RenderTexture& panel);

};

