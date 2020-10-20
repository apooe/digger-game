#pragma once
#include <SFML/Graphics.hpp>
#include "LoadResources.h"

using sf::RectangleShape;
using sf::Texture;
using sf::Vector2f;
using sf::RenderWindow;
using sf::Text;

class MenuBtn
{
public:
	//default c-tor
	MenuBtn();
	//rectangle btn
	MenuBtn(const Texture& texture, const Vector2f& position, unsigned btnSize, string text);
	//round btn
	MenuBtn(const Texture& resource, const Vector2f& position, unsigned btnSize);
	//d-tor
	~MenuBtn();
	void draw(RenderWindow& window); //draw menu btn

	Vector2f getPosition() const; // get position of menu button

	bool contains(const Vector2f& pos) const; //mouse contains or not

	void highlight(); // highlight action

	void unhighlight(); // unhighlight action
private:

	sf::Sprite  m_button; // main menu btn
	Text m_text; // text play exit
	sf::CircleShape m_Btn; // exit btn for databar
	Font m_font;
};

