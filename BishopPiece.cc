// LINE 33 CHECK
#include "BishopPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

using Student::BishopPiece;
using Student::ChessBoard;
using Student::ChessPiece;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : 
    ChessPiece(board, color, row, column) {
    type = Bishop;
}

// override the pure virtual function from ChessPiece abstract class
bool BishopPiece::canMoveToLocation(int newRow, int newCol) {
    // check if piece is on board
    if ((newRow < 0 || newRow >= board.getNumRows()) || (newCol < 0 || newCol >= board.getNumCols()))
        return false;
    if (newRow == row || newCol == column)  // checks for if the bishop didnt move at all or if it tried to move horizontally
        return false;
    // check if move is valid for a bishop
    /*
        for a piece to move diagonally, it must move the same amount horizontally
        as it does vertically.

        Therefore, if we find the vertical and horizontal distance from the original
        position to the new position, we can compare the absolute values of the 2
        distances, and if they are the same, it should be a diagonal move, making it
        valid.
    */

    // 1 mean down/right
    // -1 means up/left


    //check for pieces in the way, going each direction, NE, NW, SE, SW
    if(newRow < row && newCol > column){                                //NE
        for(int i = 1; row - i < newRow && column + i < newCol; i++){
            if(board.getPiece(row - i, column + i) != nullptr)
                return false;
        }
    }
    else if(newRow < row && newCol < column){                           //NW
        for(int i = 1; row - i > newRow && column - i < newCol; i++){
            if(board.getPiece(row - i, column - i) != nullptr)
                return false;
        }
    }
    else if(newRow > row && newCol > column){                           //SE
        for(int i = 1; row + i < newRow && column + i > newCol; i++){
            if(board.getPiece(row + i, column + i) != nullptr)
                return false;
        }
    }
    else if(newRow > row && newCol < column){                           //SW
        for(int i = 1; row + i > newRow && column - i > newCol; i++){
            if(board.getPiece(row + i, column - i) != nullptr)
                return false;
        }
    }
    return true;


    // int rowDir = (newRow - row) > 0 ? 1: -1;
    // int colDir = (newCol - column) > 0 ? 1: -1;

    // // Again, not sure if need to check if there is a piece in between

    // // checks if the absolute value of rowCheck and colCheck are equal
    // if (absValue(newRow - row) == absValue(newCol - column)) {   
    //     for (int i = 1; i < absValue(newRow - row); i++)    // checks every square until the destination square, if piece at dest square, take it
    //     {
    //         // rowDir and colDir will be 1 or -1. This will multiply into the i value, adding/subtracting (moving left/right, up/down)
    //         // checking for pieces along any diagonal
    //         if (board.getPiece(row + i *rowDir, column + i *colDir) != nullptr)
    //             return false;
    //     }
    //     return true;
    // }
    // return false;

}

const char* BishopPiece::toString()
{
    if (color == White)
        return "\u2657";
    return "\u265D";
}