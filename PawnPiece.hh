#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class PawnPiece : public ChessPiece
    {

        public:
        /**
         * @brief
         * Constructor for PawnPiece.
         * @param board
         * The board to which the piece belongs.
         * @param color
         * The colour of the piece.
         * @param row
         * Starting row of the piece.
         * @param column
         * Starting column of the piece.
         */
        PawnPiece(ChessBoard &board, Color color, int row, int column); 

        /**
         * @brief
         * Default destructor for PawnPiece.
         * Does nothing special.
         */
        virtual ~PawnPiece() {}

        bool canMoveToLocation(int newrow, int newcolumn);

        const char* toString();





    };
}

#endif
