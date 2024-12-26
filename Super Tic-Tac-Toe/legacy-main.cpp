//A text based tic-tac-toe game
//User will play for X and O

#include <iostream>
#include <string>
#include "ttt.cpp"
using namespace std;

tttBoard board;

int main(int argc, char* argv[]){
    cout << endl;
    cout << "Welcome to my text-based tic-tac-toe game!" << endl;
    cout << "──────────────────────────────────────────" << endl;

    char againChar;
    do{
        int turn = 0; //O: -1 | X: 1    Multiply by -1 to flip turn
        cout << endl;
        cout << "Let's play tic-tac-toe!" << endl;
        
        //X or Y start dialogue loop
        char choiceChar;
        do{
            //Get input
            string choice;
            cout << "Who is going to start? (X or O): ";
            getline(cin, choice);;

            //Check input is 1 character
            if(choice.length() != 1){
                cout << "Invalid input, please enter X or O." << endl;
                continue;
            }

            //Convert to char for later usage purposes
            choiceChar = toupper(choice[0]);

            //Check for valid x/y input
            if(choiceChar != 'X' && choiceChar != 'O'){
                cout << "Invalid input, please enter X or O." << endl;
            }

        }while(choiceChar != 'X' && choiceChar != 'O');
            if(choiceChar == 'X'){ turn = 1; }
            if(choiceChar == 'O'){ turn = -1; }

        //Display Initial board
        board.print_board('i');

        //Valid placement loop
        bool game_continue = true;
        do{
            int square;
            int row;
            int col;  
            do{
                //Print turn
                char token;
                if(turn == 1){ token = 'X'; }
                if(turn == -1){ token = 'O'; }

                //Get input
                string position;
                cout << "Where would you like to play, " << token << "? (1-9): ";
                getline(cin, position);

                //Check input is 1 character
                if(position.length() != 1 || !isdigit(position[0]) || position == "0"){
                    cout << "Invalid input, please enter an integer between 1 and 9." << endl;
                    continue;
                }

                //Convert to integer
                square = stoi(position);

                //Check for valid square input
                if(square < 1 || square > 9){
                    cout << "Invalid input, please enter an integer between 1 and 9." << endl;
                    board.print_board('p');
                    continue;
                }

                //Calculations from square choice to get row and column
                row = (square - 1) / 3;
                col = (square - 1) % 3;
                
                //Check if square is occupied or not
                if(board.occupied(row, col)){
                    cout << "This square is filled already, please try again." << endl;
                    board.print_board('p');
                    continue;
                }

            }while(square < 1 || square > 9 || board.occupied(row, col));    

            //Update the board and the turn, and print the board
            board.update_board(row, col, turn);
            turn *= -1;  
            board.print_board('p');
        
            //Check if the game is over
            int result = board.game_over();
            if(result == 1){
                //X won
                cout << "X won!" << endl;
                game_continue = false;
            }else if(result == -1){
                //O won
                cout << "O won!" << endl;
                game_continue = false;
            }else if(result == 0){
                if(board.full_board()){ 
                    //Draw 
                    cout << "It's a draw!" << endl;
                    game_continue = false;
                }
            }
        }while(game_continue);
            board.reset_board();

        //Check if the player wants to play again
        do{
            string again;
            cout << "Would you like to play again? (Y/N): ";
            getline(cin, again);

            //Check input is 1 character
            if(again.length() != 1){
                cout << "Invalid input, please enter Y or N." << endl;
                continue;
            }
            
            //Convert to char
            againChar = toupper(again[0]);

            //Check for valid Y/N input
            if(againChar != 'Y' && againChar != 'N'){
                cout << "Invalid input, please enter Y or N." << endl;
            }
        }while(againChar != 'Y' && againChar != 'N');
        
    }while(againChar == 'Y');

    cout << endl;
    cout << "Thank you for playing!" << endl;
    cout << "──────────────────────────────────────────" << endl;
    
    return 0;
}