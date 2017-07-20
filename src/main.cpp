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
    char bot;
};


/**
 * Desc: Initializes board with dots
 * @param grid[3][3]
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
 * @param grid[3][3] A 3x3 tic-tac-toe grid
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

/**
 *
 * @return
 */



int main() {
    TicTacToe newGame;
    initialize_board(newGame.grid);
    drawBoard(newGame.grid);
    return 0;
};
