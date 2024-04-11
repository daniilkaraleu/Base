#include <iostream>
#include <windows.h>

using namespace std;
int const LENGTH = 7;
int const LEFT = '<';
int const RIGHT = '>';

void printRow(char row[]);

int main() {
    bool isWrong = true;
    char currentSymbol = ' ';
    char nextSymbol = ' ';
    char row[LENGTH] = {'>', '<', '<', '>', '>', '<', '>'};

    while (isWrong) {
        printRow(row);
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

        Sleep(1000);
    }

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