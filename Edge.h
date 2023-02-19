//
// Created by Shahd El-Refai on 29/01/2023.
//

#ifndef DOTS_AND_BOXES_EDGE_H
#define DOTS_AND_BOXES_EDGE_H
#include <iostream>
using namespace std;


class Edge {
public:
    string linkedDots;
    bool drawn = false;
    int EdgePlayer = -1;
    enum Direction{Horizontal, Vertical};
    Direction LineDirection;

    void UpdateDrawnEdge(int edgePlayer);
    void UndoDrawnEdge();
};


#endif //DOTS_AND_BOXES_EDGE_H
