#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include"Wall.h"
#include"Diamond.h"
#include"Monster.h"
#include"Present.h"

const int DEFAULT_CASE = -1; //for present type
const float SPEED = 185.f; //speed of digger

class Digger : public MovingObject
{
public:
	//c-tor
	Digger(const Texture& texture, const Vector2f& pos, float size);
	//d-tor
	~Digger();
	void setRocks(int rocks);//set new number of rocks eatable
	void setDiamonds(int Diamonds); // set number of diamond
	void setStartPosition(const Vector2f & position); //set start pos of digger
	void reset(); //reset for digger
	Vector2f getPosition() const; //get position of digger
	int getRocksEatable() const ; // get number of rocks eatable
	int getDiamonds() const; // return num of start diamonds
	void initiazeBonus(); //for bonus present
	bool getDiamondsEaten() const; // get num of diamonds
	void setDiamondsEaten(); // set diamonds number
	void bonus(int bonus); //for bonus present
	int getBonus() const ; //return bonus type
	
	//functions for each static object with digger
	//and each moving object with digger 
	virtual void collisionObj(Digger& digger) override;
	virtual void collisionObj(Wall& wall) override;
	virtual void collisionObj(Rock& rock) override;
	virtual void collisionObj(Diamond& diamond) override;
	virtual void collisionObj(Present& present) override;
	virtual void collisionObj(Monster& monster) override;

;

private:
	//set direction for digger
	Vector2f setDirection(float deltaTime, const Vector2f diggerPos, const Vector2f monsterPos);
	int m_rocksEatable;//num og rocks eatable
	bool m_levelFinished;//if level finished
	bool m_diamondIsEaten = false;//to remove diamond
	int m_diamonds;//num of diamond to eat
	int m_bonus = DEFAULT_CASE;//type of present
	
	
	
	


};


