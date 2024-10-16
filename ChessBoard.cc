#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;
using Student::ChessPiece;
using Student::PawnPiece;
using Student::RookPiece;
using Student::BishopPiece;

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}

// Constructor: Initializes the board with given rows and columns
ChessBoard::ChessBoard(int numRow, int numCol)
    : numRows(numRow), numCols(numCol)
{
    // Resize the 2D board and initialize each pointer to nullptr
    board.resize(numRows, std::vector<ChessPiece *>(numCols, nullptr));
}

// Creates a new chess piece on the board
void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn)
{
    //verify that the given position is within the board
    if (startRow < 0 || startRow >= numRows || startColumn < 0 || startColumn >= numCols)
    {
        return;
    }

    //save old piece
    ChessPiece *oldPiece = getPiece(startRow, startColumn);
    //board.at(startRow).at(startColumn);

    // Create a new piece based on the given type and place it on the board
    ChessPiece *newPiece = nullptr;
    switch (ty)
    {
    case Pawn:
        newPiece = new PawnPiece(*this, col, startRow, startColumn);
        break;
    case Rook:
        newPiece = new RookPiece(*this, col, startRow, startColumn);
        break;
    case Bishop:
        newPiece = new BishopPiece(*this, col, startRow, startColumn);
        break;
    // Add other cases for different piece types if needed
    default:
        break;
    }

    // Delete the old piece
    if(oldPiece != nullptr)
    {
        delete oldPiece;
    }

    // Assign the new piece to the board
    board.at(startRow).at(startColumn) = newPiece;
}