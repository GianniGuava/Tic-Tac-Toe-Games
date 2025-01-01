#include <iostream>
#include <string>
#include <sstream>
#include "ttt.cpp"
using namespace std;

struct stttBoard{
    //Variables
    //----------------------
    tttBoard miniBoards[3][3];
    tttBoard metaBoard;
    bool completedBoards[3][3] = {false};

    //Functions
    //----------------------
    bool makeMove(int metaR, int metaC, int miniR, int miniC, int turn){ 
        if(!miniBoards[metaR][metaC].occupied(miniR, miniC)){
            miniBoards[metaR][metaC].update_board(miniR, miniC, turn);
            return true;
        }
        return false;
    }

    int metaGameOver(){
        return metaBoard.game_over();
    }

    void miniBoardDone(int row, int col){
        int result = miniBoards[row][col].game_over();
        if(result != 0 || miniBoards[row][col].full_board()){
            //Update completed boards and the meta board
            completedBoards[row][col] = true;
            metaBoard.update_board(row, col, result);

            //Print who won on a board
            int square = (row * 3) + col + 1;
            if(result == 1){
                //X won
                cout << "[Result]: X wins on board " << square << "!\n";
            }else if(result == -1){
                //O won
                cout << "[Result]: O wins on board " << square << "!\n";
            }else if(result == 0){
                //Draw 
                cout << "[Result]: It's a draw on board " << square << "!\n";
            }
        }
    }

    bool metaBoardFull(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(completedBoards[i][j] == false){ return false; }
            }
        }
        return true;
    }

    void resetMetaBoard(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                miniBoards[i][j].reset_board();
                completedBoards[i][j] = false;
            }
        }
        metaBoard.reset_board();
    }

    //Print Functions
    //----------------------
    string gameLineMini(char arr[9][9], int i){
        stringstream ss;
        ss << " " << arr[i][0] << " | " << arr[i][1] << " | " << arr[i][2] << "   ║   "
                  << arr[i][3] << " | " << arr[i][4] << " | " << arr[i][5] << "  ║   "
                  << arr[i][6] << " | " << arr[i][7] << " | " << arr[i][8];
        return ss.str();
    }

    string gameLineMeta(char arr[3][3], int i){
        stringstream ss;
        ss << "       ║  " << arr[i][0] << "  ║  "
                          << arr[i][1] << "  ║  " 
                          << arr[i][2] << "  ║  \n";
        return ss.str();
    }

    void printMetaBoardI(){
        stringstream ss;
        ss << 
            "\n"
            "Here's the layout of the board for selecting your moves on the Game Board:\n"
            "\n"
            " 1 | 1 | 1   ║   2 | 2 | 2  ║   3 | 3 | 3 \n"
            "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n"
            " 1 | 1 | 1   ║   2 | 2 | 2  ║   3 | 3 | 3 \n"
            "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n"
            " 1 | 1 | 1   ║   2 | 2 | 2  ║   3 | 3 | 3 \n"
            "             ║              ║             \n"
            "═════════════╬══════════════╬═════════════\n"
            "             ║              ║             \n"
            " 4 | 4 │ 4   ║   5 | 5 | 5  ║   6 | 6 | 6 \n"
            "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n"
            " 4 | 4 | 4   ║   5 | 5 | 5  ║   6 | 6 | 6 \n"
            "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n"
            " 4 | 4 | 4   ║   5 | 5 | 5  ║   6 | 6 | 6 \n"
            "             ║              ║             \n"
            "═════════════╬══════════════╬═════════════\n"
            "             ║              ║             \n"
            " 7 | 7 | 7   ║   8 | 8 | 8  ║   9 | 9 | 9 \n"
            "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n"
            " 7 | 7 | 7   ║   8 | 8 | 8  ║   9 | 9 | 9 \n"
            "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n"
            " 7 | 7 | 7   ║   8 | 8 | 8  ║   9 | 9 | 9 \n"
            "\n";
            cout << ss.str();
    }

    void printMetaBoard(){
        //Variables
        char mini[9][9];
        char meta[3][3];

        //Initialize board variables for printing
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        int token = miniBoards[i][j].game_board[k][l];
                        int x = i * 3 + k, y = j * 3 + l;
                        if      (token == -1){ mini[x][y] = 'O'; }
                        else if (token == 1) { mini[x][y] = 'X'; }
                        else    { mini[x][y] = ' '; }
                    }
                }
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int token = metaBoard.game_board[i][j];
                if      (token == -1){ meta[i][j] = 'O'; }
                else if (token == 1) { meta[i][j] = 'X'; }
                else if (token == 0 && completedBoards[i][j] == true) { meta[i][j] = '-'; }
                else    { meta[i][j] = ' '; }
            }
        }

        cout << "───────────────────────────────────────────────────────────────────\n";
        cout << "                Game Board\n";
        cout << endl;
        cout << gameLineMini(mini, 0) << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n";
        cout << gameLineMini(mini, 1)    << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n";
        cout << gameLineMini(mini, 2)    << endl;
        cout << "             ║              ║"                 << endl;
        cout << "═════════════╬══════════════╬═════════════           Meta Board\n";
        cout << "             ║              ║                   ╔═════╦═════╦═════╗\n";
        cout << gameLineMini(mini, 3) << gameLineMeta(meta, 0);
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───      ╠═════╬═════╬═════╣\n";
        cout << gameLineMini(mini, 4) << gameLineMeta(meta, 1);
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───      ╠═════╬═════╬═════╣\n";
        cout << gameLineMini(mini, 5) << gameLineMeta(meta, 2);
        cout << "             ║              ║                   ╚═════╩═════╩═════╝\n";
        cout << "═════════════╬══════════════╬═════════════\n";
        cout << "             ║              ║\n";
        cout << gameLineMini(mini, 6)    << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n";
        cout << gameLineMini(mini, 7)    << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───\n";
        cout << gameLineMini(mini, 8)    << endl;
        cout << "───────────────────────────────────────────────────────────────────\n";
        cout << endl;
    }
};