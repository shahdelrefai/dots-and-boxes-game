//
// Created by Shahd El-Refai on 29/01/2023.
//

#include "Edge.h"

void Edge::UpdateDrawnEdge(int edgePlayer)
{
    this->drawn = true;
    this->EdgePlayer = edgePlayer;
}
void Edge::UndoDrawnEdge()
{
    this->drawn = false;
    this->EdgePlayer = -1;
}