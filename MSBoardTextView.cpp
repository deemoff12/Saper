//
// Created by dawid on 19.03.2019.
//

#include "MSBoardTextView.h"
#include <iostream>

MSBoardTextView:: MSBoardTextView(MinesweeperBoard &b) :board (b){

}

void MSBoardTextView::display() const {

    for (int i = 0; i < board.getBoardHeight() ; ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            std::cout << "[ " << board.getFieldInfo(i,j) << " ]" ;
        }
        std::cout << std:: endl;
    }
}

