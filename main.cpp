#include <iostream>
#include "game.h"

int main() {
    Game game;
    game.board.Render();
    
    bool isGameOver = false;
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


    std::string startingTile;
    std::string endingTile;
    while(!isGameOver){
        do{
            std::cout << "Select a starting tile..." << std::endl;
            std::cin >> startingTile;
        } while(!game.board.isTileValid(startingTile));

        std::cout << "Selected starting tile " << startingTile << std::endl;
        
        do{
            std::cout << "Select an ending tile..." << std::endl;
            std::cin >> endingTile;
        } while(!game.board.isTileValid(endingTile));

        std::cout << "Selected ending tile " << endingTile << std::endl;
    }
    return 0;
}
