#include <iostream>
#include <windows.h>

using namespace std;

const int X_DIMENSION = 18;
const int Y_DIMENSION = 50;
const int AMOUNT_OF_BEINGS = 5;

int field[X_DIMENSION][Y_DIMENSION] = {};


void printField(char s);      //Prints field with \o/

void placeLife(int xCoords[], int yCoords[], int amountOfBeings);   //puts \o/ on the field for the first time

void lifeDistribution();  //main func which defines rules of the game

int checkAround(int x, int y); // detects \o/ around chosen position

int nextLifePlacement(int nextField[X_DIMENSION][Y_DIMENSION]);  //put \o/ on the field according to the rules


int main() {
    char symbol = ' ';
    char response = 1;
    int xCoords[AMOUNT_OF_BEINGS] = {};
    int yCoords[AMOUNT_OF_BEINGS] = {};


    while (1) {
        cout << "Would you like to play Life Game?\n(1)Start New game\n(0)exit\n";
        cin >> response;
        if (response == 49) {
            placeLife(xCoords, yCoords, AMOUNT_OF_BEINGS);
            printField(symbol);
            Sleep(2000);
            lifeDistribution();
        } else if (response == 48) {
            return 0;
        }
        else{
            cout << "Error! Incorrect response";
            return 1;
        }
    }
}

void printField(char s) {
    for (int i = 1; i < X_DIMENSION - 1; ++i) {
        for (int j = 1; j < Y_DIMENSION - 1; ++j) {
            if (field[i][j] == 0) {
                cout << s;
            } else {
                cout << "\\o/";
            }
        }
        cout << endl;

    }
    return;
}

void placeLife(int xCoords[], int yCoords[], int amountOfBeings) {
    for (int i = 0; i < X_DIMENSION; ++i) {
        for (int j = 0; j < Y_DIMENSION; ++j) {
            for (int k = 0; k < amountOfBeings; ++k) {
                field[i][j] = rand() % 2;
            }
        }
    }
    return;
}

void lifeDistribution() {
    bool life = 1;
    bool anythingChanges = 1;
    int nextField[X_DIMENSION][Y_DIMENSION] = {};

    while (life and anythingChanges) {
        system("cls");
        life = 0;
        anythingChanges = 0;

        for (int i = 1; i < X_DIMENSION - 1; ++i) {
            for (int j = 1; j < Y_DIMENSION - 1; ++j) {
                if (checkAround(i, j) > 3 and field[i][j])
                    nextField[i][j] = 0;
                if (checkAround(i, j) < 2 and field[i][j])
                    nextField[i][j] = 0;
                if (checkAround(i, j) == 3)
                    nextField[i][j] = 1;
                if (checkAround(i, j) == 2 and field[i][j])
                    nextField[i][j] = 1;
                if (checkAround(i, j) > 0)
                    life = 1;
            }
        }
        anythingChanges = nextLifePlacement(nextField);

        printField(' ');
        Sleep(500);
    }

    cout << "Game over!";
    return;
}

int checkAround(int x, int y) {
    int counter = 0;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (field[i][j]) {
                counter++;
            }
        }
    }
    return counter - field[x][y];
}


int nextLifePlacement(int nextField[X_DIMENSION][Y_DIMENSION]){
    int anythingChanges = 0;

    for (int i = 1; i < X_DIMENSION - 1; ++i) {
        for (int j = 1; j < Y_DIMENSION - 1; ++j) {
            if (nextField[i][j] != field[i][j])
                anythingChanges = 1;
            if (nextField[i][j])
                field[i][j] = 1;
            else
                field[i][j] = 0;
        }

    }

    return anythingChanges;
}