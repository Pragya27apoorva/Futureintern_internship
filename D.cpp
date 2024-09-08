#include <iostream>

using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        if (i < 2) cout << "\n---|---|---\n";
    }
    cout << "\n";
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to reset the board
void resetBoard(char board[3][3]) {
    char initial = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = initial++;
        }
    }
}

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    int choice;
    bool gameOver = false;
    char playAgain;

    resetBoard(board);

    cout << "Welcome to Tic Tac Toe!" << endl;

    do {
        displayBoard(board);

        // Player move
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Calculate row and column based on choice
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check if the cell is already taken
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken. Try again." << endl;
            continue;
        }

        // Place the player's move on the board
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (isBoardFull(board)) {
            // Check for a draw
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        } else {
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Check if the game is over and ask if the players want to play again
        if (gameOver) {
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y') {
                resetBoard(board);
                currentPlayer = 'X';
                gameOver = false;
            } else {
                cout << "Thanks for playing Tic Tac Toe!" << endl;
                break;
            }
        }

    } while (true);

    return 0;
}
