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

void testAllThreats(Student::ChessBoard &board, int rows, int cols) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            bool valid = board.isPieceUnderThreat(row, col);
            std::cout << "Piece (" << row << ", " << col << ") is: " << (valid ? "Under Threat" : "Not Under Threat") << std::endl;
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
    testAllMoves(Board);
    Board.movePiece(3, 0, 2, 0);
    std::cout << Board.displayBoard().str();
    testAllMoves(Board);
    bool valid = Board.isValidMove(0, 0, 1, 0);
    std::cout << "Move from (" << 0 << ", " << 0 << ") to (" << 1 << ", " << 0 << "): " << (valid ? "Valid" : "Invalid") << std::endl;
    return;
}

void test_part3_4x4_2()
{
    // Config file content:
    // 0
    // 4 4
    // b r 3 3
    // b b 0 0
    // b b 3 0
    // w r 2 3
    // b k 3 1
    // w k 1 0
    // ~
    Student::ChessBoard Board(4, 4);
    Board.createChessPiece(Black, Rook, 3, 3);
    Board.createChessPiece(Black, Bishop, 0, 0);
    Board.createChessPiece(Black, Bishop, 3, 0);
    Board.createChessPiece(White, Rook, 2, 3);
    Board.createChessPiece(Black, King, 3, 1);
    Board.createChessPiece(White, King, 1, 0);

    std::cout << Board.displayBoard().str();
    Board.movePiece(2, 3, 2, 0);
    Board.movePiece(3, 3, 0, 3);
    Board.movePiece(2, 0, 2, 2);
    Board.movePiece(0, 0, 1, 1);
    Board.movePiece(2, 1, 2, 1);
    Board.movePiece(2, 2, 3, 2);
    Board.movePiece(3, 1, 3, 2);
    
    Board.movePiece(1, 0, 1, 1);
    //isValidScan
    Board.movePiece(3, 2, 2, 3);
    //isValidScan
    Board.movePiece(3, 3, 2, 1);
    //isValidScan
    // underThreatScan
    Board.movePiece(1, 1, 1, 0);
    //isValidScan
    Board.movePiece(0, 3, 0, 2);
    //isValidScan
    Board.movePiece(1, 0, 2, 0);
    //isValidScan
    Board.movePiece(3, 0, 0, 3);
    //isValidScan
    Board.movePiece(2, 1, 3, 0);
    //isValidScan
    // underThreatScan
    Board.movePiece(2, 0, 3, 1);
    //isValidScan
    Board.movePiece(0, 3, 1, 2);
    //isValidScan
    Board.movePiece(3, 1, 2, 0);
    //isValidScan
    Board.movePiece(2, 3, 3, 3);
    //isValidScan
    Board.movePiece(3, 0, 1, 2);
    //isValidScan
    // underThreatScan
    Board.movePiece(2, 0, 1, 0);
    //isValidScan
    Board.movePiece(1, 2, 2, 1);
    //isValidScan
    Board.movePiece(1, 0, 2, 1);
    //isValidScan
    std::cout << Board.displayBoard().str();
    Board.movePiece(0, 2, 3, 2);
    //isValidScan
    std::cout << Board.displayBoard().str();
    Board.movePiece(1, 2, 0, 2);
    //isValidScan
    std::cout << Board.displayBoard().str();
    // underThreatScan

    bool valid  = Board.isPieceUnderThreat(3, 3);
    std::cout << "Piece (" << 3 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;

    valid  = Board.isPieceUnderThreat(2, 2);
    std::cout << "Piece (" << 2 << ", " << 2 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    return;
}

void test_part3_4x4_5()
{
    // 0
    // 4 4
    // b p 0 2
    // w b 2 1
    // w r 1 3
    // w r 1 0
    // b k 1 0
    // w k 3 2
    // ~
    Student::ChessBoard Board(4, 4);
    Board.createChessPiece(Black, Pawn, 0, 2);
    Board.createChessPiece(White, Bishop, 2, 1);
    Board.createChessPiece(White, Rook, 1, 3);
    Board.createChessPiece(White, Rook, 1, 0);
    Board.createChessPiece(Black, King, 1, 0);
    Board.createChessPiece(White, King, 3, 2);

    std::cout << Board.displayBoard().str();
    bool valid  = Board.isPieceUnderThreat(1, 0);
    std::cout << "Piece (" << 1 << ", " << 0 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    valid  = Board.isPieceUnderThreat(3, 2);
    std::cout << "Piece (" << 3 << ", " << 2 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    valid  = Board.isPieceUnderThreat(2, 1);
    std::cout << "Piece (" << 2 << ", " << 1 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    valid  = Board.isPieceUnderThreat(0, 2);
    std::cout << "Piece (" << 0 << ", " << 2 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    valid  = Board.isPieceUnderThreat(1, 3);
    std::cout << "Piece (" << 1 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    valid  = Board.isPieceUnderThreat(3, 3);
    std::cout << "Piece (" << 3 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    valid  = Board.isPieceUnderThreat(1, 3);
    std::cout << "Piece (" << 1 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;

    return;
}

void test_part3_4x4_8()
{
    // 0
    // 4 4
    // b p 0 2
    // w b 2 1
    // w r 1 3
    // w r 1 0
    // b k 1 0
    // w k 3 2
    // ~
    Student::ChessBoard Board(4, 4);
    Board.createChessPiece(White, Pawn, 2, 3);
    Board.createChessPiece(Black, Rook, 1, 3);
    Board.createChessPiece(Black, Pawn, 2, 2);
    Board.createChessPiece(Black, Rook, 1, 2);
    Board.createChessPiece(Black, King, 1, 1);
    Board.createChessPiece(White, King, 3, 1);

    std::cout << Board.displayBoard().str();

    testAllThreats(Board, 4, 4);
    // bool valid  = Board.isPieceUnderThreat(2, 3);
    // std::cout << "Piece (" << 2 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    // valid  = Board.isPieceUnderThreat(1, 3);
    // std::cout << "Piece (" << 1 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    // valid  = Board.isPieceUnderThreat(2, 2);
    // std::cout << "Piece (" << 2 << ", " << 2 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    // bool valid  = Board.isPieceUnderThreat(1, 2);
    // std::cout << "Piece (" << 1 << ", " << 2 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    // valid  = Board.isPieceUnderThreat(1, 1);
    // std::cout << "Piece (" << 1 << ", " << 1 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    // valid  = Board.isPieceUnderThreat(3, 3);
    // std::cout << "Piece (" << 3 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;
    // valid  = Board.isPieceUnderThreat(1, 1);
    // std::cout << "Piece (" << 1 << ", " << 3 << ") is: " << (valid ? "Valid" : "Invalid") << std::endl;

    return;
}

int main()
{


    test_part3_4x4_8();



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
