//
// Created by Shahd El-Refai on 09/12/2022.
//
#include "DotsAndBoxesGame.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "cmake-build-debug/termcolor.hpp"
#include <array>
#include "Box.h"
#include "Edge.h"
using namespace std;

void DotsAndBoxesGame::RunGame()
{
    this->RunMenu();
    if(this->MyMenu == LoadGameMenu)
    {
        this->LoadGame();
        return;
    }

    this->ConstructBoxes();
    this->MapEdges();
    this->ConstructGrid();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(this->NumberOfMovesLeft != 0)
    {
        this->DisplayGame();
        this->GetMove();
    }
    this->EndGame();
}

void DotsAndBoxesGame::LoadGame()
{
    this->loadFromFile("SavedGame.cpp");

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(this->NumberOfMovesLeft != 0)
    {
        this->DisplayGame();
        this->GetMove();
    }
    this->EndGame();
}


void DotsAndBoxesGame::ChooseMenu(int page)
{
    if(page < 1 or page > 3)
    {
        cout << "Choose a valid input.\n";
        return;
    }
    this->MyMenu = static_cast<Menu>(page);
}
int DotsAndBoxesGame::CheckValidGridSize(string gridSize)
{
    gridSize.erase(remove(gridSize.begin(), gridSize.end(), ' '), gridSize.end());

    if(gridSize[0] == 'b' or gridSize[0] == 'B')
    {
        this->MyMenu = MainMenu;
        return 300;
    }

    if(gridSize.length() < 2)
        return 0;
    gridSize = gridSize.substr(0,2);

    for(char c : gridSize)
        if(!isdigit(c))
            return 0;
    return 1;
}
int DotsAndBoxesGame::ChooseGameMode(char chosen)
{
    if(chosen == 'b' or chosen == 'B')
    {
        return 300;
    }
    if(chosen < '1' or chosen > '2')
    {
        return 0;
    }
    this->GameMode = static_cast<Mode>(int(chosen -'0') - 1);
    return 1;
}

void DotsAndBoxesGame::RunMainMenu()
{
    char page;
    cout << endl
         << " 1 - Start Game.\n"
         << " 2 - Load Game.\n"
         << " 3 - Exit.\n"
         << " Enter your choice and press return: ";
    cin >> page;
    this->ChooseMenu(int(page - '0'));
}
void DotsAndBoxesGame::RunStartGameMenu()
{
    this->RunChooseGameGridMenu();
}
void DotsAndBoxesGame::RunChooseGameGridMenu()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string gridSize;
    int check;
    do{
        cout << endl
             << " Enter 2 numbers that represent the size of the 2D Grid and press return (enter b to go back): ";
        getline(cin, gridSize);
        check = this->CheckValidGridSize(gridSize);
    }while(!check);
    if(check == 300) return;

    this->GridSize = gridSize;
    this->RunChooseGameModeMenu();
}
void DotsAndBoxesGame::RunChooseGameModeMenu()
{
    char chosen;
    int check;
    do {
        cout << endl
             << " 1 - Human vs Human.\n"
             << " 2 - human vs Computer.\n"
             << " Enter your choice and press return (enter b to go back): ";
        cin >> chosen;
        check = this->ChooseGameMode(chosen);
    }while(!check);
    if(check == 300)
    {
        this->MyMenu = StartGameMenu;
        return;
    }

    this->MyMenu = Exit;
}

void DotsAndBoxesGame::RunMenu()
{
    bool exitLoop = false;
    while (!exitLoop)
    {
        switch (this->MyMenu)
        {
            case MainMenu:
                this->RunMainMenu();
                break;
            case StartGameMenu:
                this->RunStartGameMenu();
                break;
            case LoadGameMenu:
                exitLoop = true;
                break;
            case Exit:
                exit(0);
            default:
                this->MyMenu = MainMenu;
                break;
        }
    }
}


void DotsAndBoxesGame::ConstructBoxes()
{
    int Y = int(this->GridSize[0] - '0') - 1;
    int X = int(this->GridSize[1] - '0') - 1;
    this->Boxes.resize(Y, vector<Box>(X));

    for(int y = 0; y < Y; y++)
    {
        for(int x = 0; x < X; x++)
        {
            this->Boxes[y][x].y = y;
            this->Boxes[y][x].x = x;
        }
    }
}
void DotsAndBoxesGame::MapVerticalBoxes(int y, int x, string currentEdge)
{
    int yBox = y, xBox = x-1;
    vector<Box*> boxes;

    for(int adjacentX = x - 1; adjacentX <= x + 1; adjacentX += 2)
    {
        if(adjacentX >= 0 and adjacentX <= 2)
        {
            boxes.push_back(&Boxes[yBox][xBox]);
        }
        xBox++;
    }
    this->BoxesMap[currentEdge] = boxes;
}
void DotsAndBoxesGame::MapHorizontalBoxes(int y, int x, string currentEdge)
{
    int yBox = y-1, xBox = x;
    vector<Box*> boxes;

    for(int adjacentY = y - 1; adjacentY <= y + 1; adjacentY += 2)
    {
        if(adjacentY >= 0 and adjacentY <= 2)
        {
            boxes.push_back(&Boxes[yBox][xBox]);
        }
        yBox++;
    }
    this->BoxesMap[currentEdge] = boxes;
}
void DotsAndBoxesGame::MapEdges()
{
    int Y = int(this->GridSize[0] - '0');
    int X = int(this->GridSize[1] - '0');

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            if (y != Y-1)
            {
                string currentLinkedDots = to_string(y) + to_string(x) + to_string(y + 1) + to_string(x);
                Edge currentEdge;
                currentEdge.linkedDots = currentLinkedDots;
                currentEdge.LineDirection = Edge::Vertical;
                this->EdgesMap[currentLinkedDots] = currentEdge;
                this->MapVerticalBoxes(y, x, currentLinkedDots);

                string currentLinkedDotsReversed = currentLinkedDots.substr(2, 2) + currentLinkedDots.substr(0, 2);
                Edge currentEdgeReversed;
                currentEdgeReversed.linkedDots = currentLinkedDotsReversed;
                currentEdgeReversed.LineDirection = Edge::Vertical;
                this->EdgesMap[currentLinkedDotsReversed] = currentEdgeReversed;
                this->MapVerticalBoxes(y, x, currentLinkedDotsReversed);

                this->NumberOfMovesLeft += 1;
            }

            if (x != X-1)
            {
                string currentLinkedDots = to_string(y) + to_string(x) + to_string(y) + to_string(x + 1);
                Edge currentEdge;
                currentEdge.linkedDots = currentLinkedDots;
                currentEdge.LineDirection = Edge::Horizontal;
                this->EdgesMap[currentLinkedDots] = currentEdge;
                this->MapHorizontalBoxes(y, x, currentLinkedDots);

                string currentLinkedDotsReversed = currentLinkedDots.substr(2, 2) + currentLinkedDots.substr(0, 2);
                Edge currentEdgeReversed;
                currentEdgeReversed.linkedDots = currentLinkedDotsReversed;
                currentEdgeReversed.LineDirection = Edge::Horizontal;
                this->EdgesMap[currentLinkedDotsReversed] = currentEdgeReversed;
                this->MapHorizontalBoxes(y, x, currentLinkedDotsReversed);

                this->NumberOfMovesLeft += 1;
            }
        }
    }
}


void DotsAndBoxesGame::ConstructGrid()
{
    int y = int(this->GridSize[0] - '0') +  (int(this->GridSize[0] - '0') - 1);
    int x = int(this->GridSize[1] - '0') +  (int(this->GridSize[1] - '0') - 1);
    this->Grid.resize(y , vector<tuple<char, Player>>(x));

    for(int i = 0; i < y; i+=2)
    {
        for(int j = 0; j < x; j+=2)
        {
            get<0>(this->Grid[i][j]) = '*';
        }
    }
}
void DotsAndBoxesGame::UpdateHorizontalLineOnGrid(string thisCurrentMove, bool draw, Player edgePlayer)
{
    int y = int(thisCurrentMove[0] - '0')*2, x = int(thisCurrentMove[1] - '0')*2+1;
    if(x > int(thisCurrentMove[3] - '0')*2+1) x = int(thisCurrentMove[3] - '0')*2+1;

    if(draw)
    {
        get<0>(this->Grid[y][x]) = '-';
        get<1>(this->Grid[y][x]) = edgePlayer;
    }
    else
        get<0>(this->Grid[y][x]) = '\0';
}
void DotsAndBoxesGame::UpdateVerticalLineOnGrid(string  thisCurrentMove, bool draw, Player edgePlayer)
{
    int y = int(thisCurrentMove[0] - '0')*2+1, x = int(thisCurrentMove[1] - '0')*2;
    if(y > int(thisCurrentMove[2]- '0')*2+1) y = int(thisCurrentMove[2] - '0')*2+1;

    if(draw)
    {
        get<0>(this->Grid[y][x]) = '|';
        get<1>(this->Grid[y][x]) = edgePlayer;
    }
    else
        get<0>(this->Grid[y][x]) = '\0';

}
void DotsAndBoxesGame::UpdateBoxOnGrid(int y, int x, bool boxClaimed, Player playerClaimed)
{
    y = y*2+1;
    x = x*2+1;

    if(boxClaimed)
    {
        get<0>(this->Grid[y][x]) = 'b';
        get<1>(this->Grid[y][x]) = playerClaimed;
    }
    else
        get<0>(this->Grid[y][x]) = '\0';
}
void DotsAndBoxesGame::DisplayGrid()
{
    int y = int(this->GridSize[0] - '0') +  (int(this->GridSize[0] - '0') - 1);
    int x = int(this->GridSize[1] - '0') +  (int(this->GridSize[1] - '0') - 1);
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
    for (int i = 0; i <= x / 2; i++) {
        cout << i << "\t\t\t";
    }
    cout << endl;

    int line = 0;
    Player edgePlayer;
    Player playerClaimed;
    for (int i = 0; i < y; i++)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
        if(i%2 == 0) cout<< line++;
        else cout<< " ";
        cout<< "\t";

        for (int j = 0; j < x; j++)
        {
            char currentDisplayChar = get<0>(this->Grid[i][j]);

            switch (currentDisplayChar)
            {
                case '\0':
                    if(i%2!=0 and j%2 ==0) cout<<" ";
                    else cout << "\t\t\t";
                    break;
                case '*':
                    cout << "*";
                    break;
                case '|':
                    edgePlayer = get<1>(this->Grid[i][j]);

                    if(edgePlayer == Player1)
                        cout << termcolor::on_color<231> << termcolor::red << "|" << termcolor::color<0>;

                    else if(edgePlayer == Player2)
                        cout << termcolor::on_color<231> << termcolor::blue << "|" << termcolor::color<0>;

                    break;
                case '-':
                    edgePlayer = get<1>(this->Grid[i][j]);

                    if(edgePlayer == Player1)
                        cout << termcolor::on_color<231> << termcolor::red << " --------- " << termcolor::color<0>;
                    else if(edgePlayer == Player2)
                        cout << termcolor::on_color<231> << termcolor::blue << " --------- " << termcolor::color<0>;

                    break;
                case 'b':
                    playerClaimed = get<1>(this->Grid[i][j]);

                    if(playerClaimed == Player1)
                        cout << termcolor::on_color<231> << termcolor::red << "  player 1 " << termcolor::color<0>;
                    else if(playerClaimed == Player2)
                        cout << termcolor::on_color<231> << termcolor::blue << "  player 2 " << termcolor::color<0>;

                    break;

                default:
                    break;
            }
        }
        if(i%2 != 0)
        {
            cout <<"\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t \t";

            for(int j = 0; j < x; j++)
            {
                char currentDisplayChar = get<0>(this->Grid[i][j]);

                if(currentDisplayChar == '|')
                {
                    edgePlayer = get<1>(this->Grid[i][j]);
                    if(edgePlayer == Player1)
                        cout << termcolor::on_color<231> << termcolor::red << "|" << termcolor::color<0>;
                    else if(edgePlayer == Player2)
                        cout << termcolor::on_color<231> << termcolor::blue << "|" << termcolor::color<0>;
                }
                else
                {
                    if(j%2 == 0) cout<<" ";
                    else cout<<"\t\t\t";
                }
            }
        }

        cout << endl;
    }
}

void DotsAndBoxesGame::DisplayGame()
{
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t";
    cout << termcolor::on_color<231> << termcolor::red <<"Player 1 Score : " << this->PlayerScore[Player1] << termcolor::color<0>;
    cout<<"\t\t\tNumber of Moves Left : " << this->NumberOfMovesLeft <<"\t\t\t";
    cout << termcolor::on_color<231> << termcolor::blue  <<"Player 2 Score : " << this->PlayerScore[Player2] << termcolor::color<0> <<"\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------------------";

    if(this->GameTurn == Player1) cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|Player : "<< termcolor::on_color<231> << termcolor::red << "Player 1" << termcolor::color<0> <<"|\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------\n\n";
    else cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|Player : "<< termcolor::on_color<231> << termcolor::blue << "Player 2" << termcolor::color<0> <<"|\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-----------------\n\n";

    this->DisplayGrid();
}


void DotsAndBoxesGame::GetWinner()
{
    if(this->PlayerScore[Player1] > this->PlayerScore[Player2])
        this->GameWinner = Player1;
    else if(this->PlayerScore[Player1] < this->PlayerScore[Player2])
        this->GameWinner = Player2;
    else this->GameWinner = Tie;
}
void DotsAndBoxesGame::EndGame()
{
    this->DisplayGame();
    this->GetWinner();
    cout <<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tGAME HAS ENDED\n";
    if(this->GameWinner == Player1) cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << termcolor::on_color<231> << termcolor::red <<"Player 1 WON!!! with Score : " << this->PlayerScore[Player1] << termcolor::color<0>;
    else if(this->GameWinner == Player2) cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<< termcolor::on_color<231> << termcolor::blue << "Player 2 WON!!! with Score : "<< this->PlayerScore[Player2] << termcolor::color<0>;
    else cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBOTH of you are WINNERS it's a TIE!!!";
}


int DotsAndBoxesGame::GetMoveInput()
{
    cout << "\nEnter Move : ";
    getline(cin, this->currentMove);

    if(this->currentMove.empty())
        return 0;

    return 1;
}
bool DotsAndBoxesGame::CheckIfValidMoveInput()
{
    this->currentMove.erase(remove(this->currentMove.begin(), this->currentMove.end(), ' '), this->currentMove.end());
    this->currentMove = this->currentMove.substr(0,4);
    this->currentMoveReversed = this->currentMove.substr(2, 2) + this->currentMove.substr(0, 2);

    if(!this->EdgesMap.count(this->currentMove) or !this->EdgesMap.count(this->currentMoveReversed))
    {
        cout <<"This move isn't a valid move.\nThe two dots you chose aren't adjacent vertically or horizontally or they're OFF grid size. Please enter a valid move.";
        return false;
    }

    if(this->EdgesMap[this->currentMove].drawn)
    {
        cout << "You have already drawn that line before.\nPlease Enter a valid move.";
        return false;
    }

    return true;
}
bool DotsAndBoxesGame::UndoOrRedo()
{
    string input;
    cout << "Enter U for Undo or R for Redo or press anything else to continue : ";
    getline(cin,input);

    if(input.empty())
        return false;

    if(input[0] == 'U' or input[0] == 'u')
    {
        if(this->MovesStack.empty())
        {
            cout << "There are no moves to Undo\n";
            this->GetMove();
            return true;
        }
        this->UndoMove();
        return true;
    }
    else if(input[0] == 'R' or input[0] == 'r')
    {
        if(this->RedoStack.empty())
        {
            cout << "There are no moves to Redo\n";
            this->GetMove();
            return true;
        }
        this->RedoMove();
        return true;
    }
    return false;
}
void DotsAndBoxesGame::AskSaveGame()
{
    string input;
    cout << "Enter S to save game : ";
    getline(cin,input);

    if(input.empty())
        return;

    if(input[0] == 'S' or input[0] == 's')
    {
        this->saveToFile("SavedGame.cpp");
        exit(0);
    }

    return;
}

void DotsAndBoxesGame::GetMove()
{
    if(!this->MovesStack.empty() or !this->RedoStack.empty())
        if(this->UndoOrRedo()) return;

    this->AskSaveGame();

    bool valid = false;
    do
    {
        if(this->GetMoveInput())
            valid = this->CheckIfValidMoveInput();
    }while(!valid);

    while(!this->RedoStack.empty())
        this->RedoStack.pop();

    this->MakeMove();
}


void DotsAndBoxesGame::UpdateDrawnEdge()
{
    this->EdgesMap[this->currentMove].UpdateDrawnEdge(this->GameTurn);
    this->EdgesMap[this->currentMoveReversed].UpdateDrawnEdge(this->GameTurn);

    this->NumberOfMovesLeft -= 1;

    if(EdgesMap[this->currentMove].LineDirection == Edge::Horizontal) this->UpdateHorizontalLineOnGrid(this->currentMove, true, this->GameTurn);
    else this->UpdateVerticalLineOnGrid(this->currentMove, true, this->GameTurn);
}
void DotsAndBoxesGame::UpdateDrawnBox()
{
    bool pointScored = false;
    for(auto currentBox : this->BoxesMap[this->currentMove])
    {
        currentBox->UpdateNumberOfDrawnLines();
        if(currentBox->CheckIfBoxIsDrawn())
        {
            currentBox->UpdateDrawnBox(this->GameTurn);
            this->UpdateScore();
            pointScored = true;
            this->UpdateBoxOnGrid(currentBox->y, currentBox->x, true, this->GameTurn);
        }
    }
    if(pointScored) this->changeTurn = false;
    else this->changeTurn = true;
}
void DotsAndBoxesGame::UndoDrawnEdge()
{
    this->EdgesMap[this->currentMove].UndoDrawnEdge();
    this->EdgesMap[this->currentMoveReversed].UndoDrawnEdge();

    this->NumberOfMovesLeft += 1;

    if(EdgesMap[this->currentMove].LineDirection == Edge::Horizontal) this->UpdateHorizontalLineOnGrid(this->currentMove, false,this->GameTurn);
    else this->UpdateVerticalLineOnGrid(this->currentMove, false, this->GameTurn);
}
void DotsAndBoxesGame::UndoDrawnBox()
{
    for(auto currentBox : this->BoxesMap[this->currentMove])
    {
        if(currentBox->CheckIfBoxIsDrawn())
        {
            currentBox->UndoDrawnBox();
            this->UpdateBoxOnGrid(currentBox->y, currentBox->x, false, this->GameTurn);
        }
        currentBox->UndoNumberOfDrawnLines();
    }
}


void DotsAndBoxesGame::UpdateScore()
{
    this->PlayerScore[this->GameTurn] += 1;
}
void DotsAndBoxesGame::ChangeGameTurn()
{
    if(!this->changeTurn)
        return;

    if(this->GameTurn == Player1)
    {
        this->GameTurn = Player2;
        return;
    }

    this->GameTurn = Player1;
}
void DotsAndBoxesGame::AddMoveToStack()
{
    tie(get<0>(this->currentMoveTuple),get<1>(this->currentMoveTuple),get<2>(this->currentMoveTuple),get<3>(this->currentMoveTuple))
    = make_tuple(this->currentMove, this->currentMoveReversed, this->GameTurn, this->PlayerScore);

    this->MovesStack.push(this->currentMoveTuple);
}


void DotsAndBoxesGame::MakeMove()
{
    this->UpdateDrawnEdge();
    this->UpdateDrawnBox();
    this->AddMoveToStack();
    this->ChangeGameTurn();
}
void DotsAndBoxesGame::UndoMove()
{
    this->UndoDrawnEdge();
    this->UndoDrawnBox();

    this->RedoStack.push(this->MovesStack.top());
    this->MovesStack.pop();
    this->GameTurn = get<2>(this->currentMoveTuple);
    this->PlayerScore = this->OnStartGamePlayerScore;

    if(!this->MovesStack.empty())
    {
        this->currentMoveTuple = this->MovesStack.top();
        this->currentMove = get<0>(this->currentMoveTuple);
        this->currentMoveReversed = get<1>(this->currentMoveTuple);
        this->PlayerScore = get<3>(this->currentMoveTuple);
    }
}
void DotsAndBoxesGame::RedoMove()
{
    this->currentMoveTuple = this->RedoStack.top();
    this->RedoStack.pop();
    this->currentMove = get<0>(this->currentMoveTuple);
    this->currentMoveReversed = get<1>(this->currentMoveTuple);
    this->GameTurn = get<2>(this->currentMoveTuple);

    this->MakeMove();
}

void DotsAndBoxesGame::saveToFile(const string &fileName) {
    ofstream outfile(fileName);
    if (outfile.is_open()) {
        outfile << this->GridSize << endl;
        outfile << this->PlayerScore[0] << " " << PlayerScore[1] << endl;
        outfile << this->currentMove<< endl;
        outfile << this->currentMoveReversed<< endl;
        outfile << this->GameTurn << endl;

        outfile << this->NumberOfMovesLeft<<endl;

        for (auto x : this->EdgesMap) {
            outfile << x.first << " " << x.second.drawn;
            if(x.second.drawn) outfile << " " << x.second.EdgePlayer;
            outfile << endl;
        }

        for(auto x : this->Boxes)
        {
            for(auto z : x)
            {
                outfile << z.NLines << " " << z.PlayerClaimed << endl;
            }
        }

        outfile.close();
    }
    else {
        cout << "Unable to save game state to file." << endl;
    }
}

void DotsAndBoxesGame::loadFromFile(const string &fileName) {
    ifstream infile(fileName);
    if (infile.is_open()) {
        infile >> this->GridSize;
        infile >> this->PlayerScore[0] >> this->PlayerScore[1];
        this->OnStartGamePlayerScore = this->PlayerScore;
        infile >> this->currentMove;
        infile >> this->currentMoveReversed;
        int gameTurn;
        infile >> gameTurn;
        if(gameTurn == 0) this->GameTurn = Player1;
        else this->GameTurn = Player2;

        tie(get<0>(this->currentMoveTuple),get<1>(this->currentMoveTuple),get<2>(this->currentMoveTuple),get<3>(this->currentMoveTuple)) = make_tuple(
                this->currentMove, this->currentMoveReversed, this->GameTurn, this->PlayerScore);

        this->ConstructBoxes();
        this->MapEdges();
        this->ConstructGrid();

        infile >> this->NumberOfMovesLeft;

        string edgeKey;
        bool isDrawn;
        int edgePlayer;
        for(auto x : this->EdgesMap)
        {
            infile >> edgeKey >> isDrawn ;
            this->EdgesMap[edgeKey].drawn = isDrawn;

            if(isDrawn)
            {
                infile >> edgePlayer;
                this->EdgesMap[edgeKey].EdgePlayer = edgePlayer;

                Player EdgePlayer;
                if(edgePlayer == 0) EdgePlayer = Player1;
                else EdgePlayer = Player2;

                if(EdgesMap[edgeKey].LineDirection == Edge::Horizontal) this->UpdateHorizontalLineOnGrid(edgeKey, true, EdgePlayer);
                else this->UpdateVerticalLineOnGrid(edgeKey, true, EdgePlayer);
            }
        }

        int Nlines, playerClaimed;
        int Y = int(this->GridSize[0] - '0') - 1;
        int X = int(this->GridSize[1] - '0') - 1;
        for(int y = 0; y < Y; y++)
        {
            for(int x = 0; x < X; x++)
            {
                infile >> Nlines >> playerClaimed;
                this->Boxes[y][x].NLines = Nlines;
                this->Boxes[y][x].PlayerClaimed = playerClaimed;

                Player PlayerClaimed;
                if(playerClaimed == 0) PlayerClaimed = Player1;
                else PlayerClaimed = Player2;

                if(this->Boxes[y][x].CheckIfBoxIsDrawn()) this->UpdateBoxOnGrid(y, x, true, PlayerClaimed);
            }
        }

        infile.close();
    }
    else {
        cout << "Unable to load game state from file." << endl;
    }
}
