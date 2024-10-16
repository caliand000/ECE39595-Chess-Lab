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

    // Check if the move is a valid pawn move
    if (color == White) {
        if (newrow == row - 1 && newcolumn == column) {
            return true;
        }
    } else {
        if (newrow == row + 1 && newcolumn == column) {
            return true;
        }
    }

    return false;
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
