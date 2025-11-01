#include <iostream>
#include "game.h"

int main() {
    Board board;
    board.Render();

    // Next step from here: come up with game loop...
    // Prompt user for input for next move
    //   select tile to start at
    //   select tile to end at
    //   see if that's legal
    //   make move accordingly
    // switch to other user
    // continue until current player has no more legal moves
    //   if their king is in check, other player wins
    //   if their king is not in check, it's a tie
    return 0;
}
