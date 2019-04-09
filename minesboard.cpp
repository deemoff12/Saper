//
// Created by dawid on 12.03.2019.
//
#include <iostream>
#include <cmath>
#include "minesboard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {
    {
        this -> MinesweeperBoard::width = width;
        this -> MinesweeperBoard::height = height;
        for (int i = 0; i < height ; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                board[i][j]={false, false, false};
            }
        }
        int mines_number;
        int x, y;
        switch (mode)
        {
            case EASY:
                mines_number = ceil(width*height*0.1);

                for (int i = 0; i < mines_number ; ++i) {
                    x = rand()% width;
                    y = rand()% height;
                    if (board[y][x].hasMine)
                    {
                        i--;
                        continue;
                    }
                    board[y][x].hasMine = true;
                }
                break;
            case NORMAL:
                mines_number = ceil(width*height*0.2);
                for (int i = 0; i < mines_number ; ++i) {
                    x = rand()% height;
                    y = rand()% width;
                    if (board[y][x].hasMine)
                    {
                        i--;
                        continue;
                    }
                    board[y][x].hasMine = true;
                }
                break;
            case HARD:
                mines_number = ceil(width*height*0.3);
                for (int i = 0; i < mines_number ; ++i) {
                    x = rand()% height;
                    y = rand()% width;
                    if (board[y][x].hasMine)
                    {
                        i--;
                        continue;
                    }
                    board[y][x].hasMine = true;
                }
                break;
            case DEBUG:
                for (int i = 0; i < getBoardWidth()  ; ++i) {
                    for (int j = 0; j < getBoardHeight(); ++j) {
                        if (i == 0)
                            board[j][i].hasMine = true;
                        if (j==i)
                            board[j][i].hasMine = true;
                        if (j == 0 && i%2==0 )
                            board[j][i].hasMine = true;
                    }
                }
                break;
        }


    };
}

void MinesweeperBoard::debug_display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << "[";
            if (!board[i][j].hasMine)
                std::cout << ".";
            else std::cout << "M";
            if (!board[i][j].hasRevealed)
                std::cout << ".";
            else std::cout << "O";
            if (!board[i][j].hasFlag)
                std::cout << ".";
            else std::cout << "F";
            std::cout << "] ";
        }
        std::cout << std::endl;
    }
}
GameState MinesweeperBoard::getGameState() const{
    for (int i = 0; i < height ; ++i) {
        for (int j = 0; j < width ; ++j) {
            if(getFieldInfo(i,j)=='x')
                return FINISHED_LOSS;
        }

    }

    int temp = 0;
    for (int k = 0; k < height; ++k) {
        for (int i = 0; i < width; ++i) {
            if((board[k][i].hasMine && !board[k][i].hasRevealed) && (board[k][i].hasMine && board[k][i].hasFlag) )
            {
                temp ++;
            }
        }
    }
    if(temp == getMineCount()) return FINISHED_WIN;

    return RUNNING;


}
 bool MinesweeperBoard::isRevealed(int x, int y) const{
        if(board[y][x].hasRevealed)
            return true;
        else
            return false;
}

int MinesweeperBoard::getBoardWidth() const {
    return width;
}

int  MinesweeperBoard::getBoardHeight() const {
    return height;
}
int MinesweeperBoard::getMineCount() const {
    int mines_count = 0;
    for (int i = 0 ; i < getBoardHeight(); ++i) {
        for (int j = 0; j < getBoardWidth(); ++j) {
            if (board[j][i].hasMine)
                mines_count++;
        }
    }
    return mines_count;
}
int MinesweeperBoard::countMines(int y, int x) const {
    if(!isRevealed(y, x)) return -1;
    if(x < 0 || x > getBoardHeight() || y < 0 || y > getBoardWidth()) return -1;

    int counter = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            if (x + j < 0 || x + j > getBoardHeight() || y + i < 0 || y + i > getBoardWidth()) continue;
            if (board[y + i][x + j].hasMine) counter++;
        }
    }
    return counter;
};

bool MinesweeperBoard::czyPierwszy() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (isRevealed(i, j)) return false;
        }
    }
    return true;
}
void MinesweeperBoard::toggleFlag(int x, int y) {
    if(getGameState() == RUNNING)
    {
        if (!isRevealed(x, y)) {
            if (hasFlag(x, y)) board[y][x].hasFlag = false;
            else board[y][x].hasFlag = true;
        }

        if (isRevealed(y, x))
            if (x < 0 || x > height || y < 0 || y > width);
    }

}
void MinesweeperBoard::revealField(int x, int y) {
    if (isRevealed(y, x))
        return;



    if (hasFlag(y, x))
        return;

    if (!isRevealed(y, x) && !board[y][x].hasMine) board[y][x].hasRevealed = true;
    else if (!isRevealed(y, x) && board[y][x].hasMine) {
        if (czyPierwszy()) {
            int n_x = 0;
            int n_y = 0;
            do {
                n_x = rand() % height;
                n_y = rand() % width;
            }
            while (board[n_y][n_x].hasMine);
            board[y][x].hasMine = false;
            board[n_y][n_x].hasMine = true;
            board[y][x].hasRevealed = true;
        }
        else board[y][x].hasRevealed = true;

    }


}

char MinesweeperBoard::getFieldInfo(int x, int y) const {
    if (x < 0 || x > height || y < 0 || y > width) return '#';
    if (!isRevealed(y, x) && MinesweeperBoard::hasFlag(y, x))
        return 'F';
    if (!isRevealed(y, x) && !MinesweeperBoard::hasFlag(y, x))
        return '_';
    if (isRevealed(y, x) && board[y][x].hasMine)
        return 'x';
    if (isRevealed(y, x)&& MinesweeperBoard::countMines(y, x) == 0)
        return ' ';
    if (isRevealed(y, x) && MinesweeperBoard::countMines(y, x) != 0) {
        char tmp = static_cast<char>(MinesweeperBoard::countMines(y, x)) + '0';
        return tmp;
    }
}
bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if(x > 0 && x< getBoardHeight() && y > 0 && y < getBoardWidth())
    {
        if(!board[y][x].hasRevealed)
        {
            if(board[y][x].hasFlag)
                return true;
        }
    }
    else
    {
        return false;
    }
}
