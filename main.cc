#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "iostream"

void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}


int main()
{
    //test_part1_4x4_1();
    Student::ChessBoard Board(8, 8);
    Board.createChessPiece(Black, Bishop, 7, 0);
    Board.createChessPiece(White, Pawn, 7, 1);
    Board.createChessPiece(Black, Bishop, 6, 3);
    //Board.createChessPiece(White, Pawn, 3, 5);
    //Board.createChessPiece(White, Pawn, 4, 5);
    //std::cout << Board.displayBoard().str();

    //bool result = Board.isValidMove(2, 0, 0, 0);        //from (3, 2) to (3,1) should return true
    int maxRow = 8;
    int maxCol = 8;

    int pieceRow = 7;
    int pieceCol = 1;
    // for (int row = 0; row < maxRow; row++) {
    //     for (int col = 0; col < maxCol; col++) {
    //         std::cout << Board.isValidMove(pieceRow, pieceCol, row, col) << " ";
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << Board.isValidMove(pieceRow, pieceCol, 5, 1);

    // std::cout << Board.isValidMove(2, 0, 0, 1) << std::endl;
    // std::cout << Board.isValidMove(2, 0, 1, 1) << std::endl;
    // std::cout << Board.isValidMove(2, 0, 2, 1) << std::endl;
    // std::cout << Board.isValidMove(2, 0, 2, 1) << std::endl;

    return EXIT_SUCCESS;
}
