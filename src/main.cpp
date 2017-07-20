/*********************************************************************
 ** Filename: main.cpp
 ** @author Arianna Leah Fischer
 ** @date 07/20/2017
 ** Description: Tic tac toe (1 player and 2 player)
 *********************************************************************/


#include <iostream>

using namespace std;

struct TicTacToe {
    char grid[3][3];
    char player;
    char AIbot;
};


/**
 * Desc: Initializes board with dots
 * @param grid
 * @return initialized board board with dots
 */
void initialize_board (char grid[3][3]) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            grid[x][y]='.';
        }
    }
}


/**
 * Desc: Draws board
 * @param grid A 3x3 tic-tac-toe grid
 * @return: prints board to console
 */
void drawBoard(char grid[3][3]) {
    for (int x = 0; x < 3; x++) {
        cout << endl;
        for (int y = 0; y < 3; y++) {
            cout << " ";
            cout << grid[x][y];
        }
    }
    cout << endl << endl;
}

bool isInBounds(int in) {
    return (in >= 1 && in <= 3);
}

bool isFieldTaken(char grid[3][3], int x, int y) {
    return (grid[x-1][y-1] != '.');
}

/**
 * Desc: Gets player's input as coordinates and places character 'x' on that spot.
 * @param player, grid
 * @return Places character 'x' on grid
 */
void getPlayerInput(char player, char grid[3][3]){
    while(1) {
        string srow;
        string scol;
        int row = 0;
        int col = 0;
        while (1) {
            cout << "Enter the row: " << endl;
            cin >> srow;
            row = atoi(srow.c_str());
            if (isInBounds(row))
                break;
            cout << "Ouch! You must enter a value between 1 and 3 inclusive!" << endl;
        }
        while(1) {
            cout << "Enter the column: " << endl;
            cin >> scol;
            col = atoi(scol.c_str());
            if (isInBounds(col))
                break;
            cout << "Ouch! You must enter a value between 1 and 3 inclusive!" << endl;
        }
        if (!isFieldTaken(grid, row, col)) {
            grid[row-1][col-1] = player;
            break;
        }
        cout << "Field taken! ";
    }
}

/**
 * Desc: Checks for three of the same char in a row horizontally, vertically, and diagonally.
 * @param grid
 * @return returns character of the winner or 0 if nobody has won
 */
char checkWin (char grid[3][3]) {
    // check through coordinates (0,0)
    if (grid[0][0] != '.' && (grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2] || // horizontal
                              grid[0][0] == grid[1][0] && grid[0][0] == grid[2][0] || // vertical
                              grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]))  // diagonal
        return grid[0][0];
    // check through coordinates (1,1)
    if (grid[1][1] != '.' && (grid[1][1] == grid[1][0] && grid[1][1] == grid[1][2] || // horizontal
                              grid[1][1] == grid[0][1] && grid[1][1] == grid[2][1] || // vertical
                              grid[1][1] == grid[2][0] && grid[1][1] == grid[0][2]))  // diagonal
        return grid[1][1];
    // check through coordinates (2,2) . All horizontal win cases have already been checked in previous two conditions
    if (grid[2][2] != '.' && (grid[2][2] == grid[0][2] && grid[2][2] == grid[1][2] || // vertical
                              grid[2][2] == grid[2][0] && grid[2][2] == grid[2][1]))  // horizontal
        return grid[2][2];


    return 0;
}


int




/**
 * Desc: Plays game, player vs AI bot
 * @param player, AIbot, grid
 * @return a played game
 */
void playGame(char grid[3][3], char player, char AIbot) {
    int move = 0;
    while (move < 9) {
        getPlayerInput(player, grid);
        move++;
        drawBoard(grid);
    }

}




int main() {
    TicTacToe newGame;
    initialize_board(newGame.grid);
    drawBoard(newGame.grid);
    getPlayerInput('x', newGame.grid);
    drawBoard(newGame.grid);
    return 0;
};
