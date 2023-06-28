#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void print(int size);
void printWord(int size, string word, char letter, string *newWord);
bool check(string word, char letter, int size);
bool checkWins(string *word, int size);

/*
      HANG MAN
   ______________
   |            |
   |            |
   |           (_)
   |           /|\
   |           / \
   |
   |
   +--------------------
*/

int main() {
    srand (time(NULL));

    int counter = 1;
    char letter;
    bool secondCheck = true;

    string guesses[] = {
            "pomeranian",
            "shiba inu",
            "yorkshire terrier",
            "shih tzu",
            "chihuahua",
            "pug",
            "golden retriever",
            "doberman",
            "husky",
            "samoyed"
    };
    string word;
    word = guesses[ rand() % guesses->length() ];

    int size = word.length();
    string newWord[size];

    for (int i = 0; i < size; i++){

        if (i == 0){
            newWord[i] = word[i];
        } else if (i == size-1){
            newWord[i] = word[i];
        }else if (word[i] == ' '){
            newWord[i] = " ";
            //cout << newWord[i];
        } else {
            newWord[i] = "*";
            //cout << newWord[i];
        }
        cout << newWord[i];
    }
    cout << endl;

    cout << endl << "Choose letter from a to z: " << endl;

    while (secondCheck){
        secondCheck = true;
        cin >> letter;
        cout << endl;

        if (check(word, letter, size)){

            printWord(size, word, letter, newWord);

            if (checkWins(newWord, size)){
                cout << endl << "YOU WON!" << endl;
                cout  << "The word was: ";
                printWord(size, word, letter, newWord);
                secondCheck = false;
            }

            cout << endl;

        } else {

            if (counter == 8){
                cout << "GAME END" << endl;
                secondCheck = false;
            }
            cout << endl;
            print(counter);
            counter++;
            cout << endl;
        }

    }

    return 0;
}

void print(int size){
    for (int i = 1; i <= size; i++){
        switch (i) {
            case 1:
                cout << "   ______________" << endl;
                cout << "   |            |" << endl;
                break;
            case 2:
                cout << "   |            |" << endl;
                break;
            case 3:
                cout << "   |           (_)" << endl;
                break;
            case 4:
                cout << "   |           /";
                break;
            case 5:
                cout << "|";
                break;
            case 6:
                cout << "\\" << endl;
                break;
            case 7:
                cout << "   |           /";
                break;
            case 8:
                cout << " \\" << endl;
                cout << "   |" << endl;
                cout << "   |" << endl;
                cout << "   +--------------------" << endl;
                break;
        }


    }

}

void printWord(int size, string word, char letter, string *newWord){
    for (int i = 0; i < size; i++){
        if (word[i] == letter){
            newWord[i] = letter;
        }
    }

    for (int i = 0; i < size; i++){
        cout << newWord[i];
    }

}

bool check(string word, char letter, int size){
    for (int i = 0; i < size; i++){
        if (word[i] == letter){
            return true;
        }
    }
    return false;
}

bool checkWins(string *word, int size){
    bool check = false;
    int counter = 0;

    for (int i = 0; i < size; i++){
        if (word[i] != "*" && counter == 0){
            check = true;

        } else {
            check = false;
            counter++;
        }

    }

    return check;
}