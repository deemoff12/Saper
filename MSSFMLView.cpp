//
// Created by dawid on 02.04.2019.
//

#include <cmath>
#include "MSSFMLView.h"

MSSFMLView:: MSSFMLView(MinesweeperBoard & b, float squaresize, sf::Vector2f LG) :board(b)
{
    col = b.getBoardHeight();
    row = b.getBoardWidth();
}
void MSSFMLView:: draw(sf::RenderWindow &win)
{
    sf::CircleShape square(20.f , 4);

        square.setFillColor(sf::Color::Black);
        square.setOutlineThickness(-1);
        square.setOutlineColor(sf::Color::White);
        win.clear(sf::Color::Magenta);
        square.rotate(45);
        for (int i = 0; i < col ; ++i) {
            for (int j = 0; j < row ; ++j) {
                if(board.isRevealed(i,j))
                    square.setFillColor(sf::Color::Green);
                if(board.hasFlag(i, j))
                    square.setFillColor(sf::Color::Red);
                square.setPosition(LG.x + i*(squaresize*2)/pow(2, 0.5), LG.y + j*(squaresize*2)/pow(2, 0.5));
                win.draw(square);
            }

        }

}