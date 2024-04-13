#include <iostream>
#include <windows.h>

using namespace std;
/*
 * RIGHT, LEFT, LEFT, RIGHT, RIGHT, LEFT, RIGHT
 *
 *  ><<>><>
 *  <><><>>
 *  <<><>>>
 *  <<<>>>>
 *  CMIPHO!
 * */


int const LENGTH = 7;
int const LEFT = '<';
int const RIGHT = '>';
int const SLEEP = 1000;

void printRow(char row[]);
void changeConfiguration(char row[]);

int main() {
    char row[LENGTH] = {RIGHT, LEFT, LEFT, RIGHT, RIGHT, LEFT, RIGHT};

    printRow(row);
    changeConfiguration(row);

    cout << "\a";
    cout << "CMIPHO!";
    return 0;
}

void printRow(char row[]){
    for (int i = 0; i < LENGTH; ++i) {
        cout << row[i];
    }
    cout << endl;
}

void changeConfiguration(char row[]){
    bool isWrong = true;
    char currentSymbol = ' ';
    char nextSymbol = ' ';

    while (isWrong) {
        currentSymbol = row[0];
        isWrong = false;
        for (int i = 0; i < LENGTH - 1; ++i) {
            nextSymbol = row[i + 1];
            if (currentSymbol == RIGHT and row[i + 1] == LEFT) {
                row[i] = LEFT;
                row[i + 1] = RIGHT;
                isWrong = true;
            }
            currentSymbol = nextSymbol;
        }
        if (isWrong){
            Sleep(SLEEP);
            printRow(row);
        }
    }
}
