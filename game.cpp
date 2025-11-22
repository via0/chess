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
         case Queen:
            std::cout << ((color == Black) ? BQUEEN : WQUEEN);
            break;
         case Rook:
            std::cout << ((color == Black) ? BROOK : WROOK);
            break;
         case Bishop:
            std::cout << ((color == Black) ? BBISHOP : WBISHOP);
            break;
         case Knight:
            std::cout << ((color == Black) ? BKNIGHT : WKNIGHT);
            break;
         case Pawn:
            std::cout << ((color == Black) ? BPAWN : WPAWN);
            break;
        default:
           std::cout << " ";
           break;
   }
}

Board::Board(void){
    int length = 8;
    int width = 8;

    for(int row = 2; row < (length - 2); row++){
        for(int col = 0; col < width; col++){
            tiles[row][col] = Tile(((row + col) % 2) ? Black : White);
        }
    }

    tiles[0][0] = Tile(White, Piece(Black, Rook));
    tiles[0][1] = Tile(Black, Piece(Black, Knight));
    tiles[0][2] = Tile(White, Piece(Black, Bishop));
    tiles[0][3] = Tile(Black, Piece(Black, Queen));
    tiles[0][4] = Tile(White, Piece(Black, King));
    tiles[0][5] = Tile(Black, Piece(Black, Bishop));
    tiles[0][6] = Tile(White, Piece(Black, Knight));
    tiles[0][7] = Tile(Black, Piece(Black, Rook));
    for(int col = 0; col < width; col += 2){
        tiles[1][col]   = Tile(Black, Piece(Black, Pawn));
        tiles[1][col+1] = Tile(White, Piece(Black, Pawn));
    }

    tiles[7][0] = Tile(Black, Piece(White, Rook));
    tiles[7][1] = Tile(White, Piece(White, Knight));
    tiles[7][2] = Tile(Black, Piece(White, Bishop));
    tiles[7][3] = Tile(White, Piece(White, Queen));
    tiles[7][4] = Tile(Black, Piece(White, King));
    tiles[7][5] = Tile(White, Piece(White, Bishop));
    tiles[7][6] = Tile(Black, Piece(White, Knight));
    tiles[7][7] = Tile(White, Piece(White, Rook));
    for(int col = 0; col < width; col += 2){
        tiles[6][col]   = Tile(White, Piece(White, Pawn));
        tiles[6][col+1] = Tile(Black, Piece(White, Pawn));
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
                if((tile_x == 1) && (tile_y == 1) && (tiles[row][col].piece.type != None))
                    tiles[row][col].piece.Render();
                else
                    std::cout << ((tiles[row][col].color == Black) ? BSQUARE : WSQUARE);
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

}

bool Board::isTileValid(std::string inTile){
    // Tiles are in the form "a1", "h8", etc.
    if(inTile.length() > 2){
        return false;
    }
    
    // File must be between a and h inclusive
    if(inTile[0] < 'a' && inTile[0] > 'h'){
        return false;
    }

    // Rank must be between 1 and 8 inclusive
    if(inTile[1] < '1' || inTile[1] > '8'){
        return false;
    }

    return true;
}


// assume all inputs have been validated by this point - we are simply replacing the piece
// in endingLocation with the piece in startingLocation
void Board::executeMove(std::string startingTile, std::string endingTile){
    // Convert algebraic coordinates to pointer to actual Tile object
    struct Cartesian startCart = algebraicToCartesian(startingTile);
    struct Cartesian endCart = algebraicToCartesian(endingTile);

    tiles[endCart.row][endCart.col].piece = tiles[startCart.row][startCart.col].piece;
    tiles[startCart.row][startCart.col].piece = Piece(White, None);
}

// Convert algebraic notation (a1, h8, etc.) to Cartesian row, col (0 indexed with origin at top left)
// We are assuming inputs are valid LUL
struct Cartesian Board::algebraicToCartesian(std::string algebraicTile){
    struct Cartesian cart;
    cart.row = ((algebraicTile[1] - '0') * -1) + 8;
    cart.col = (algebraicTile[0] - 'a');

    return cart;
}

// Based on the piece located at the square indicated by startCart, return a vector
// of all the squares that piece can legally travel to right now
std::vector<struct Cartesian> Board::getAccessibleTiles(struct Cartesian startCart){

    std::vector<struct Cartesian> accessibleTiles;
    Piece activePiece = tiles[startCart.row][startCart.col].piece;

    int nextRow; // only relevant for pawns?
    // Start with an EVIL switch case statement then refactor later (lul)
    // this whole thing is going to be very messy until we refactor
    switch(activePiece.type){
        case King:
        case Queen:
        case Rook:
        case Bishop:
        case Knight:
        case Pawn:
            // TODO: en passant - need to retain move history for this
            
            // Able to move forward one square, if it's empty
            nextRow = (activePiece.color == Black) ? (startCart.row + 1) : (startCart.row - 1);
            if((nextRow >= 0 && nextRow <= 7) && tiles[nextRow][startCart.col].piece.type == None){
                accessibleTiles.push_back({nextRow, startCart.col});
            }

            // Also able to move forward two squares, if currently in home row (2 for white, 7 for black)
            // Able to capture diagonally, if diagonal spot holds 
        default:
            break;
    }

    return accessibleTiles;
}

Tile::Tile(void){
    color = White;
}

Tile::Tile(Color inColor){
    color = inColor;
    piece = Piece(White, None);
}

Tile::Tile(Color inColor, Piece inPiece){
    color = inColor;
    piece = inPiece;
}

void Tile::Render(void){
    
    std::cout << ((color == Black) ? BSQUARE : WSQUARE);
}

Game::Game(void){
    board = Board();
    whoseTurn = White;
}

bool Game::isMoveLegal(struct Cartesian startCart, struct Cartesian endCart){
    // Does the square indicated by startCart contain a piece belonging to the current player?
    if((board.tiles[startCart.row][startCart.col].piece.type == None) || (board.tiles[startCart.row][startCart.col].piece.color != whoseTurn)){
        return false;
    }
    // Is the square indicated by endCart either a) empty or b) contains a piece belonging to opposing player?
    if((board.tiles[startCart.row][startCart.col].piece.type != None) && (board.tiles[startCart.row][startCart.col].piece.color == whoseTurn)){
        return false;
    }
    // Is the endCart within range of startCart, given the piece contained on startCart?
    // Checking two separate questions here:
    // 1) Is endCart hypothetically within range of startCart for the movement afforded by startCart.piece?
    // 2) Is there nothing blocking the path? (Ignored for knights, of course)
    // Which means this can't be a function called by the piece itself
    // the piece tells you which tiles to scan (e.g. pawns look forward one square, or two if they're on their home rank,
    // or diagonal forward one if capturing)
    if(!canTileReachTile(startCart, endCart)){
        return false;
    }

    // Would executing this move place the current player's king in check?
    // Save the piece on endCart for later
    // Execute the move
    // Test whether current player's king is in check
    // If current player's king is in check, reverse the move (using that piece we just saved)
    
    return true;
}

bool Game::canTileReachTile(struct Cartesian startCart, struct Cartesian endCart){
    // Get the piece located at startCart
    Piece startPiece = board.tiles[startCart.row][startCart.col].piece;
    // Start searching through all the tiles it can access
    // Just create a vector of all the Cartesians bro
    std::vector<struct Cartesian> accessibleTiles = board.getAccessibleTiles(startCart);


    // If endCart ever matches one of the searched tiles, return true
    // Otherwise, return false
    // Alternative approach that might be fun: during beginning of turn, for each piece,
    // create hash set of pieces it can access. That would make memory go crazy but fast search tho

    return false;
}
