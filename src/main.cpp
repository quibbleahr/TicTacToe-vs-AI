#include <iostream>

using namespace std;
char matrix[3][3] {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';

// draws matrix for tic-tac-toe
void draw() {
    cout << "Tic-Tac-Toe" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
// gets the player input and updates matrix
void playerInput() {
    int a;
    cout << "Press the number of the field: ";
    cin >> a;

    a--;
    matrix[a/3][a%3] = player;

}
// changes player from X to O, default is X
void changePlayer() {
    if (player == 'X')
        player = 'O';

    else player = 'X';
}


int main() {
    draw();
    while (1) {
        playerInput();
        draw();
        changePlayer();
    }
    return 0;
}