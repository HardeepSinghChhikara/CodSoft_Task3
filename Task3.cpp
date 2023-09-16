#include <iostream>
#include <vector>

// Function to initialize the game board
std::vector<std::vector<char>> initializeBoard() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    return board;
}

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
}

// Function to check if the game is over (win or draw)
bool isGameOver(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }

    // Check for a draw (board is full)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There's an empty space, game is not a draw yet
            }
        }
    }
    return true; // The board is full, and there's no win, so it's a draw
}

int main() {
    std::vector<std::vector<char>> board = initializeBoard();
    char currentPlayer = 'X';
    bool gameIsOver = false;

    std::cout << "TIC-TAC-TOE GAME" << std::endl;
    
    while (!gameIsOver) {
        displayBoard(board);
        std::cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
        
        int row, col;
        std::cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move! Try again." << std::endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check if the current player has won or if the game is a draw
        gameIsOver = isGameOver(board, currentPlayer);

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Display the final state of the board and the result
    displayBoard(board);
    if (gameIsOver && !isGameOver(board, 'X') && !isGameOver(board, 'O')) {
        std::cout << "It's a draw!" << std::endl;
    } else {
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    }

    return 0;
}
