#include "game.h"
#include <iostream>

Piece::Piece(void){
    color = White;  // arbitrary we'll see if these is a problem lol
    type = None;
}

Piece::Piece(Color inColor, PieceType inType){
    color = inColor;
    type = inType;
}

void Piece::Render(void){
   switch(type){
       case King:
           std::cout << ((color == Black) ? BKING : WKING);
           break;
//         case Queen:
//            break;
//         case Rook:
//            break;
//         case Bishop:
//            break;
//         case Knight:
//            break;
//         case Pawn:
//            break;
        default:
           std::cout << " ";
           break;
   }
}

Board::Board(void){
    length = 8;
    width = 8;

    for(int row = 0; row < length; row++){
        for(int col = 0; col < width; col++){
            tiles[row][col] = Tile(((row + col) % 2) ? Black : White);
        }
    }
}

void Board::Render(void){

//    for(int row = length; row > 0; row--){
//        std::cout << (char)('0' + row);
//        for(int col = 0; col < width; col++){
//            tiles[row-1][col].Render();
//        }
//        std::cout << std::endl;
//    }
//
//    std::cout << " ABCDEFGH" << std::endl;

    // Goofy ahh methodology: just print massive board
    for(int row = 0; row < 8; row++){
        RenderRow(row);
    }
}

void Board::RenderRow(int row){

    Color currentColor = tiles[row][0].color;

    for(int tile_y = 0; tile_y < 3; tile_y++){
        for(int col = 0; col < 8; col++){
            // Switch color tiles here because this is where we actually switch squares
            currentColor = (currentColor == White) ? Black : White;
            for(int tile_x = 0; tile_x < 3; tile_x++){
                if((tile_x == 1) && (tile_y) == 1)
                    tiles[row][col].piece.Render();
                else
                    std::cout << ((tiles[row][col].color == Black) ? BSQUARE : WSQUARE);
            }
        }
        std::cout << std::endl;
    }

}

Tile::Tile(void){
    color = White;
}

Tile::Tile(Color inColor){
    color = inColor;
}

void Tile::Render(void){
    
    std::cout << ((color == Black) ? BSQUARE : WSQUARE);
}
