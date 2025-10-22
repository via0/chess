#include "game.h"
#include <iostream>

Board::Board(void){
    length = 8;
    width = 8;
}

void Board::Render(void){
    for(int row = 0; row < length; row++){
        for(int col = 0; col < width; col++){
            std::cout << ".";
        }
        std::cout << std::endl;
    }
}
