//
// Created by dawid on 02.04.2019.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H



#include "minesboard.h"
#include <SFML/Graphics.hpp>

class MSSFMLView {

    MinesweeperBoard & board;

    sf::Text number;
    int squaresize;
    int square_pos_x;
    int square_pos_y;
public:
    std::vector<sf::CircleShape> rectangleShape;
    MSSFMLView(MinesweeperBoard& b, float squares, sf::Vector2f start);
    void draw(sf::RenderWindow &win);

};


#endif //SAPER_MSSFMLVIEW_H


