//
// Created by dawid on 19.03.2019.
//

#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H

#include "minesboard.h"
#include "MSBoardTextView.h"


class MSTextController {
    MinesweeperBoard& board;
    MSBoardTextView& view;

public:
    MSTextController(MinesweeperBoard& b, MSBoardTextView& v);
    void play();
};

#endif //SAPER_MSTEXTCONTROLLER_H
