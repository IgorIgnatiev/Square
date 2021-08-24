#pragma once
#include"C_Square.h"
class C_Square_Blue :
	public C_Square
{
private:
	std::thread* m_th;
	bool _side;
public:
	C_Square_Blue(float x, float pos_x, float pos_y, float window_x, float window_y) : C_Square(x, pos_x, pos_y, window_x, window_y)
	{
		this->setFillColor(sf::Color::Blue);
		this->_side = true;

		this->m_th = new std::thread(&C_Square_Blue::move, *this);
		this->m_th->detach();
	}
	virtual ~C_Square_Blue()
	{
		delete this->obj;
		this->is_work = false;
		std::this_thread::sleep_for(std::chrono::microseconds(100));
		delete this->m_th;
	}
	void virtual move()
	{
		while (this->is_work)
		{
			if (this->_side == true)
			{
				this->setPosition(this->getPosition().x, this->getPosition().y + 20);
			}
			else
			{
				this->setPosition(this->getPosition().x, this->getPosition().y - 20);
			}
			if (this->getPosition().y + this->getSize().y < this->obj->getSize().y)
			{
				this->_side = true;
			}
			else
			{
				this->_side = false;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(700));
		}
	}
};