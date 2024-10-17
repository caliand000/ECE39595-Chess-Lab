#include "PawnPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

using Student::PawnPiece;
using Student::ChessBoard;
using Student::ChessPiece;


PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column) : 
    ChessPiece(board, color, row, column) {
    type = Pawn;
}

// override the pure virtual function from ChessPiece abstract class
bool PawnPiece::canMoveToLocation(int newrow, int newcolumn) {
    // Check if the move is within bounds
    if (newrow < 0 || newrow >= board.getNumRows() || newcolumn < 0 || newcolumn >= board.getNumCols())
        return false;
    // did not change positions
    if (row == newrow && column == newcolumn)
        return false;
    // the most a pawn can move at a time is one square up, except for when it is on the starting board
    // a pawn can move diagonally

    /*
        1. Check where you are first
        2. Check if theres a guy in front of you

        scenarios
        1. pawn is starting
        2. pawn has a guy in front of him
        3. pawn has a guy to the side of him
        4. pawn can move 1
        
    */
    // 1 means moved down/right
    // 0 means no change
    // -1 means moved up/left
    int rowDir = (newrow - row == 0)? 0: (newrow - row > 0)? 1 : -1;
    //int colDir = (newcolumn - column == 0)? 0: (newcolumn - column > 0)? 1: -1;

    // if a pawn ever goes more than one square horizontally, its ILLEGAL!
    if (absValue(newcolumn - column) > 1)
        return false;
    // if a pawn ever goes more than 2 squares vertically or moves only horizontally its wrong
    if (absValue(newrow - row) > 2 || (rowDir) == 0) 
        return false;

    // white only moves up (---)
    if (color == White && rowDir == 1)
        return false;   // if WHITE pawn moves DOWN (+++) its wrong
    // black only moves down (+++)
    if (color == Black && rowDir == -1)
        return false;   // if BLACK pawn moves UP (---) its wrong

    // if moved diagonal
    if (absValue(newrow - row) == absValue(newcolumn - column)) {
        if (board.getPiece(newrow, newcolumn) == nullptr)   // could not find a piece, pawn cannot move diagonally
            return false;
        if (color == board.getPiece(newrow, newcolumn)->getColor()) // found a piece, but it is same color
            return false;    
        return true;
    }
    // if moved 1 row
    if (board.getPiece(row + 1 *rowDir, column) != nullptr) // check if there is a piece in 1 square in front of the pawn
        return false;
    // moving 2 rows
    else {
        if (absValue(newrow - row) == 1)    // if only needed to move 1 row
            return true;
        // moving 2 rows
        if (column - newcolumn != 0)    // if horizontal movement accompanies the 2 square vertical movement
            return false;
        // piece is at pawn starting location
        if (row == 1 || row == board.getNumRows() - 2) {
            if (board.getPiece(row + 2 * rowDir, column) != nullptr) // if there is a piece 2 squares in front
                return false;
            return true;    // if there is no piece 2 squares in front, it is a valid move.
        }
        else    // this is for when none of the conditions have been met that allow a pawn to move 2 rows
            return false;
    }


    // Check if the move is a valid based on color, and column direction
    
    /*
    if(newcolumn == column){
        if (color == White) {
            if (newrow == row - 1) {
                if(board.getPiece(newrow, newcolumn) != nullptr) {
                    return false;
                }
            } 
            else if(newrow == row - 2){
                if(board.getNumRows() - 2 == row){
                    if((board.getPiece(newrow, newcolumn) != nullptr) && (board.getPiece(newrow + 1, newcolumn) != nullptr)) {
                        return false;
                    }
                }
                else{
                    return false;
                }
            } 
            else {
                return false;
            }
        } 
        else if(color == Black) {
            if (newrow == row + 1) {
                //check if location already occupied
                if(board.getPiece(newrow, newcolumn) != nullptr) {
                    return false;
                }
            } 
            else if(newrow == row + 2){
                if(row != 1){
                    return false;
                }
                //check if location already occupied, looking at 2 spaces now
                if((board.getPiece(newrow, newcolumn) != nullptr) && (board.getPiece(newrow - 1, newcolumn) != nullptr)) {
                    return false;
                }
            } 
            else {
                return false;
            }
        } 
    }

    else if((newcolumn == column - 1) || (newcolumn == column + 1)) {

        if(color == White){
            if(newrow == row - 1){
                if(board.getPiece(newrow, newcolumn) != nullptr){
                    if(board.getPiece(newrow, newcolumn)->getColor() == White){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else if(color == Black){
            if(newrow == row + 1){
                if(board.getPiece(newrow, newcolumn) != nullptr){
                    if(board.getPiece(newrow, newcolumn)->getColor() == Black){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    else {
        return false;
    }
    */
}

// override the pure virtual function from ChessPiece abstract class
const char* PawnPiece::toString() 
{
    if(color == White)
    {
        return "\u2659";
    }
    else
    {
        return "\u265F";
    }
}
