#include <iostream>
#include <string>
#include "ttt.cpp"
using namespace std;

struct stttBoard{
    //Variables
    //----------------------
    tttBoard miniBoards[3][3];
    tttBoard metaBoard;

    //Functions
    //----------------------
    void makeMove(int metaR, int metaC, int miniR, int miniC, int turn){ 
        miniBoards[metaR][metaC].update_board(miniR, miniC, turn);
    }

    int metaGameOver(){
        return metaBoard.game_over();
    }

    bool miniBoardDone(){

    }

    bool metaBoardFull(){}

    void resetMetaBoard(){}

    void printMetaBoard(){}
};