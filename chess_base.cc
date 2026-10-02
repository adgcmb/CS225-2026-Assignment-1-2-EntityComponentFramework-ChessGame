#include "chess_base.hh"
#include "chess_pieces.hh"

Piece::Piece(bool isWhite)
{
    is_color_white = isWhite;
}

Piece::Piece(bool isWhite, int x, int y, char letter)
{
    is_color_white = isWhite;
    attach(new PositionComponent(x,y));
    attach(new VisualComponent(letter));
}
bool Piece::isWhite()
{
    return is_color_white;
}

PositionComponent* Piece::getPosition()
{
    PositionComponent* newPosComp = dynamic_cast<PositionComponent*>(getComponent("Position"));
    return newPosComp;
}
VisualComponent* Piece::getVisual()
{
    VisualComponent* newVisual = dynamic_cast<VisualComponent*>(getComponent("Visual"));
    return newVisual;
}

Piece::~Piece(){}
 

 
void ChessBoard::initializeBoard()
{
    for (int y = 0; y < BOARD_SIZE; y++)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            board[y][x] = nullptr;
        }
    }

    //WHITE
    for (int x = 0; x < BOARD_SIZE; x++)
    {
        setPieceAt(new Pawn(true, x, 1), x, 1);
    }

    setPieceAt(new Rook(true,   0, 0), 0, 0);
    setPieceAt(new Knight(true, 1, 0), 1, 0);
    setPieceAt(new Bishop(true, 2, 0), 2, 0);
    setPieceAt(new Queen(true,  3, 0), 3, 0);
    setPieceAt(new King(true,   4, 0), 4, 0);
    setPieceAt(new Bishop(true, 5, 0), 5, 0);
    setPieceAt(new Knight(true, 6, 0), 6, 0);
    setPieceAt(new Rook(true,   7, 0), 7, 0);

    //BLACK
    for (int x = 0; x < BOARD_SIZE; x++)
    {
        setPieceAt(new Pawn(false, x, 6), x, 6);
    }

    setPieceAt(new Rook(false,   0, 7), 0, 7);
    setPieceAt(new Knight(false, 1, 7), 1, 7);
    setPieceAt(new Bishop(false, 2, 7), 2, 7);
    setPieceAt(new Queen(false,  3, 7), 3, 7);
    setPieceAt(new King(false,   4, 7), 4, 7);
    setPieceAt(new Bishop(false, 5, 7), 5, 7);
    setPieceAt(new Knight(false, 6, 7), 6, 7);
    setPieceAt(new Rook(false,   7, 7), 7, 7);

}

Piece* ChessBoard::getPieceAt(int x, int y)
{
    return board[y][x];
}

void ChessBoard::setPieceAt(Piece* piece, int x, int y)
{
    board[y][x] = piece;
}

ChessBoard::~ChessBoard()
{
    for (int y = 0; y < BOARD_SIZE; y++)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            delete board[y][x];
        }
    }
}