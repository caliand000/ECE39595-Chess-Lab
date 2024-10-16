// LINE 35
#include "RookPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

using Student::RookPiece;
using Student::ChessBoard;
using Student::ChessPiece;

// Constructor
RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) :
    ChessPiece(board, color, row, column) {
    type = Rook;
}

//Overridden canMoveToLoc
bool RookPiece::canMoveToLocation(int newRow, int newCol) {
    // check if piece is on board
    if ((newRow < 0 || newRow >= board.getNumRows()) || (newCol < 0 || newCol >= board.getNumCols()))
        return false;
    
    // check if move is valid for a rook
    /*
    A rook moving horizontally means the column changes while the row remains the same\
    (row == newRow)
    
    A rook moving vertically means row changes while col does not
    (newCol == col)

    A rook not moving at all means nothing changes
    (newRow == row) && (newCol == col)

    */

    // not sure if we need to account for pieces being in the way?
    
    if (newRow == row || newCol == column) // checks for movement horizontally or vertically
        return true;
    return false;
}

//Override pvf toString from chessPiece abstract class
const char* RookPiece::toString()
{
    if (color == White)
        return "\u2656";
    else
        return "\u265C";
}