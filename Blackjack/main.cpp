#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int* sumCards (int* sumPlayers, const std::string& currentCard, int index);
int largestNum(int* arr, int n);

int main() {
    srand (time(NULL));
    int players = 1, sum = 0;
    char card, cardRequest = 'Y';
    string currentCard;
    string deck[] = {
            " ",
            "A",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "J",
            "Q",
            "K",
    };

    cout << "Enter players: " << endl;
    cin >> players;

    int sumPlayers[players];
    string board[12][players];

    for (int i = 0; i < players; i++) {
        sumPlayers[i] = 0;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < players; j++) {
            currentCard = deck[rand() % 13 + 1];
            board[i][j] = currentCard;

            cout << board[i][j] << " ";

            sumCards(sumPlayers, currentCard, j);

        }
        cout << endl;
    }

    for (int i = 0; i < players; i++){
        cout << "Sum player " << i + 1 << " : " << sumPlayers[i] << " " << endl;
    }


    for (int j = 0; j < players; j++){
        do {
            cout << "Plater: " << j + 1 << ". Do you want more cards ?" << endl;
            cin >> cardRequest;
            if (cardRequest == 'Y') {
                currentCard = deck[rand() % 13 + 1];
                cout << currentCard << " " << endl;

                sumCards(sumPlayers, currentCard, j);

                cout << "Sum player " << j + 1 << " : " << sumPlayers[j] << " " << endl;
            }
        } while (cardRequest != 'N' && sumPlayers[j] <= 21);
    }

    cout << endl;
    for (int i = 0; i < players; i++){
        if (sumPlayers[i] == 21){
            cout << "Player " << i + 1 << " WINS" << endl;
        } else if (sumPlayers[i] > 21){
            cout << "Player " << i + 1 << " is BUSTED" << endl;
        } else if (sumPlayers[i] == largestNum(sumPlayers, players)){
            cout << "Player " << i + 1 << " WINS" << endl;
        }
    }

    return 0;
}

int* sumCards(int* sumPlayers, const std::string& currentCard, int index) {
    if (currentCard == "A" && index <= 1) {
        sumPlayers[index] += 11;
    } else if (currentCard <= "9") {
        int num = std::stoi(currentCard);
        sumPlayers[index] += num;
    } else {
        sumPlayers[index] += 10;
    }
    
    return sumPlayers;
}

int largestNum(int* arr, int n){
    int max = arr[0];

    for (int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}
