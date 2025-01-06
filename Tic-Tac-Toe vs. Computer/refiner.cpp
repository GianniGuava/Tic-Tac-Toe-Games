//This is the file that will refine the raw data file and remove symmetrical and mirrored game states

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include "board.cpp"
using namespace std;

vector<string> createSymmetries(const string &board){
    vector<string> symmetries(9);

    //Original board
    symmetries[0] = board;

    //90 rotation
    symmetries[1] = {board[6], board[3], board[0],
                     board[7], board[4], board[1],
                     board[8], board[5], board[2]};

    //180 rotation
    symmetries[2] = {board[8], board[7], board[6],
                     board[5], board[4], board[3],
                     board[2], board[1], board[0]};

    //270 rotation
    symmetries[3] = {board[2], board[5], board[8],
                     board[1], board[4], board[7],
                     board[0], board[3], board[6]};

    //Horizontal reflection
    symmetries[4] = {board[2], board[1], board[0],
                     board[5], board[4], board[3],
                     board[8], board[7], board[6]};

    //Vertical reflection
    symmetries[5] = {board[6], board[7], board[8],
                     board[3], board[4], board[5],
                     board[0], board[1], board[2]};

    //Diagonal reflection (\)
    symmetries[6] = {board[0], board[3], board[6],
                     board[1], board[4], board[7],
                     board[2], board[5], board[8]};

    //Diagonal reflection (/)
    symmetries[7] = {board[8], board[5], board[2],
                     board[7], board[4], board[1],
                     board[6], board[3], board[0]};

    //Mirrored Xs and Os
    symmetries[8] = board;
    for(char square : board){
        if(square == 'X'){ symmetries[square] = 'O'; }
        if(square == 'O'){ symmetries[square] = 'X'; }
    }

    return symmetries;
}

//Double check for valid game state
bool isValid(const string &board){
    int xs = 0, os = 0;
    for(char c : board){
        if(c == 'X'){ xs++; }
        else if(c == 'O'){ os; }
    }

    //The count of Xs and Os are either the same or different by 1
    if(xs == os || xs == os + 1 || xs + 1 == os){ return true; }
    else{ return false; }
}

//Minimax algorithm
int miniMax(string game){
    board board(game);
}

int main(int argc, char* argv[]){
    //Open the CSV file for reading
    ifstream iFile("rawGameStates.csv");
    if (!iFile.is_open()) {
        cerr << "Error: Could not open file for writing!\n";
        return 1;
    }

    //Create a new CSV file for writing
    ofstream oFile("gameStates.csv");
        if (!oFile.is_open()) {
        cerr << "Error: Could not open file for writing!\n";
        return 1;
    }

    oFile << "Refined game states:\n";

    string line;
    unordered_map<string, int> baseCases;
    while(getline(iFile, line)){
        if(line == "Boards:" || line == "Xs:" || line == "Os:"){ continue; }

        vector<string> symmetries = createSymmetries(line);
        string baseCase = *min_element(symmetries.begin(), symmetries.end()); 

        if(isValid(baseCase)){
            if(baseCases.find(baseCase) == baseCases.end()){
                int bestMove = miniMax(baseCase);
                baseCases[baseCase] = bestMove;
                oFile << baseCase << bestMove << endl;
            }
        }
    }

    iFile.close();
    oFile.close();
    return 0;
}