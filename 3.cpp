#include <iostream>
using namespace std;

class Game {
private:
    char board[3][3];
    char turn;     // 'X' or 'O'
    char winner;   // 'X', 'O', or ' ' (no winner yet)

public:
    // Constructor
    Game() {
        resetGame();
    }

    // Reset the game
    void resetGame() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        turn = 'X';     // X always starts
        winner = ' ';
    }

    // Print the board
    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    // Make a move
    bool makeMove(int row, int col) {
        // Check bounds
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "Invalid position! Try again.\n";
            return false;
        }

        // Check if cell is empty
        if (board[row][col] != ' ') {
            cout << "Cell already occupied! Try again.\n";
            return false;
        }

        // Place mark
        board[row][col] = turn;

        // Check winner
        checkWinner();

        // Switch turn
        if (winner == ' ') {
            turn = (turn == 'X') ? 'O' : 'X';
        }

        return true;
    }

    // Check for winner
    void checkWinner() {
        // Rows and Columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == turn &&
                board[i][1] == turn &&
                board[i][2] == turn) {
                winner = turn;
                return;
            }

            if (board[0][i] == turn &&
                board[1][i] == turn &&
                board[2][i] == turn) {
                winner = turn;
                return;
            }
        }

        // Diagonals
        if (board[0][0] == turn &&
            board[1][1] == turn &&
            board[2][2] == turn) {
            winner = turn;
            return;
        }

        if (board[0][2] == turn &&
            board[1][1] == turn &&
            board[2][0] == turn) {
            winner = turn;
            return;
        }
    }

    // Check if board is full (draw)
    bool isDraw() {
        if (winner != ' ') return false;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    // Get current turn
    char getTurn() {
        return turn;
    }

    // Get winner
    char getWinner() {
        return winner;
    }
};

int main() {
    Game game;
    int row, col;

    while (true) {
        game.printBoard();

        cout << "Player " << game.getTurn() << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (!game.makeMove(row, col)) {
            continue;
        }

        // Check for winner
        if (game.getWinner() != ' ') {
            game.printBoard();
            cout << "Player " << game.getWinner() << " wins!\n";
            break;
        }

        // Check for draw
        if (game.isDraw()) {
            game.printBoard();
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
