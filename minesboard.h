
#ifndef MINESBOARD_H__
#define MINESBOARD_H__

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

// HINT
struct Field
{
    bool hasMine;
    bool hasFlag;
    bool hasRevealed;
};
class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;

public:
    MinesweeperBoard(int width, int height, GameMode mode );
    void debug_display() const ;


    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;

    int countMines(int x, int y) const;

    bool hasFlag(int x, int y) const;

    void toggleFlag(int x, int y);

    void revealField(int x, int y);

    bool czyPierwszy() const ;

    bool isRevealed(int x, int y) const;

    GameState getGameState() const;

    char getFieldInfo(int x, int y) const;
};

#endif //SAPER_MINESBOARD_H
