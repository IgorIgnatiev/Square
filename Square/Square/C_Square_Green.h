#pragma once
#include"C_Square.h"
class C_Square_Green :
	public C_Square
{
private:
	std::thread* m_th;
	bool _side;
public:
	C_Square_Green(float x, float pos_x, float pos_y, float window_x, float window_y) : C_Square(x, pos_x, pos_y, window_x, window_y)
	{
		this->setFillColor(sf::Color::Green);
		this->_side = true;

		this->m_th = new std::thread(&C_Square_Green::move, *this);
		this->m_th->detach();
	}
	std::thread* get_thread()
	{
		return this->m_th;
	}
	virtual void move() override
	{
		while (this->is_work)
		{
			if (this->_side == true)
			{
				this->setPosition(this->getPosition().x + 50, this->getPosition().y);
			}
			else
			{
				this->setPosition(this->getPosition().x - 50, this->getPosition().y);
			}
			if (this->getPosition().x + this->getSize().x < this->obj->getSize().x)
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
