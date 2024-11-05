#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "iostream"

void testAllMoves(Student::ChessBoard &board) {
    for (int fromRow = 0; fromRow < 4; ++fromRow) {
        for (int fromCol = 0; fromCol < 4; ++fromCol) {
            for (int toRow = 0; toRow < 4; ++toRow) {
                for (int toCol = 0; toCol < 4; ++toCol) {
                    // Exclude moves to the same location
                    if (fromRow == toRow && fromCol == toCol) {
                        continue;
                    }
                    bool valid = board.isValidMove(fromRow, fromCol, toRow, toCol);
                    std::cout << "Move from (" << fromRow << ", " << fromCol << ") to (" << toRow << ", " << toCol << "): " << (valid ? "Valid" : "Invalid") << std::endl;
                }
            }
        }
    }
}

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

void test_part3_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // b k 0 0
    // w k 3 0
    // ~

    Student::ChessBoard Board(4, 4);
    Board.createChessPiece(White, Rook, 3, 2);
    Board.createChessPiece(Black, Bishop, 1, 3);
    Board.createChessPiece(Black, Rook, 1, 1);
    Board.createChessPiece(White, Rook, 2, 3);
    Board.createChessPiece(Black, King, 0, 0);
    Board.createChessPiece(White, King, 3, 0);

    std::cout << Board.displayBoard().str();
    // testAllMoves(Board);

    Board.movePiece(3, 0, 2, 0);

    std::cout << Board.displayBoard().str();
    // testAllMoves(Board);

    bool valid = Board.isValidMove(0, 0, 1, 0);
                    std::cout << "Move from (" << 0 << ", " << 0 << ") to (" << 1 << ", " << 0 << "): " << (valid ? "Valid" : "Invalid") << std::endl;


    return;
}


int main()
{


    test_part3_4x4_1();



    //test_part1_4x4_1();
    // Student::ChessBoard Board(8, 8);
    // Board.createChessPiece(Black, Bishop, 7, 0);
    // Board.createChessPiece(White, Pawn, 7, 1);
    // Board.createChessPiece(Black, Bishop, 6, 3);
    //Board.createChessPiece(White, Pawn, 3, 5);
    // Board.createChessPiece(White, King, 4, 5);
    // std::cout << Board.displayBoard().str();

    //bool result = Board.isValidMove(2, 0, 0, 0);        //from (3, 2) to (3,1) should return true
    // int maxRow = 8;
    // int maxCol = 8;

    // int pieceRow = 7;
    // int pieceCol = 1;
    // for (int row = 0; row < maxRow; row++) {
    //     for (int col = 0; col < maxCol; col++) {
    //         std::cout << Board.isValidMove(pieceRow, pieceCol, row, col) << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << Board.isValidMove(pieceRow, pieceCol, 5, 1);

    // std::cout << Board.isValidMove(2, 0, 0, 1) << std::endl;
    // std::cout << Board.isValidMove(2, 0, 1, 1) << std::endl;
    // std::cout << Board.isValidMove(2, 0, 2, 1) << std::endl;
    // std::cout << Board.isValidMove(2, 0, 2, 1) << std::endl;

    return EXIT_SUCCESS;
}
