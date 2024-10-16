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

    // check if move is valid for a bishop
    /*
        for a piece to move diagonally, it must move the same amount horizontally
        as it does vertically.

        Therefore, if we find the vertical and horizontal distance from the original
        position to the new position, we can compare the absolute values of the 2
        distances, and if they are the same, it should be a diagonal move, making it
        valid.
    */
    int rowCheck = newRow - row;
    int colCheck = newCol - column;
    
    // Again, not sure if need to check if there is a piece in between
    if (rowCheck == colCheck || (-1*rowCheck) == colCheck)    // checks if the absolute value of rowCheck and colCheck are equal
        return true;
    return false;

}

const char* BishopPiece::toString()
{
    if (color == White)
        return "\u2657";
    return "\u265D";
}