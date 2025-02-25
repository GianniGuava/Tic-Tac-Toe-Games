#include <iostream>
#include <string>
#include <deque>
#include <utility>
using namespace std;

struct itttBoard{
    // -1 = O | 1 = X | 0 = null

    //Variables
    //----------------------
    int game_board[3][3]={
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    deque<pair<int, int>> xs;
    deque<pair<int, int>> os;

    //Functions
    //----------------------
    void update_board(int r, int c, int turn){ game_board[r][c] = turn; }

        int game_over(){
        //Returns:      -1 = O, 1 = X
        //Win Totals:   -3 = O, 3 = X

        //Diagnoal win totals 
        int diagRL = game_board[0][0] + game_board[1][1] + game_board[2][2];
        int diagLR = game_board[0][2] + game_board[1][1] + game_board[2][0];

        //Column win totals
        int colL = game_board[0][0] + game_board[1][0] + game_board[2][0];
        int colM = game_board[0][1] + game_board[1][1] + game_board[2][1];
        int colR = game_board[0][2] + game_board[1][2] + game_board[2][2];

        //Row win totals
        int rowT = game_board[0][0] + game_board[0][1] + game_board[0][2];
        int rowM = game_board[1][0] + game_board[1][1] + game_board[1][2];
        int rowB = game_board[2][0] + game_board[2][1] + game_board[2][2];

        int totals_array[] = {diagRL, diagLR, colL, colM, colR, rowT, rowM, rowB};

        for(int total : totals_array){
            //Returns:      -1 = O, 1 = X
            //Win Totals:   -3 = O, 3 = X
            if(total == 3){ return 1; }
            if(total == -3){ return -1; }
        }

        return 0;
    }

    bool occupied(int row, int col){
        if(game_board[row][col] != 0){ return true; } 
        return false;
    }

    void reset_board(){
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                game_board[r][c] = 0;
            }
        }   
        xs.clear();
        os.clear();
    }

    void print_board(char type, int turn){
        //Initial board
        cout << endl;
        if (type == 'i'){
            cout << "Here's the layout of the board for selecting your moves on the Board:\n";
            cout << endl;
            for(int i = 1; i < 10; i++){
                cout << " " << i << " ";
                if(i % 3 != 0){ cout << "│"; }
                if(i % 3 == 0 && i < 9){ cout << endl; }
                if(i % 3 == 0 && i < 9){ cout << "───┼───┼───\n"; }
            }
        cout << endl;
        }

        //Board in play
        if(type == 'p'){
            cout << "This is the current state of the board:\n";
            cout << endl;
            for(int r = 0; r < 3; r++){
                for(int c = 0; c < 3; c++){
                    string token = " ";
                    if(game_board[r][c] == 1){
                        int xRow = xs.back().first;
                        int xCol = xs.back().second; 
                        if(turn == 1 && (xRow == r && xCol == c) && (xs.size() == 3)){ token = "×"; }
                        else{ token = "X";  }
                        }
                    if(game_board[r][c] == -1){
                        int oRow = os.back().first;
                        int oCol = os.back().second; 
                        if(turn == -1 && (oRow == r && oCol == c) && (os.size() == 3)){ token = "◌"; }
                        else{ token = "O";  }
                        }
                    if(game_board[r][c] == 0){ token = " "; }

                    cout << " " << token << " ";
                    if(c != 2){ cout << "│"; }
                    if(c == 2){ cout << endl; } 
                }
                if(r != 2){ cout << "───┼───┼───\n";}
            }
        }
        cout << endl;
    }
};