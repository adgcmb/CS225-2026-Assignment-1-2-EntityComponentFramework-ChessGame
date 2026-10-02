#pragma once
#include "chess_base.hh"

class Pawn : public Piece
{
public:
    Pawn(bool isWhite);
    Pawn(bool isWhite, int x, int y);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Knight : public Piece
{
public:
    Knight(bool isWhite);
    Knight(bool isWhite, int x, int y);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Bishop : public Piece
{
public:
    Bishop(bool isWhite);
    Bishop(bool isWhite, int x, int y);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Rook : public Piece
{
public:
    Rook(bool isWhite);
    Rook(bool isWhite, int x, int y);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class Queen : public Piece
{
public:
    Queen(bool isWhite);
    Queen(bool isWhite, int x, int y);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};

class King : public Piece
{
public:
    King(bool isWhite);
    King(bool isWhite, int x, int y);
    bool canMoveTo(int x, int y) override;
    PieceType getType() override;
};