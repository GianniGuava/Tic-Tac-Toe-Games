//A text based tic-tac-toe game
//User will play for X and O

#include <iostream>
#include <string>
using namespace std;

// -1 = O
//  0 = null
//  1 = X
//Comments: Could have created a class for future proofing, but will keep it simple here
int game_board[3][3]={
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void update_board(int r, int c, int turn){
    game_board[r][c] = turn;
}

int check_win(int total){
    //Returns:      -1 = O, 1 = X, 0 = tie
    //Win Totals:   -3 = O, 3 = X, [-2, 2] = tie
    if(total == 3){ return 1; }
    if(total == -3){ return -1; }
    return 0;
}

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
        int result = check_win(total);
        if (result != 0) { return result; }
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
        cout << "Here's the layout of the board for selecting your moves:" << endl;
        cout << endl;
        for(int i = 1; i < 10; i++){
            cout << " " << i << " ";
            if(i % 3 != 0){ cout << "│"; }
            if(i % 3 == 0 && i < 9){ cout << endl; }
            if(i % 3 == 0 && i < 9){ cout << "───┼───┼───" << endl; }
        }
        cout << endl;
    }

    //Board in play
    if(type == 'p'){
        cout << "This is the current state of the board:" << endl;
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
            if(r != 2){ cout << "───┼───┼───" << endl;}
        }
    }
    cout << endl;
}

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
        print_board('i');

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
                    print_board('p');
                    continue;
                }

                //Calculations from square choice to get row and column
                row = (square - 1) / 3;
                col = (square - 1) % 3;
                
                //Check if square is occupied or not
                if(occupied(row, col)){
                    cout << "This square is filled already, please try again." << endl;
                    print_board('p');
                    continue;
                }

            }while(square < 1 || square > 9 || occupied(row, col));    

            //Update the board and the turn, and print the board
            update_board(row, col, turn);
            turn *= -1;  
            print_board('p');
        
            //Check if the game is over
            int result = game_over();
            if(result == 1){
                //X won
                cout << "X won!" << endl;
                game_continue = false;
            }else if(result == -1){
                //O won
                cout << "O won!" << endl;
                game_continue = false;
            }else if(result == 0){
                if(full_board()){ 
                    //Draw 
                    cout << "It's a draw!" << endl;
                    game_continue = false;
                }
            }
        }while(game_continue);
            reset_board();

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