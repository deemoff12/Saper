//
// Created by dawid on 19.03.2019.
//

#include <iostream>
#include "minesboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
using namespace std;
MSTextController:: MSTextController(MinesweeperBoard &b, MSBoardTextView &v) :board(b), view(v){

}
void MSTextController::play() {
        cout << "INSTRUKCJA : " << endl;
        cout<< "Gracz wykonuje ruchy w nastepujacej kolejnosci" << endl;
        cout << "- Wpisuje wspolrzedne pola(Najpierw Pozioma, nastepnie Pionowa) ktorego dotyczy akcja."<< endl;
        cout << "- Wybiera akcje (Odkrycie pola LUB Postawienie Flagi)" << endl;
        cout << "O - Odkrycie pola"<<endl << "F - Postawienie Flagi";
        cout<< "- Gracz moze wykonywac ruchy dopoki gra nie zostala zakonczona." << endl;
        char action;
        int x,y;
        view.display();
        do
        {
            cout << "Wspolrzedna X : ";
            cin >> x;
            cout << endl << "Wspolrzedna Y : ";
            cin >> y;
            cout << endl << "Wybierz akcje(O - odkrycie pola || F - postawienie flagi : ";
            cin >> action;
            switch(action)
            {
                case 'o':
                    board.revealField(x,y);
                    view.display();
                    break;
                case 'f':
                    board.toggleFlag(x, y);
                    view.display();
                    break;
                default:
                    cout << endl << "NIEPRAWIDLOWA FUNKCJA URWIPOLKU !!!!";
                    break;
            }

        }while (board.getGameState() == RUNNING);
        if (board.getGameState() == FINISHED_WIN)
            cout << endl <<"GRATULUJE WYGRANEJ";
        if (board.getGameState() == FINISHED_LOSS)
            cout<< endl << "NIESTETY TYM RAZEM SIE NIE UDALO";
}
