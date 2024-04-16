#include <iostream>
#include <windows.h>

using namespace std;

int const LENGTH = 100;
char const SYMBOL = '-';
int const SLEEP = 2000;
int const AMOUNT_OF_WORDS = 4;

char container[AMOUNT_OF_WORDS][LENGTH] = {"qweqtq", "qeeee", "ddddd", "yyyttrr"};
char questions[AMOUNT_OF_WORDS][LENGTH] = {"q1", "q2", "q3", "q4"};
char hiddenWord[LENGTH] = "";
int wordIndex = -1;


int checkTheLetter(char l, int index);
void startNewGame();
int getStringLength(char str[]);
void hideWord();
void openLetters(char l);
bool checkClosedLetters();


int main(){
    char choice = ' ';

    while(true){
        system("cls");
        cout << "Would you like to start a New Game?" << endl;
        cout << "[Y|N]" << endl;
        cin >> choice;
        wordIndex = rand() % AMOUNT_OF_WORDS;
        if (choice == 'Y' or choice == 'y'){
            startNewGame();
        } else {
            break;
        }
    }

    return 0;
}

void startNewGame() {
    char letter = ' ';
    int index = 0;
    bool guessed = true;

    system("cls");
    cout << questions[wordIndex] << endl;
    hideWord();
    cout << hiddenWord << endl;
    while (guessed) {
        guessed = false;
        cout << "What's your letter?" << endl;
        cin >> letter;
        openLetters(letter);
        cout << questions[wordIndex] << endl;
        cout << hiddenWord << endl;
        guessed = checkClosedLetters();
    }
    system("cls");
    cout << "You've guessed the word!" << endl;
    cout << hiddenWord;
    Sleep(SLEEP);
}

int checkTheLetter(char l, int index){
    for (int i = index; i < getStringLength(container[wordIndex]); ++i) {
        if (l == container[wordIndex][i]) {
            return i;
        }
    }
    return -1;
}

int getStringLength(char str[]){
    int counter = 0;

    while(true){
        if (str[counter] == 0)
            break;
        counter++;
    }
    return counter + 1;
}

void hideWord(){
    int i = 0;
    for (; i < getStringLength(container[wordIndex]) - 1; ++i) {
        hiddenWord[i] = SYMBOL;
    }
    hiddenWord[i] = container[wordIndex][i];
}

void openLetters(char l){
    int index = 0;
    bool wasOpened = false;

    while (true) {
        index = checkTheLetter(l, index);
        if (index == -1 and wasOpened)
            break;
        else if ( index == -1 and !wasOpened ){
            cout << "There is no such letter" << endl;
            cout << endl;
            break;
        } else {
        hiddenWord[index] = container[wordIndex][index];
        wasOpened = true;
        index++;
        }
    }
}

bool checkClosedLetters(){
    for (int i = 0; i < getStringLength(hiddenWord); ++i) {
        if (hiddenWord[i] == '-')
            return true;
    }
    return false;
}
