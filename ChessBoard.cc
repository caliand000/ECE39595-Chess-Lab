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


// moves piece from one position to another
bool movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    // used for part 2/3, doesn't need to be implemented yet
}

//TODO
// check if move is valid
bool isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    /* check if there are any pieces in the way of the desire movement here?
    currently the canMoveToLocation() function just checks if a piece is
    doing a possible move without accounting for pieces in the way

    idea:
        maybe use another switch statement to define different squares to
        check for depending on rook/pawn/bishop.
        ex. for bishop, calculate direction of diagonal movement, then check
        all the squares along that line (maybe use getPiece() func)
        to see if a piece exists before the place the bishop should
        move to

        ex. for rook, calculate direction of movement, then check squares
        along that line to see if theres a piece along the line

        ex. for pawn, just check if square above or below has a piece

        to calculate direction of movement, do y(toRow - fromRow) and
        x(toCol - fromCol)
        +y - piece moved down
        -y - piece moved up

        +x - piece moved right
        -x - piece moved left
    */
}

// check if piece can be attacked
bool isPieceUnderThreat(int row, int column) {
    // used for part 2/3, doesn't need to be implemented yet
}

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

