# Tic-Tac-Toe Games!
This repository contains 3 Tic-Tac-Toe variants (currently), with more on the way!
Each variant was built using C++ in VSCode and is designed to run in the terminal of whatever programming application or IDE you use.

## Features:
### Released:
- Basic Tic-Tac-Toe: The original Tic-Tac-Toe
- Super Tic-Tac-Toe: Play with 9 Tic-Tac-Toe Boards within each square of a Super Tic-Tac-Toe Board!
- Infinite Tic-Tac-Toe: Tic-Tac-Toe with a maximum of 3 Xs and 3 Os!

### Coming Soon:
- Tic-Tac-Toe vs. Computer: Play against a computer opponent that always knows the best move!
- Tic-Tac-Toe Solved: A database of all the possible game states of Tic-Tac-Toe, optimized for symmetry and reflection.
- Super Tic-Tac-Toe vs. AI: Play against an AI in Super Tic-Tac-Toe!

## Installation Instructions:
Fork the code, open the folder of the game you want to play in the application of your choice (make sure it is in a C++ environment), and then run the following commands:
  - g++ main.cpp
  - ./a.out

For example, to play Super Tic-Tac-Toe, open the "Super Tic-Tac-Toe" folder in the integrated terminal and run the above commands.

## Game Rules:
### Super Tic-Tac-Toe:
  - In this game, there is a Tic-Tac-Toe game inside each square of the giant Tic-Tac-Toe game
  - Winning on the smaller boards will mark the corresponding square on the big board with the player who won
  - Tying will result in a "-" being placed, indicating a draw
  - The square that the previous player plays will force the next player to play in the corresponding mini board on the large board
    - (Ex: If I play the top left square on my move, my opponent will be forced to play in the top left board of the big board)
  - If the forced board is completed, the next player can play anywhere.
  - Play continues until a winner or a draw is found on the big board.

### Infinite Tic-Tac-Toe:
  - In this game, the maximum number of Xs and Os is 3 each.
    - (Ex: If there are already 3 Xs on the board, upon placement of the 4th, the oldest X placed will disappear)
  - Play continues until X or O wins. 
