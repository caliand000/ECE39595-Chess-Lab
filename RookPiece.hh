#ifndef _ROOKPIECE_H__
#define _ROOKPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Rook chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class RookPiece : public ChessPiece
    {
        public:
        RookPiece(ChessBoard &board, Color color, int row, int column);
        virtual ~RookPiece() {}
        bool canMoveToLocation(int newRow, int newCol); // override chessPiece canMoveToLocation method
        const char* toString();                         // override chessPiece toString method
    };
}

#endif
