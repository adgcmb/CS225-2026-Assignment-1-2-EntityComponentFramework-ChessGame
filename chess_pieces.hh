#pragma once
#include "chess_base.hh"

class Queen : public Piece
{
    public:
        Queen(bool isWhite);
        bool canMoveTo(int x, int y) override;
        PieceType getType() override;
};