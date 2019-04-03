//
// Created by dawid on 19.03.2019.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

#include "minesboard.h"

class MSBoardTextView{
    MinesweeperBoard &board;
public:
    MSBoardTextView(MinesweeperBoard &b);
    void display() const;
};

#endif //SAPER_MSBOARDTEXTVIEW_H
