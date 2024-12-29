#include <iostream>
#include <string>
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
        if(miniBoards[metaR][metaC].occupied(miniR, miniC)){
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
                cout << "X won on board: " << square << endl;
            }else if(result == -1){
                //O won
                cout << "O won on board: " << square << endl;
            }else if(result == 0){
                //Draw 
                cout << "It's a draw on board: " << square << endl;
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

    void printMetaBoard(){
        cout << "                Game Board" << endl;
        cout << endl;
        cout << " X | O | X   ║   O | X |    ║     | X | O"     << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───"    << endl;
        cout << "   | X |     ║   X | O | X  ║   O |   |   "    << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───"    << endl;
        cout << " O |   | O   ║   X |   |    ║   O | X |   "    << endl;
        cout << "             ║              ║"                 << endl;
        cout << "═════════════╬══════════════╬═════════════           Meta Board" << endl;
        cout << "             ║              ║                   ╔═════╦═════╦═════╗" << endl;
        cout << "   | O | X   ║     | X | O  ║   O |   |         ║  X  ║     ║     ║" << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───      ╠═════╬═════╬═════╣" << endl;
        cout << " O | X |     ║   O | X |    ║   X | O |         ║     ║  O  ║     ║" << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───      ╠═════╬═════╬═════╣" << endl;
        cout << "   |   |     ║     |   | X  ║     |   |         ║     ║     ║  X  ║" << endl;
        cout << "             ║              ║                   ╚═════╩═════╩═════╝" << endl;
        cout << "═════════════╬══════════════╬═════════════"    << endl;
        cout << "             ║              ║"                 << endl;
        cout << " X |   | O   ║   X | O | X  ║   O | X | O"     << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───"    << endl;
        cout << "   | X | O   ║   O | X |    ║     | X |   "    << endl;
        cout << "───┼───┼───  ║  ───┼───┼─── ║  ───┼───┼───"    << endl;
        cout << "   |   |     ║     |   |    ║     |   |   "    << endl;
    }
};