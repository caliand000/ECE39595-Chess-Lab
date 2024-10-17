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
    if ((newRow == row) && (newCol == column))
         return false;
    // if ((newRow != row) && (newCol != column))
    //     return false;


    // if(newCol == column){   //if we're moving along columns
    //     if(newRow > row){   //if we're moving down
    //         for(int i = row + 1; i < newRow; i++){          //check if there are any pieces in the way
    //             if(board.getPiece(i, column) != nullptr){
    //                 return false;
    //             }
    //         }
    //     }
    //     else{               //if we're moving up
    //         for(int i = row - 1; i > newRow; i--){          //check if there are any pieces in the way
    //             if(board.getPiece(i, column) != nullptr){
    //                 return false;
    //             }
    //         }
    //     }
    // }
    // else{
    //     if(newCol > column){   //if we're moving right
    //         for(int i = column + 1; i < newCol; i++){          //check if there are any pieces in the way
    //             if(board.getPiece(row, i) != nullptr){
    //                 return false;
    //             }
    //         }
    //     }
    //     else{               //if we're moving left
    //         for(int i = column - 1; i > newCol; i--){          //check if there are any pieces in the way
    //             if(board.getPiece(row, i) != nullptr){
    //                 return false;
    //             }
    //         }
    //     }
    // }

    // return true;
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
    
    // 1 means down/right
    // 0 mean no change
    // -1 means up/left
    int rowDir = (newRow - row) == 0 ? 0 : (newRow - row) > 0 ? 1 : -1;
    int colDir = (newCol - column) == 0? 0:  (newCol - column) > 0 ? 1: -1;
    int maxDistance = 0;

    if (newRow == row)  // check to see if the rook moved horizontally or vertically, and assign the distance it traveled
        maxDistance = absValue(newCol - column);
    else
        maxDistance = absValue(newRow - row);
    
    if (newRow == row || newCol == column) {
        for (int i = 1; i < maxDistance; i++)
        {
            if (board.getPiece(row + (i * rowDir), column + (i * colDir)) != nullptr)
                return false;
        }
        return true;
    }        
    // did not move horizontally/vertically
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