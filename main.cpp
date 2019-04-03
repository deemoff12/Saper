#include <iostream>
#include "minesboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <ctime>
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MSSFMLView.cpp"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    MinesweeperBoard b(9, 7, DEBUG);
    sf::Vector2f LG(50,50);
    MSSFMLView view(b, 50, LG);
    b.revealField(3,4);
    b.toggleFlag(4,4);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);

        view.draw(window);


        window.display();
    }

}