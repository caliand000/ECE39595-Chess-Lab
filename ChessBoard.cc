//TODO: boolIsValidMove()

#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include <iostream>

using Student::ChessBoard;
using Student::ChessPiece;
using Student::PawnPiece;
using Student::RookPiece;
using Student::BishopPiece;
using Student::KingPiece;

// Constructor: Initializes the board with given rows and columns
ChessBoard::ChessBoard(int numRow, int numCol)
    : numRows(numRow), numCols(numCol)
{
    // Resize the 2D board and initialize each pointer to nullptr
    board.resize(numRows, std::vector<ChessPiece *>(numCols, nullptr));
}

// Destructor: removes all ChessPiece objects from ChessBoard
ChessBoard::~ChessBoard() {
    // go through the entire array, determine if there is a piece, remove
    // that piece if so

    // this for loop goes through the rows
    for (std::vector<Student::ChessPiece *> rowPtrs : board) {
        // this for loop goes through the cols
        for (Student::ChessPiece * piecePtr :rowPtrs) {
            //if (piecePtr != nullptr) {}
                delete piecePtr;
        }
    }

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
    case King:
        newPiece = new KingPiece(*this, col, startRow, startColumn);
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
bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    // used for part 2/3, doesn't need to be implemented yet

    // if there is no piece at the specific location
    if (getPiece(fromRow, fromColumn) == nullptr)
        return false;

    // obtain the current color of the piece to move
    Color currPiece = getPiece(fromRow, fromColumn)->getColor();
    if (currPiece != turn)  // incorrect color turn  
        return false;
    if (!isValidMove(fromRow, fromColumn, toRow, toColumn)) // check if move to that position is valid
        return false;
    
    // piece can move to the new square
    delete board.at(toRow).at(toColumn);    // delete the guy that was killed
    board.at(toRow).at(toColumn) = board.at(fromRow).at(fromColumn);    // copy pointer from old square to new square
    board.at(fromRow).at(fromColumn) = nullptr;                         // set the old square to be empty again 
    getPiece(toRow,toColumn)->setPosition(toRow, toColumn);             // change the space
    turn = turn == White ? Black : White;   // change turns

    return true;    // piece is safe to move to the area
}

//TODO
// check if move is valid
bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
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
   //check if coordinates are the same
   if(fromRow == toRow && fromColumn == toColumn)
   {
       return false;
   }
    //check if there is a piece at the from position
    if(board.at(fromRow).at(fromColumn) == nullptr)
    {
        return false;
    }
    //check if same color piece is at the to position, if piece exists
    if(board.at(toRow).at(toColumn) != nullptr)
    {
        if(board.at(fromRow).at(fromColumn)->getColor() == board.at(toRow).at(toColumn)->getColor())
        {
            return false;
        }
    }
    //now check canMoveToLocation
    if(board.at(fromRow).at(fromColumn)->canMoveToLocation(toRow, toColumn) == false)
    {
        return false;
    }


    //logic for if king for same color of the move under threat
    //first we need to attempt the move and then read the board to 
    //determine if the king is currently under threat
    //if the king is under threat, then the move is invalid

    //store original piece locations before attempting move
    ChessPiece *Piece = board.at(fromRow).at(fromColumn);
    ChessPiece *startPiece = Piece;
    ChessPiece *endPiece = board.at(toRow).at(toColumn);

    //attempt the move
    board.at(toRow).at(toColumn) = Piece;
    Piece->setPosition(toRow, toColumn);
    //delete the piece at the original location
    board.at(fromRow).at(fromColumn) = nullptr;

    //check if the king is under threat
    bool underThreat = false;

    //find king of same color on the board
    ChessPiece *king = nullptr;

    std::vector<std::vector<ChessPiece*>>::iterator rows = board.begin();
    while (rows != board.end()) {
        std::vector<ChessPiece*>::iterator piece_iter = (*rows).begin();  // Using auto here instead of retyping the iterator definition
        while (piece_iter != rows->end()) {
            // Looking for the same color king
            if (*piece_iter != nullptr && (*piece_iter)->getColor() == Piece->getColor() && (*piece_iter)->getType() == King) {
                std::cout << "Found King: "<< (*piece_iter)->getRow() << (*piece_iter)->getColumn()  << std::endl;
                king = *piece_iter;
                break;
            }
            ++piece_iter;
        }
        ++rows;
    }

    //if king is under attack
    if(king != nullptr && isPieceUnderThreat(king->getRow(), king->getColumn()) == true && king->getColor() == turn){
        underThreat = true;
    }

    //reset the board to original state
    board.at(fromRow).at(fromColumn) = startPiece;
    startPiece->setPosition(fromRow, fromColumn);
    board.at(toRow).at(toColumn) = endPiece;

    std::cout << "King under threat: " << (underThreat ? "Yes" : "No") << std::endl;

    //if king is under threat then return false
    if(underThreat == true)
    {
        return false;
    }

   return true;
}

// check if piece can be attacked
bool ChessBoard::isPieceUnderThreat(int row, int column) {
    // used for part 2/3, doesn't need to be implemented yet
    // go through all the opposing color's pieces and run 'isValidMove()'
    // on the square of the piece about to be attacked.
    if (getPiece(row, column) == nullptr)
        return false;
    Color currPiece = getPiece(row, column)->getColor();    // obtain the color
    
    // determine opposing piece color
    Color oppPiece;
    if (currPiece == White)
        oppPiece = Black;
    else
        oppPiece = White;
    
    // go through the vector of vectors
    for (std::vector<Student::ChessPiece *> rowPtrs : board) {
        // go through the elements within one vector
        for (Student::ChessPiece * piecePtr :rowPtrs) {
            // if you find a piece of the opposing color
            if (piecePtr != NULL)
            {
                if (piecePtr->getColor() == oppPiece)
                {
                    // if((getPiece(row, column))->getType() == King)      //if curr piece is a king
                    // {
                    //     if(piecePtr->canMoveToLocation(row, column))    //if the opposing piece can move to the king
                    //         return true;
                    // }
                    // else if(piecePtr->getType() == King){
                    //     if(piecePtr->canMoveToLocation(row, column))    //if the opposing piece can move to the king
                    //         return true;
                    // }
                    // //check if the opposing piece can make a valid move onto the current piece. if it can, the current piece
                    // // is under threat
                    // else if (isValidMove(piecePtr -> getRow(), piecePtr -> getColumn(), row, column))   
                    //     return true;
                    // // else if(!isValidMove(piecePtr -> getRow(), piecePtr -> getColumn(), row, column) && isKingUnderThreat(piecePtr -> getRow(), piecePtr -> getColumn(), row, column))
                    // //     return true;
                    if(piecePtr->canMoveToLocation(row, column))    //if the opposing piece can move to the king
                        return true;
                }
            }
        }
    }
    return false;   // there are no pieces of the opposing color, or none of the enemy
                    // pieces can attack my piece at that square
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

