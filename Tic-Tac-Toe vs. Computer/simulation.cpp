//This file will contain the struct and code to run a simulated game of tic-tac-toe and find all the possible game states and save it to a csv file

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "board.cpp"
using namespace std;

void simulation(board game, bool xTurn, ofstream &file){
    //Base case: Game over
    if(game.gameOver()){
        file << game.toString() << endl;
        return;
    }

    //Recursive case: Generate all possible game states
    for(int i = 0; i < 9; i++){
        if(game.squares[i] == '-'){
            //Place X
            if(xTurn){ game.squares[i] = 'X'; }
            
            //Place O
            else{ game.squares[i] = 'O'; }

            //Recursive call
            simulation(game, !xTurn, file);

            //Reset square
            game.squares[i] = '-';
        }
    }
}

int main(int argc, char* argv[]){
    //Open the CSV file for writing
    ofstream file("rawGameStates.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not open file for writing!\n";
        return 1;
    }

    file << "Boards:\n";

    board board;
    //If X starts
    file << "Xs:\n";
    simulation(board, true, file);
    //If O starts. Should be a mirrored set
    file << "Os:\n";
    simulation(board, false, file);

    file.close();

    return 0;
}