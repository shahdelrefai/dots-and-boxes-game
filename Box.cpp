//
// Created by Shahd El-Refai on 13/12/2022.
//

#include "Box.h"
#include "DotsAndBoxesGame.h"

void Box::UpdateNumberOfDrawnLines()
{
    this->NLines += 1;
}
void Box::UndoNumberOfDrawnLines()
{
    if(this->NLines > 0)
        this->NLines -= 1;
}

bool Box::CheckIfBoxIsDrawn()
{
    if(this->NLines == 4)
    {
        return true;
    }
    return false;
}
void Box::UpdateDrawnBox(int playerClaimed)
{
    this->PlayerClaimed = playerClaimed;
}

void Box::UndoDrawnBox()
{
    this->PlayerClaimed = -1;
}