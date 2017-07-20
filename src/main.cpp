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
void initialize_grid(char grid[3][3]) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            grid[x][y]='.';
        }
    }
}


/**
 * Desc: Draws board
 * @param grid
 * @return: prints board to console
 */
void drawGrid(char grid[3][3]) {
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
 * @param player
 * @param grid
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


int negaMax(char grid[3][3], char player, char AIbot);

/**
 * Desc: Picks the best move given the current board.
 * @param grid
 * @param player
 * @param AIbot
 * @return
 */
int pickBestMove(char grid[3][3], char player, char AIbot) {
    int bestMoveScore = -9999;
    int bestMoveRow = -9999;
    int bestMoveCol = -9999;
    int thisMoveScore = 0;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (grid[x][y] = '.') {
                grid[x][y] = player;
                thisMoveScore = -(negaMax(grid, AIbot, player));
                grid[x][y] = '.';
                if (thisMoveScore >= bestMoveScore) {
                    bestMoveScore = thisMoveScore;
                    bestMoveRow = x;
                    bestMoveCol = y;
                }

            }
        }
    }

    return (10*bestMoveRow + bestMoveCol);
}

/**
 * Desc: Plays out every possible position
 * @param grid
 * @param player
 * @param AIbot
 * @return bestMoveScore to pickBestMove
 */
int negaMax(char grid[3][3], char player, char AIbot) {
    int bestMoveScore = -9999;
    int thisMoveScore = 0;

    // if human wins, score increases
    if (checkWin(grid) == player)
        return 1000;
    // if AIbot wins, score decreases
    else if (checkWin(grid) == AIbot)
        return -1000;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (grid[x][y] = '.') {
                grid[x][y] = player;
                thisMoveScore = -(negaMax(grid, AIbot, player));
                grid[x][y] = '.';
                if (thisMoveScore >= bestMoveScore) {
                    bestMoveScore = thisMoveScore;
                }
            }
        }
    }

    if (bestMoveScore == 0 || bestMoveScore == -9999)
        return 0;
    else if (bestMoveScore < 0)
        return bestMoveScore + 1;
    else if (bestMoveScore > 0)
        return bestMoveScore -1;

}




/**
 * Desc: Plays game, player vs AI bot
 * @param grid
 * @param player
 * @param AIbot
 * @return a played game
 */
void playGame(char grid[3][3], char player, char AIbot) {
    int move = 0;
    while (move < 9) {
        getPlayerInput(player, grid);
        move++;
        drawGrid(grid);
        if (checkWin(grid)) {
            cout << "Wow, you've actually won..." << endl;
            exit(1);
        }
        if (move == 9)
            break;
        int nextMove = pickBestMove(grid, AIbot, player);
        int x = nextMove / 10;
        int y = nextMove % 10;
        grid[x][y] = AIbot;
        move++;
        drawGrid(grid);
        if (checkWin(grid)) {
            cout << "That was too easy! Humans are so petty, we robots will dominate the Earth!" << endl;
            cout << "However...I'll take pity on you. Your best move would have been at coordinates " << "( " << nextMove/10 + 1 << ", " << nextMove % 10 + 1 <<")" << endl;
            exit(2);
        }
        cout << "It's a draw! If the computer could glare, it would be doing so right now!" << endl;
    }

}




int main() {
    TicTacToe newGame;
    initialize_grid(newGame.grid);
    newGame.player='x';
    newGame.AIbot='o';
    drawGrid(newGame.grid);
    playGame(newGame.grid, newGame.player, newGame.AIbot);
    return 0;
};
