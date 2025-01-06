#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct board{
    char squares[9];

    //Constructor to create a board with a default start
    board(){ fill(squares, squares + 9, '-'); }

    //Constructor to create a game board given a string
    board(string game){ for(int i : game){ squares[i] = game[i]; } }
    
    void display() const {
        for(int i = 0; i < 9; i++){ cout << squares[i]; }
        cout << endl;
    }

    string toString() const { return string(squares, squares + 9); }

    void toInt(int arr[]) const { 
        for(int i = 0; i < 9; i++){
            if(squares[i] == 'X'){ arr[i] = 1; }
            else if(squares[i] == 'O'){ arr[i] = -1; }
            else{ arr[i] = 0; } //squares[i] == '-'
        }
    }

    bool gameOver() const {
        //Returns:      true if winner or tie, false for game continue
        //Win Totals:   -3 = O, 3 = X, [-2, 2] = tie

        int arr[9];
        toInt(arr);

        //Diagnoal win totals 
        int diagRL = arr[0] + arr[4]+ arr[8];
        int diagLR = arr[2] + arr[4]+ arr[6];
        //Column win totals
        int colL = arr[0] + arr[3]+ arr[6];
        int colM = arr[1] + arr[4]+ arr[7];
        int colR = arr[2] + arr[5]+ arr[8];

        //Row win totals
        int rowT = arr[0] + arr[1]+ arr[2];
        int rowM = arr[3] + arr[4]+ arr[5];
        int rowB = arr[6] + arr[7]+ arr[8];

        int totals_array[] = {diagRL, diagLR, colL, colM, colR, rowT, rowM, rowB};
    
        //There is a winner
        for(int total : totals_array){ if(total == 3 || total == -3){ return true; } }

        //The game isn't finished b/c there is an empty square.
        for(int i = 0; i < 9; i++){ if(squares[i] == '-'){ return false; } }

        //There is a draw b/c the board is full
        return true;
    }

    int gameOverMM() const {
        //Returns:      true if winner or tie, false for game continue
        //Win Totals:   -3 = O, 3 = X, [-2, 2] = tie

        int arr[9];
        toInt(arr);

        //Diagnoal win totals 
        int diagRL = arr[0] + arr[4]+ arr[8];
        int diagLR = arr[2] + arr[4]+ arr[6];
        //Column win totals
        int colL = arr[0] + arr[3]+ arr[6];
        int colM = arr[1] + arr[4]+ arr[7];
        int colR = arr[2] + arr[5]+ arr[8];

        //Row win totals
        int rowT = arr[0] + arr[1]+ arr[2];
        int rowM = arr[3] + arr[4]+ arr[5];
        int rowB = arr[6] + arr[7]+ arr[8];

        int totals_array[] = {diagRL, diagLR, colL, colM, colR, rowT, rowM, rowB};
    
        for(int total : totals_array){
            //Returns:      -1 = O, 1 = X, 0 = tie
            //Win Totals:   -3 = O, 3 = X, [-2, 2] = tie
            if(total == 3){ return 1; }
            if(total == -3){ return -1; }
        }

        return 0;
    }
};