# Tic-Tac-Toe Games!
This repository contains 3 Tic-Tac-Toe variants (currently), with more on the way!
Each variant was built using C++ in VSCode and is designed to run in the terminal of whatever programming application or IDE you use.

Of the currently released variants, playing for X and O requires user input. Bring a friend or play against yourself!

## Features:
### Released:
- [**Basic Tic-Tac-Toe:**](./Basic%20text-based%20Tic-Tac-Toe) The original Tic-Tac-Toe
- [**Infinite Tic-Tac-Toe:**](./Infinite%20Tic-Tac-Toe) Tic-Tac-Toe with a maximum of 3 Xs and 3 Os!
- [**Super Tic-Tac-Toe:**](./Super%20Tic-Tac-Toe) Play with 9 Tic-Tac-Toe Boards within each square of a Super Tic-Tac-Toe Board!


### Coming Soon:
- **Tic-Tac-Toe Solved:** A database of all the possible game states of Tic-Tac-Toe, optimized for symmetry and reflection.
- **Tic-Tac-Toe vs. Computer:** Play against a computer opponent that always knows the best move!
- **Super Tic-Tac-Toe vs. AI:** Play against an AI in Super Tic-Tac-Toe!

## Installation Instructions:
***Note** This project was made and designed in **VSCode**. Follow the steps below to start playing:

1. **Clone the Repository:**
  - Create the file you want to clone your repository in.
  - Open the file in Git Bash and run the following command:
    ```bash
    git clone https://github.com/GianniGuava/Tic-Tac-Toe-Games.git
    ```
  - Or fork the code from this website.
    
2. **Set Up Your Environment:**
  - **If you're on Windows,** download and install **VSCode** and a **C++ Compiler** by following this video tutorial provided by my university:
    - [HOW TO SET UP A C++ PROGRAMMING ENVIRONMENT ON WINDOWS - Shmeowlex](https://www.youtube.com/watch?v=z9pl-0shPTs)
    - *(This tutorial was created by my university faculty and ensures that your environment is properly configured for C++.)*
  - **If you're on MacOS,** 
   
3. **Open the Folder in VSCode:**
   - Right-click on the "Tic-Tac-Toe Games" folder, and select "Open with Code".
   - Alternatively, you can open VSCode and add the "Tic-Tac-Toe Games" folder to your workspace.
   - Right-click on the folder of the variant you want to play and select "Open in Integrated Terminal".
     
5. **Compile and Run the Game:**
  - Compile the game.
     ```bash
     g++ main.cpp
     ```
  - Run the game.
     ```bash
     ./a.out
     ```
6. **Have Fun Playing!**
   - Follow the in-terminal prompts to play against yourself or a friend!

## Game Rules:
### Infinite Tic-Tac-Toe:
  - In this game, the maximum number of Xs and Os is 3 each.
    - *(Ex: Placing a 4th X removes the oldest X)*
  - Play continues until X or O wins.

### Super Tic-Tac-Toe:
  - In this game, there is a Tic-Tac-Toe game inside each square of the giant Tic-Tac-Toe game.
  - Winning on a smaller board marks the corresponding square with the winner's symbol on the big board.
  - Tying will result in a "-" being placed, indicating a draw.
  - The square chosen in the last move determines the next mini-board to play in.
    - *(Ex: If I play the top left square on my move, my opponent will be forced to play in the top left board of the big board)*
  - If the forced board is complete, the next player can play anywhere.
  - Play continues until a winner or a draw is on the big board.

## License
This project is licensed under the MIT License. See the [License](LICENSE.txt) file for details.
