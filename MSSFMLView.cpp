//
// Created by dawid on 02.04.2019.
//

#include <cmath>
#include "MSSFMLView.h"

MSSFMLView:: MSSFMLView(MinesweeperBoard & b, float squaresize, sf::Vector2f LG) :board(b)
{
    this->squaresize = squaresize;
    this->square_pos_x = LG.x;
    this->square_pos_y = LG.y;



//    for (int k = 0; k<board.getBoardHeight(); ++k) {
//        for (int i = 0; i<board.getBoardWidth(); ++i) {
//            number[k][i].setFont(font);
//            number[k][i].setCharacterSize(16);
//            number[k][i].setFillColor(sf::Color::Black);
//            number[k][i].setPosition(sf::Vector2f(fields[k][i].getPosition().x+0.5*squaresize, fields[k][i].getPosition().y+0.5*squaresize));
//            number[k][i].setString(board.getFieldInfo(i, k));
//        }
//    }


}

void MSSFMLView::draw(sf::RenderWindow & win)
{
    sf::CircleShape square(squaresize,4);
    square.rotate(45);
    sf::Font font;
    font.loadFromFile("arial.ttf");
    number.setCharacterSize(50);
    number.setFillColor(sf::Color::Red);
    number.setFont(font);

    for (int i = 0; i<board.getBoardHeight(); ++i) {
        for (int j = 0; j<board.getBoardWidth(); ++j) {
            square.setFillColor(sf::Color::Blue);
            square.setOutlineColor(sf::Color::Black);
            square.setOutlineThickness(floor(-0.05*squaresize));
            square.setPosition(sf::Vector2f(square_pos_x+j*squaresize, square_pos_y+i*squaresize));
            if(board.isRevealed(j,i))
            {
                square.setFillColor(sf::Color::White);
            }
            if(board.hasFlag(j,i))
            {
                square.setFillColor(sf::Color::Green);
            }
            win.draw(square);
            if(board.getFieldInfo(j,i)==' ')
            {
                number.setPosition(square_pos_x+j*squaresize, square_pos_y+i*squaresize);
                number.setString("0");
                win.draw(number);
            }

            if(isdigit(board.getFieldInfo(j,i)))
            {
                switch(board.getFieldInfo(j,i))
                {
                    case '1': number.setString("1");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                    case '2': number.setString("2");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                    case '3': number.setString("3");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                    case '4': number.setString("4");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                    case '5': number.setString("5");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                    case '6': number.setString("6");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                    case '7': number.setString("7");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                    case '8': number.setString("8");
                        number.setPosition(square_pos_y+i*squaresize - 20, square_pos_x+j*squaresize + 30);
                        win.draw(number);
                        break;
                }
            }
        }
    }
}