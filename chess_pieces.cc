#include "chess_pieces.hh"
#include <cmath>

Pawn::Pawn(bool isWhite) : Piece(isWhite){}
Knight::Knight(bool isWhite) : Piece(isWhite){}
Bishop::Bishop(bool isWhite) : Piece(isWhite){}
Rook::Rook(bool isWhite) : Piece(isWhite){}
Queen::Queen(bool isWhite) : Piece(isWhite){}
King::King(bool isWhite) : Piece(isWhite){}

Pawn::Pawn(bool isWhite, int x, int y) : Piece(isWhite, x, y, isWhite ? 'P' : 'p'){}
Knight::Knight(bool isWhite, int x, int y) : Piece(isWhite, x, y, isWhite ? 'N' : 'n'){}
Bishop::Bishop(bool isWhite, int x, int y) : Piece(isWhite, x, y, isWhite ? 'B' : 'b'){}
Rook::Rook(bool isWhite, int x, int y) : Piece(isWhite, x, y, isWhite ? 'R' : 'r'){}
Queen::Queen(bool isWhite, int x, int y) : Piece(isWhite, x, y, isWhite ? 'Q' : 'q'){}
King::King(bool isWhite, int x, int y) : Piece(isWhite, x, y, isWhite ? 'K' : 'k'){}


PieceType Pawn::getType() {return PAWN;}
PieceType Knight::getType() {return KNIGHT;}
PieceType Bishop::getType() {return BISHOP;}
PieceType Rook::getType() {return ROOK;}
PieceType Queen::getType() {return QUEEN;}
PieceType King::getType() {return KING;}

bool Pawn::canMoveTo(int x, int y)
{
    int currentX = getPosition()->getX();
    int currentY = getPosition()->getY();

    int dx = x - currentX;
    int dy = y - currentY;

    if (isWhite())
    {
        if (dx == 0 && (dy == 1 || (currentY == 1 && dy == 2)))
            return true;

        if (std::abs(dx) == 1 && dy == 1)
            return true;
    }
    else
    {
        if (dx == 0 && (dy == -1 || (currentY == 6 && dy == -2)))
            return true;

        if (std::abs(dx) == 1 && dy == -1)
            return true;
    }

    return false;
}
bool Knight::canMoveTo(int x, int y)
{
    int currentX = getPosition()->getX();
    int currentY = getPosition()->getY();

    int dx = std::abs(x - currentX);
    int dy = std::abs(y - currentY);

    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
bool Bishop::canMoveTo(int x, int y)
{
    int currentX = getPosition()->getX();
    int currentY = getPosition()->getY();

    int dx = std::abs(x - currentX);
    int dy = std::abs(y - currentY);

    return dx == dy;
}
bool Rook::canMoveTo(int x, int y)
{
    int currentX = getPosition()->getX();
    int currentY = getPosition()->getY();

    return x == currentX || y == currentY;
}
bool Queen::canMoveTo(int x, int y)
{
    int currentX = getPosition()->getX();
    int currentY = getPosition()->getY();

    int dx = std::abs(x - currentX);
    int dy = std::abs(y - currentY);

    return (x == currentX) || (y == currentY) || (dx == dy);
}
bool King::canMoveTo(int x, int y)
{
    int currentX = getPosition()->getX();
    int currentY = getPosition()->getY();

    int dx = std::abs(x - currentX);
    int dy = std::abs(y - currentY);

    return dx <= 1 && dy <= 1;
}