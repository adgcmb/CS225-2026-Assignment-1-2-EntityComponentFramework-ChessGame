#include "chess_base.hh"

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
    //initiallize the board everithing to null

}