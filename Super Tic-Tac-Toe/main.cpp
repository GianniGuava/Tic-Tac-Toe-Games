//A text based super tic-tac-toe game
//User will play for X and O

#include <iostream>
#include <string>
#include "sttt.cpp"
using namespace std;

stttBoard board;

int main(int argc, char* argv[]){
    //Intro
    cout << "\nWelcome to my text-based Super Tic-Tac-Toe game!\n";
    cout << "──────────────────────────────────────────\n";

    //Loop to determine X or O start
    char againChar;
    do{
        int turn = 0; //O: -1 | X: 1    Multiply by -1 to flip turn
        cout << "\nLet's play Super Tic-Tac-Toe!\n" ;

        cout << "\nThe rules are as follows: \n"
             << "The number of the square you play will force the board that your opponent\n" 
             << "will have to play unless the board picked is finished. The game continues\n" 
             << "until the meta board is won or comes to a draw. Each mini board that is won\n"
             << "or that comes to a draw will be reflected on the meta board.\n";
        cout << endl;
        
        //X or Y start dialogue loop
        char choiceChar;
        do{
            //Get input
            string choice;
            cout << "Who is going to start? (X or O): ";
            getline(cin, choice);;

            //Check input is 1 character
            if(choice.length() != 1){
                cout << "[Error]: Please enter X or O.\n";
                continue;
            }

            //Convert to char for later usage purposes
            choiceChar = toupper(choice[0]);

            //Check for valid x/y input
            if(choiceChar != 'X' && choiceChar != 'O'){
                cout << "[Error]: Please enter X or O.\n";
            }

        }while(choiceChar != 'X' && choiceChar != 'O');
            if(choiceChar == 'X'){ turn = 1; }
            if(choiceChar == 'O'){ turn = -1; }

        //Print initial board
        board.printMetaBoardI();
        board.miniBoards[0][0].print_board('i');

        //While loop to run game
        bool game_continue = true;
        int boardToBePlayed = 0;
        do{
            //Print game state
            board.printMetaBoard();

            //To print whose turn it is
            char token;
            if(turn == 1){ token = 'X'; }
            if(turn == -1){ token = 'O'; }

            //Calculates the miniboard
            int boardRow = (boardToBePlayed - 1) / 3;
            int boardCol = (boardToBePlayed - 1) % 3;
            
            //Valid miniboard placement loop
            string userBoard;
            if(boardToBePlayed == 0){ 
                //If user can play anywhere, select a board
                cout << "Player [" << token << "], it's your turn! You can play on any unfinished board." << endl;
                while(true){
                    //Prompt user for board
                    cout << "What board would you like to play on, ["<< token << "]?: ";
                    getline(cin, userBoard);

                    //Check input is a valid digit
                    if(userBoard.length() != 1 || !isdigit(userBoard[0]) || userBoard == "0"){
                        cout << "[Error]: Please enter a valid number (1-9).\n";
                        continue;
                    }

                    //Convert to integer
                    boardToBePlayed = stoi(userBoard);

                    //Calculates the new miniboard
                    boardRow = (boardToBePlayed - 1) / 3;
                    boardCol = (boardToBePlayed - 1) % 3;

                    //Check if board is finished
                    if(board.completedBoards[boardRow][boardCol] == true){
                        cout << "[Error]: Board has been completed. Please play in a different board.\n";
                        boardToBePlayed = 0;
                        continue;
                    }
                    break;
                }
            }else{
                //Tell the user where they can play
                cout << "Player [" << token << "], you can play on board: " << boardToBePlayed << endl;
            }

            //Valid square placement loop
            string userSquare;
            while(true){
                //Print mini board
                board.miniBoards[boardRow][boardCol].print_board('p');

                //Select new square
                cout << "What square would you like to play in that board, ["<< token << "]?: ";
                getline(cin, userSquare);

                //Check input is a valid digit
                if(userSquare.length() != 1 || !isdigit(userSquare[0]) || userSquare == "0"){
                    cout << "[Error]: Please enter a valid number (1-9).\n";
                    continue;
                }

                //Convert to integer
                int squareToBePlayed = stoi(userSquare);

                //Calculates the square
                int squareRow = (squareToBePlayed - 1) / 3;
                int squareCol = (squareToBePlayed - 1) % 3;

                //Attempt to make the move
                //If the square is occupied, reprompt
                if(!board.makeMove(boardRow, boardCol, squareRow, squareCol, turn)){
                    cout << "[Error]: Square already filled. Please pick a different square.\n";
                    board.printMetaBoard();
                    continue;
                }else{ 
                    //If miniboard hits a gameover, 
                    //add it to the vector of finished boards and update metaboard
                    board.miniBoardDone(boardRow, boardCol);
                    if(board.completedBoards[squareRow][squareCol] == false){
                        boardToBePlayed = squareToBePlayed;
                    }else{
                        boardToBePlayed = 0;
                    }
                    turn *= -1;
                    break;
                }
            }
            //Print out winner of game
            if(board.metaBoardFull() || board.metaGameOver() != 0){
                int winner = board.metaGameOver();
                cout << "\n*********************************";
                if(winner == 1){
                    //X won
                    cout << "*           X WINS!             *\n";
                    game_continue = false;
                }else if(winner == -1){
                    //O won
                    cout << "*           O WINS!             *\n";
                    game_continue = false;
                }else if(winner == 0){
                    //Draw 
                    cout << "*           A DRAW!             *\n";
                    game_continue = false;
                }
                cout << "*********************************\n";
            }
        }while(game_continue);
        board.resetMetaBoard();

        //Check if the player wants to play again
        do{
            string again;
            cout << "Would you like to play again? (Y/N): ";
            getline(cin, again);

            //Check input is 1 character
            if(again.length() != 1){
                cout << "[Error]: Please enter Y or N.\n";
                continue;
            }
            
            //Convert to char
            againChar = toupper(again[0]);

            //Check for valid Y/N input
            if(againChar != 'Y' && againChar != 'N'){
                cout << "[Error]: Please enter Y or N.\n";
            }
        }while(againChar != 'Y' && againChar != 'N');   
    if(againChar == 'Y'){ cout << "The game has been reset. Let's play again!\n";}
    }while(againChar == 'Y');

    cout << "\nThank you for playing!\n";
    cout << "──────────────────────────────────────────\n";
    
    return 0;
}