#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a King chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class KingPiece : public ChessPiece
    {
        public:
        /**
         * @brief
         * Constructor for KingPiece.
         * @param board
         * The board to which the piece belongs.
         * @param color
         * The colour of the piece.
         * @param row
         * Starting row of the piece.
         * @param column
         * Starting column of the piece.
         */
        KingPiece(ChessBoard &board, Color color, int row, int column); 

        /**
         * @brief
         * Default destructor for KingPiece.
         * Does nothing special.
         */
        virtual ~KingPiece() {}

        /**
         * @brief
         * Determines if the KingPiece can move to the specified location.
         * @param newrow
         * The row to move to.
         * @param newcolumn
         * The column to move to.
         * @return
         * True if the move is valid, false otherwise.
         */
        bool canMoveToLocation(int newrow, int newcolumn) override;

        /**
         * @brief
         * Returns a string representation of the KingPiece.
         * @return
         * A C-string representing the KingPiece.
         */
        const char* toString();

    };
}

#endif
