#ifndef GAME_H_
#define GAME_H_

#include <cstddef>

#define WSQUARE "\u25A1"
#define BSQUARE "\u25A0"

typedef enum {White, Black} Color;

// Piece class attributes...
// needs a color, maybe list of moves?
// also make sure to do that funny trick where you have to define the function in the child class
class Piece
{
  public:
    Piece(void);
    Piece(Color inColor);
    Color color;
};

class Pawn : public Piece
{
  public
};

class Tile
{
  public:
    Color color;
    Tile(void);
    Tile(Color inColor);
    void Render(void);

};

class Board
{
  public:
    int length;
    int width;
    Board(void);
    void Render(void);
    void RenderRow(int row);
    Tile tiles[8][8];
};

#endif // GAME_H_
