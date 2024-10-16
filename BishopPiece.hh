#ifndef __BISHOPPIECE_H__
#define __BISHOPPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Bishop chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class BishopPiece : public ChessPiece
    {
        public:
        BishopPiece(ChessBoard &board, Color color, int row, int column);
        virtual ~BishopPiece() {}
        bool canMoveToLocation(int newRow, int newCol); // override chessPiece canMoveToLocation method
        const char* toString();                         // override chessPiece toString method
    };
}

#endif
