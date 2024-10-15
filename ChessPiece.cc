#include "ChessPiece.hh"
#include "ChessBoard.hh"

using Student::ChessPiece;

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column) : board(board), color(color), row(row), column(column)
{
}
