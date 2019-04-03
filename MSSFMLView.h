//
// Created by dawid on 02.04.2019.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "minesboard.h"

class MSSFMLView {

    MinesweeperBoard & board;
    int col,row;
    sf::Vector2f LG;
    int squaresize;
public:
    MSSFMLView(MinesweeperBoard& b, float squares, sf::Vector2f start);
    void draw(sf::RenderWindow &win);

};


#endif //SAPER_MSSFMLVIEW_H


