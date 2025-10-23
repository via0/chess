#ifndef GAME_H_
#define GAME_H_

#include <cstddef>

#define WSQUARE "\u25A1"
#define BSQUARE "\u25A0"

class Board
{
  public:
    int length;
    int width;
    Board(void);
    void Render(void);
};
#endif // GAME_H_
