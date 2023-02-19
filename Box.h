//
// Created by Shahd El-Refai on 13/12/2022.
//
#ifndef DOTS_AND_BOXES_BOX_H
#define DOTS_AND_BOXES_BOX_H

class Box {
public:
    int y, x;
    int NLines = 0;
    int PlayerClaimed = -1;

    void UpdateNumberOfDrawnLines();
    void UndoNumberOfDrawnLines();

    bool CheckIfBoxIsDrawn();
    void UpdateDrawnBox(int playerClaimed);
    void UndoDrawnBox();
};


#endif //DOTS_AND_BOXES_BOX_H
