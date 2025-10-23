#include "game.h"
#include <iostream>

Board::Board(void){
    length = 8;
    width = 8;
}

void Board::Render(void){

    for(int row = length; row > 0; row--){
	std::cout << (char)('0' + row);
        for(int col = 0; col < width; col++){
            std::cout << (((row + col) % 2) ? BSQUARE : WSQUARE);
        }
        std::cout << std::endl;
    }

    std::cout << " ABCDEFGH" << std::endl;
}
