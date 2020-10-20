#include "MenuBtn.h"

sf::Sprite sprite;


MenuBtn::MenuBtn()
{
}

//c-tor of rectangle  button for main menu
MenuBtn::MenuBtn(const Texture& texture, const Vector2f& position, unsigned btnSize, string text)
{
	m_button.setTexture(texture);	 //texture btn for main menu with sprite
	m_button.setPosition(position);				
	m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);	// set origin to the middle
	
	//set text of button
	m_text.setString(text);
	
	m_font.loadFromFile("pixel.ttf");
	m_text.setFont(m_font);	//font					
	m_text.setCharacterSize(btnSize - MARGE);//size of letters
	//position in game
	m_text.setPosition(m_button.getPosition().x, m_button.getPosition().y+ 32);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().width / 2);	
}

//c-tor for round button for menu of databar
MenuBtn::MenuBtn(const Texture& resource, const Vector2f& position, unsigned btnSize)
{
	m_Btn.setTexture(&resource); //texture
	m_Btn.setRadius(btnSize); //raduis 
	//position in game
	m_Btn.setPosition(position);
	m_Btn.setOrigin(m_Btn.getGlobalBounds().width / 2, m_Btn.getGlobalBounds().height / 2);
}

MenuBtn::~MenuBtn()
{
}

void MenuBtn::draw(RenderWindow& window)
{
	window.draw(m_button); //for main menu
	window.draw(m_Btn); //for databar
	window.draw(m_text); //for main menu

}
bool MenuBtn::contains(const Vector2f& pos) const
{
	//if mouse in play or exit
	return (m_button.getGlobalBounds().contains(pos) ||
		m_Btn.getGlobalBounds().contains(pos));
}

void MenuBtn::highlight()
{

	m_button.setColor(sf::Color::Red);
}

void MenuBtn::unhighlight()
{
	m_button.setColor(sf::Color::Green);
}


Vector2f MenuBtn::getPosition() const
{
	
		return m_button.getPosition();
	
}
