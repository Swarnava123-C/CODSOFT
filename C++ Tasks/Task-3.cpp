#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} }; 
char currentPlayer = 'X';

void displayBoard() {
    system("clear"); // Use "cls" for Windows, "clear" for Linux/Mac
    cout << "TIC-TAC-TOE GAME\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) cout << "---|---|---\n";
    }
    cout << endl;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||  
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||  
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // There's still a move left
            }
        }
    }
    return true;  // No moves left, it's a draw
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
    currentPlayer = 'X';
}

void playGame() {
    int move;
    bool gameRunning = true;

    while (gameRunning) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter a number (1-9) to place your mark: ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid input! Choose a number between 1 and 9.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Spot already taken! Choose another.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            gameRunning = false;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw! 🤝\n";
            gameRunning = false;
        } else {
            switchPlayer();
        }
    }
}

int main() {
    char playAgain;
    
    do {
        resetBoard();
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! 🎮\n";
    return 0;
}
//Output:
/*
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9

Player X, enter a number (1-9) to place your mark: 1
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 X | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9

Player O, enter a number (1-9) to place your mark: 2
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 X | O | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9

Player X, enter a number (1-9) to place your mark: 3
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 X | O | X
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9

Player O, enter a number (1-9) to place your mark: 4
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 X | O | X
---|---|---
 O | 5 | 6
---|---|---
 7 | 8 | 9

Player X, enter a number (1-9) to place your mark: 5
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 X | O | X
---|---|---
 O | X | 6
---|---|---
 7 | 8 | 9

Player O, enter a number (1-9) to place your mark: 6
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 X | O | X
---|---|---
 O | X | O
---|---|---
 7 | 8 | 9

Player X, enter a number (1-9) to place your mark: 7
TIC-TAC-TOE GAME
Player 1 (X)  -  Player 2 (O)

 X | O | X
---|---|---
 O | X | O
---|---|---
 X | 8 | 9

Player X wins! 🎉
Do you want to play again? (y/n): n
Thanks for playing! 🎮
*/
