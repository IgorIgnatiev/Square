#pragma once
#include<SFML/Graphics.hpp>
#include<thread>
using namespace sf;
class C_Square :
	public sf::RectangleShape
{
public:
	C_Square(float x, float pos_x, float pos_y, float window_x, float window_y) : RectangleShape(sf::Vector2f(x, x))
	{
		this->setPosition(pos_x, pos_y);
		this->obj = new RectangleShape(Vector2f(window_x, window_y));
		this->is_work = true;
	}
	void set_is_work(bool* is)
	{
		this->is_work = is;
	}
	virtual void move() = 0;
protected:
	RectangleShape* obj;
	bool is_work;
};