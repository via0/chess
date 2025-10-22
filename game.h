#ifndef GAME_H_
#define GAME_H_

#include <cstddef>

class Board
{
  public:
    int length;
    int width;
    Board(void);
    void Render(void);
};
#endif // GAME_H_
