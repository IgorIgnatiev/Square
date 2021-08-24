
#include <iostream>
#include"C_Square_Blue.h"
#include"C_Square_Green.h"
#include"C_Square_Yellow.h"
#include <iostream>
#include <mutex>
#include <ctime>
#include <chrono>

void move(C_Square& obj)
{
    obj.move();
}

int main()
{
    RenderWindow window(VideoMode(1000, 500), "Circles");
    C_Square_Blue* blue = new C_Square_Blue(100, 450, 0, 1000, 500);


    C_Square_Green green(100, 0, 200, 1000, 500);

    C_Square_Yellow yellow(100, 450, 200, 1000, 500);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(green);
        window.draw(*blue);
        window.draw(yellow);
        window.display();
    }
}

