#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;

void print(char *matrix);
bool checkWin(char *matrix, char playerSymbol);

int main() {
    srand (time(NULL));

    char player1, player2;
    char currentPlayer;
    int place;
    bool winner = false;

    int checkIfPLaceIsTaken[9] = {0};
    char matrix[9];

    cout << "Choose X or O" << endl;


    do{
        cin >> player1;
    } while (player1 != 'X' && player1 != 'O');

    if (player1 == 'X'){
        player2 = 'O';
    } else {
        player2 = 'X';
    }

    cout << "Choose where to place your symbol " << endl;

    int k = 0;

while (!winner && k < 9){
    cin >> place;

    for (int i = 0; i < 9; i++){

        if (checkIfPLaceIsTaken[i] == place){
            place = 0;

        } else{
            checkIfPLaceIsTaken[i] = place;
        }

    }

    if (k % 2 == 0){
        currentPlayer = player1;
    } else {
        currentPlayer = player2;
    }

    switch (place) {
        case 0:
            cout << "Invalid input. This position is taken." << endl;
            continue;
        case 1:
            matrix[0] = currentPlayer;
            break;
        case 2:
            matrix[1] = currentPlayer;
            break;
        case 3:
            matrix[2] = currentPlayer;
            break;
        case 4:
            matrix[3] = currentPlayer;
            break;
        case 5:
            matrix[4] = currentPlayer;
            break;
        case 6:
            matrix[5] = currentPlayer;
            break;
        case 7:
            matrix[6] = currentPlayer;
            break;
        case 8:
            matrix[7] = currentPlayer;
            break;
        case 9:
            matrix[8] = currentPlayer;
            break;
        default:
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
    }

    print(matrix);

    if (checkWin(matrix, player1)){
        cout << "PLayer 1 wins!" << endl;
        winner = true;
    } else if (checkWin(matrix, player2)){
        cout << "PLayer 2 wins!" << endl;
        winner = true;
    } else if (k == 8){
        cout << "Draw!" << endl;
        winner = true;
    }

    k++;
}

if (!winner){
    cout << "Nobody wins! " << endl;
}

    return 0;
}

void print(char *matrix){

    cout << "----------------------------------" << endl;
    cout << "     " << matrix[0] << "     |     " << matrix[1] << "     |     " << matrix[2] << "     " << endl;
    cout << "----------------------------------" << endl;
    cout << "     " << matrix[3] << "     |     " << matrix[4] << "     |     " << matrix[5] << "     " << endl;
    cout << "----------------------------------" << endl;
    cout << "     " << matrix[6] << "     |     " << matrix[7] << "     |     " << matrix[8] << "     " << endl;
    cout << "----------------------------------" << endl;

}

bool checkWin(char *matrix, char playerSymbol) {

    for (int i = 0; i < 9; i += 3) {
        if (matrix[i] == playerSymbol && matrix[i + 1] == playerSymbol && matrix[i + 2] == playerSymbol) {
            return true;
        }
        if (matrix[i / 3] == playerSymbol && matrix[(i / 3) + 3] == playerSymbol && matrix[(i / 3) + 6] == playerSymbol) {
            return true;
        }
    }


    if (matrix[0] == playerSymbol && matrix[4] == playerSymbol && matrix[8] == playerSymbol) {
        return true;
    }
    if (matrix[2] == playerSymbol && matrix[4] == playerSymbol && matrix[6] == playerSymbol) {
        return true;
    }

    return false;
}