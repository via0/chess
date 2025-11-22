#include <iostream>
#include "game.h"

int main() {
    Game game;
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
    struct Cartesian startCart;
    struct Cartesian endCart;
    while(!isGameOver){
        game.board.Render();

        // Check if any moves are available HERE

        do{
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

            startCart = game.board.algebraicToCartesian(startingTile);
            endCart = game.board.algebraicToCartesian(endingTile);
        } while(!game.isMoveLegal(startCart, endCart));

        // if move is legal...
        game.board.executeMove(startingTile, endingTile);
    }
    return 0;
}
