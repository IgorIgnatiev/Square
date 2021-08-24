#pragma once
#include"C_Square.h"
class C_Square_Yellow :
	public C_Square
{
private:
	std::thread* m_th;
public:
	C_Square_Yellow(float x, float pos_x, float pos_y, float window_x, float window_y) : C_Square(x, pos_x, pos_y, window_x, window_y)
	{
		this->setFillColor(sf::Color::Yellow);

		this->m_th = new std::thread(&C_Square_Yellow::move, *this);
		this->m_th->detach();
	}
	virtual void move() override
	{
		while (this->is_work)
		{
			short* random = new short(rand() % 5);
			if (*random == 1)
			{
				this->setPosition(this->getPosition().x + 25, this->getPosition().y);
			}
			else if (*random == 2)
			{
				this->setPosition(this->getPosition().x - 25, this->getPosition().y);
			}
			else if (*random == 3)
			{
				this->setPosition(this->getPosition().x, this->getPosition().y + 25);
			}
			else
			{
				this->setPosition(this->getPosition().x, this->getPosition().y - 25);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(700));
		}
	}
};