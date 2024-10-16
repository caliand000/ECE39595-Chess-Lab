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
    if (newrow < 0 || newrow >= board.getNumRows() || newcolumn < 0 || newcolumn >= board.getNumCols()) {
        return false;
    }

    // Check if the move is a valid based on color, and column direction

    if (color == White && (newcolumn == column)) {
        if (newrow == row - 1) {
            if(board.getPiece(newrow, newcolumn) != nullptr) {
                return false;
            }
        } else if(newrow == row - 2){
            if((board.getPiece(newrow, newcolumn) != nullptr) && (board.getPiece(newrow + 1, newcolumn) != nullptr)) {
                return false;
            }
        } else {
            return false;
        }
    } else if(color == Black && (newcolumn == column)) {
        if (newrow == row + 1) {
            //check if location already occupied
            if(board.getPiece(newrow, newcolumn) != nullptr) {
                return false;
            }
        } else if(newrow == row + 2){
            //check if location already occupied, looking at 2 spaces now
            if((board.getPiece(newrow, newcolumn) != nullptr) && (board.getPiece(newrow - 1, newcolumn) != nullptr)) {
                return false;
            }
        } else {
            return false;
        }

    } else if(color == White && ((newcolumn == column - 1) || (newcolumn == column + 1))) {
        if(newrow == row - 1) {
            if(board.getPiece(newrow, newcolumn) != nullptr) {
                if(board.getPiece(newrow, newcolumn)->getColor() == White) {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else if(color == Black && ((newcolumn == column - 1) || (newcolumn == column + 1))) {
        if(newrow == row + 1) {
            if(board.getPiece(newrow, newcolumn) != nullptr) {
                if(board.getPiece(newrow, newcolumn)->getColor() == Black) {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
    return true;
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
