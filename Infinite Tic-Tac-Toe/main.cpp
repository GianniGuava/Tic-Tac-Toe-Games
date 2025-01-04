#include <iostream>
#include <string>
#include "ittt.cpp"
using namespace std;

itttBoard board;

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
             << "There can only be 3 X's and 3 O's on the board at any given time.\n"
             << "When placing the 4th X or O, the oldest one placed will disappear.\n"
             << "Play until you get three in a row!\n";
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

        //Display Initial board
        board.print_board('i', 0);

        //Valid placement loop
        bool game_continue = true;
        do{
            int square;
            int row;
            int col;  
            do{
                //Printable X and O
                char token;
                if(turn == 1){ token = 'X'; }
                if(turn == -1){ token = 'O'; }

                //1. Ask user for square
                string position;
                cout << "Player [" << token << "], it's your turn! Where would you like to play, " << token << "? (1-9): ";
                getline(cin, position);

                //2. Check input
                //Check input is 1 character
                if(position.length() != 1 || !isdigit(position[0]) || position == "0"){
                    cout << "[Error]: Please enter a valid number (1-9).\n";
                    continue;
                }

                //Convert to integer
                square = stoi(position);

                //Check for valid square input
                if(square < 1 || square > 9){
                    cout << "[Error]: Please enter a valid number (1-9).\n";
                    board.print_board('p', 0);
                    continue;
                }

                //Calculations from square choice to get row and column
                row = (square - 1) / 3;
                col = (square - 1) % 3;
                
                //Check if square is occupied or not
                if(board.occupied(row, col)){
                    cout << "[Error]: Square already filled. Please pick a different square.\n";
                    board.print_board('p', 0);
                    continue;
                }

            }while(square < 1 || square > 9 || board.occupied(row, col));    

            //3. Update Deques
            if(turn == 1){ board.xs.push_front(make_pair(row, col)); }
            else if (turn == -1){ board.os.push_front(make_pair(row, col)); }

            //4. Update Board
            board.update_board(row, col, turn);

            //5. Update Turn
            turn *= -1;  

            //6. Update meta board for fading token and print
            if(turn == 1){ board.print_board('p', 1); }
            else if(turn == -1){ board.print_board('p', -1); }
            
            //8. Check Win
            int result = board.game_over();
            if(result == 1){
                //X won
                cout << "\n*********************************";
                cout << "*           X WINS!             *\n";
                cout << "\n*********************************";
                game_continue = false;
            }else if(result == -1){
                //O won
                cout << "\n*********************************";
                cout << "*           O WINS!             *\n";
                cout << "\n*********************************";
                game_continue = false;
            }else{
                //9. Delete old token from board and output fade warning
                if(turn == 1 && board.xs.size() == 3){
                    int xRow = board.xs.back().first;
                    int xCol = board.xs.back().second;
                    board.update_board(xRow, xCol, 0);
                    cout << "Player [X], your X on square [" << (xRow * 3 + xCol) << "] will disappear.\n";
                    board.xs.pop_back();
                }else if(turn == -1 && board.os.size() == 3){
                    int oRow = board.os.back().first;
                    int oCol = board.os.back().second;
                    board.update_board(oRow, oCol, 0);
                    cout << "Player [O], your O on square [" << (oRow * 3 + oCol) << "] will disappear.\n";
                    board.os.pop_back();
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