#include <iostream>
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <ctime>

#include "MSSFMLView.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    MinesweeperBoard b(9, 7, DEBUG);
    sf::Vector2f LG(50,50);
    b.revealField(2,4);
//    b.revealField(4,2);
//    b.revealField(3,4);
    b.revealField(4,3);
    b.toggleFlag(4,4);
    MSSFMLView view(b, 50, LG);
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