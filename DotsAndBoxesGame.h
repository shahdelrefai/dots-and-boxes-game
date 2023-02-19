//
// Created by Shahd El-Refai on 09/12/2022.
//
#ifndef DOTS_AND_BOXES_DOTSANDBOXESGAME_H
#define DOTS_AND_BOXES_DOTSANDBOXESGAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include "Box.h"
#include "Edge.h"
using namespace std;

class DotsAndBoxesGame {
public:
    enum Menu{MainMenu, StartGameMenu, LoadGameMenu, TopTenMenu, Exit};
    Menu MyMenu = MainMenu;

    void ChooseMenu(int page);
    int CheckValidGridSize(string gridSize);
    int ChooseGameMode(char chosen);

    void RunMainMenu();
    void RunStartGameMenu();
    void RunChooseGameGridMenu();
    void RunChooseGameModeMenu();

    void RunMenu();


    enum Player{Player1, Player2, Tie};
    Player GameTurn = Player1;
    Player GameWinner;

    bool changeTurn;
    array<int, 2> PlayerScore{0, 0};
    array<int,2> OnStartGamePlayerScore{0, 0};

    enum Mode{HumanVsHuman, HumanVsComputer};
    Mode GameMode;

    string GridSize;
    vector<vector<tuple<char, Player>>> Grid;

    vector<vector<Box>> Boxes;
    map<string, Edge> EdgesMap;
    map<string, vector<Box*>> BoxesMap;
    int NumberOfMovesLeft = 0;

    string currentMove;
    string  currentMoveReversed;

    stack<tuple<string, string, Player, array<int, 2>>> MovesStack;
    tuple<string, string, Player, array<int,2>> currentMoveTuple;
    stack<tuple<string, string, Player, array<int, 2>>> RedoStack;


    void RunGame();

    void LoadGame();


    void ConstructBoxes();
    void MapVerticalBoxes(int y, int x, string currentEdge);
    void MapHorizontalBoxes(int y, int x, string currentEdge);
    void MapEdges();


    void ConstructGrid();
    void UpdateHorizontalLineOnGrid(string thisCurrentMove, bool draw, Player edgePlayer);
    void UpdateVerticalLineOnGrid(string thisCurrentMove, bool draw, Player edgePlayer);
    void UpdateBoxOnGrid(int y, int x, bool boxClaimed, Player playerClaimed);
    void DisplayGrid();

    void DisplayGame();


    void GetWinner();
    void EndGame();


    int GetMoveInput();
    bool CheckIfValidMoveInput();
    bool UndoOrRedo();

    void GetMove();


    void UpdateDrawnEdge();
    void UpdateDrawnBox();
    void UndoDrawnEdge();
    void UndoDrawnBox();
    void AskSaveGame();


    void UpdateScore();
    void ChangeGameTurn();
    void AddMoveToStack();


    void MakeMove();
    void UndoMove();
    void RedoMove();

    void saveToFile(const std::string &fileName);
    void loadFromFile(const std::string &fileName);
};
#endif //DOTS_AND_BOXES_DOTSANDBOXESGAME_H