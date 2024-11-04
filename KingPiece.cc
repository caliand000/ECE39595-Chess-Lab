#include "KingPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

using Student::KingPiece;
using Student::ChessBoard;
using Student::ChessPiece;

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column) : 
    ChessPiece(board, color, row, column) {
    type = King;
}

// override the pure virtual function from ChessPiece abstract class
bool KingPiece::canMoveToLocation(int newrow, int newcolumn) {
    // Check if the move is within bounds
    if (newrow < 0 || newrow >= board.getNumRows() || newcolumn < 0 || newcolumn >= board.getNumCols())
        return false;
    // did not change positions
    if (row == newrow && column == newcolumn)
        return false;
    // the king can move one square in any direction
    int rowDiff = abs(newrow - row);
    int colDiff = abs(newcolumn - column);
    if (rowDiff <= 1 && colDiff <= 1)
        return true;
    return false;
}

const char* KingPiece::toString() {
    if(color == White)
    {
        return "\u2654";
    }
    else
    {
        return "\u265A";
    }
}