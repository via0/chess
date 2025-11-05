#ifndef GAME_H_
#define GAME_H_

#include <cstddef>
#include <string>

#define WSQUARE "\u25A1"
#define BSQUARE "\u25A0"

#define WKING   "\u2654"
#define WQUEEN  "\u2655"
#define WROOK   "\u2656"
#define WBISHOP "\u2657"
#define WKNIGHT "\u2658"
#define WPAWN   "\u2659"

#define BKING   "\u265A"
#define BQUEEN  "\u265B"
#define BROOK   "\u265C"
#define BBISHOP "\u265D"
#define BKNIGHT "\u265E"
#define BPAWN   "\u265F"

typedef enum {White, Black} Color;

typedef enum
{
    King = 0,
    Queen = 1,
    Rook = 2,
    Bishop = 3,
    Knight = 4,
    Pawn = 5,
    None = 6
} PieceType;

// Piece class attributes...
// needs a color, maybe list of moves?
// also make sure to do that funny trick where you have to define the function in the child class
class Piece
{
  public:
    Piece(void);
    Piece(Color inColor, PieceType inType);
    void Render(void);
    Color color;
    PieceType type;
};

// class Pawn : public Piece
// {
//   public:
// 
// };

class Tile
{
  public:
    Color color;
    Tile(void);
    Tile(Color inColor);
    Tile(Color inColor, Piece inPiece);
    void Render(void);
    Piece piece;
};

class Board
{
  public:
    Board(void);
    void Render(void);
    void RenderRow(int row);
    Tile tiles[8][8];
    bool isTileValid(std::string inTile);
};

class Game
{
    public:
        Game(void);
        Board board;
};

#endif // GAME_H_
