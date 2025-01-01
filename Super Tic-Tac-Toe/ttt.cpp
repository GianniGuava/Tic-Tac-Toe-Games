#include <iostream>
#include <string>
using namespace std;

struct tttBoard{
    // -1 = O | 1 = X | 0 = null

    //Variables
    //----------------------
    int game_board[3][3]={
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    //Functions
    //----------------------
    void update_board(int r, int c, int turn){ game_board[r][c] = turn; }

    int game_over(){
        //Returns:      -1 = O, 1 = X, 0 = tie
        //Win Totals:   -3 = O, 3 = X, [-2, 2] = tie

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
            //Returns:      -1 = O, 1 = X, 0 = tie
            //Win Totals:   -3 = O, 3 = X, [-2, 2] = tie
            if(total == 3){ return 1; }
            if(total == -3){ return -1; }
        }

        return 0;
    }

    bool occupied(int row, int col){
        if(game_board[row][col] != 0){ return true; } 
        return false;
    }

    bool full_board(){
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                if(!occupied(r, c)){ return false; }
            }
        }   
        return true;
    }

    void reset_board(){
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                game_board[r][c] = 0;
            }
        }   
    }

    void print_board(char type){
        //Initial board
        cout << endl;
        if (type == 'i'){
            cout << "Here's the layout of the board for selecting your moves on the Mini Board:\n";
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
                    char token = ' ';
                    if(game_board[r][c] == 1){ token = 'X'; }
                    if(game_board[r][c] == -1){ token = 'O'; }
                    if(game_board[r][c] == 0){ token = ' '; }

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