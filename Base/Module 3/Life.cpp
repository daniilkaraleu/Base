#include <iostream>
#include <windows.h>

using namespace std;

const int X_DIMENSION = 18;
const int Y_DIMENSION = 50;
const int AMOUNT_OF_BEINGS = 3;

int field[X_DIMENSION][Y_DIMENSION] = {};


void printField(char s);

void placeLife(int xCoords[], int yCoords[], int amountOfBeings);

void lifeDistribution();

int checkAround(int x, int y);

bool checkData(int xCoords[], int yCoords[], int amountOfBeings);

void startTheGame(int xCoords[], int yCoords[]);

int main() {
    char symbol = ' ';
    int response = 1;
    int xCoords[AMOUNT_OF_BEINGS] = {};
    int yCoords[AMOUNT_OF_BEINGS] = {};


    while (1) {
        cout << "Would you like to play Life Game?\n(1)Start New game\n(0)exit\n";
        cin >> response;
        if (response) {
            startTheGame(xCoords, yCoords);
            if (!checkData(xCoords, yCoords, AMOUNT_OF_BEINGS)) {
                cout << "Invalid coords!";
                continue;
            }
            placeLife(xCoords, yCoords, AMOUNT_OF_BEINGS);
            printField(symbol);
            Sleep(2000);
            lifeDistribution();
        } else
            break;
    }
    return 0;
}

void printField(char s) {
    for (int i = 1; i < X_DIMENSION - 1; ++i) {
        for (int j = 1; j < Y_DIMENSION - 1; ++j) {
            if (field[i][j] == 0) {
                cout << s;
            } else {
                cout << "#";
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
                if (xCoords[k] == i and yCoords[k] == j) {
                    field[i][j] = 1;
                }
            }
        }
    }
    return;
}

void lifeDistribution() {
    bool life = 1;
    bool anythingChanges = 1;
    int arrayToChange[X_DIMENSION][Y_DIMENSION] = {};

    while (life and anythingChanges) {
        system("cls");
        life = 0;
        anythingChanges = 0;

        for (int i = 1; i < X_DIMENSION - 1; ++i) {
            for (int j = 1; j < Y_DIMENSION - 1; ++j) {
                if (checkAround(i, j) > 3 and field[i][j])
                    arrayToChange[i][j] = 0;
                if (checkAround(i, j) < 2 and field[i][j])
                    arrayToChange[i][j] = 0;
                if (checkAround(i, j) == 3 and field[i][j] == 0)
                    arrayToChange[i][j] = 1;
                if (checkAround(i, j) == 2 and field[i][j])
                    arrayToChange[i][j] = 1;
                if (checkAround(i, j) > 0)
                    life = 1;
            }
        }

        for (int i = 1; i < X_DIMENSION - 1; ++i) {
            for (int j = 1; j < Y_DIMENSION - 1; ++j) {
                if (arrayToChange[i][j] != field[i][j])
                    anythingChanges = 1;
                if (arrayToChange[i][j])
                    field[i][j] = 1;
                else
                    field[i][j] = 0;
            }

        }

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

bool checkData(int xCoords[], int yCoords[], int amountOfBeings) {
    for (int i = 0; i < amountOfBeings; ++i) {
        if (xCoords[i] < 1 or xCoords[i] > X_DIMENSION - 1 or yCoords[i] < 1 or yCoords[i] > Y_DIMENSION - 1) {
            return false;
        }

    }
    return true;
}

void startTheGame(int xCoords[], int yCoords[]) {
    printField('o');
    cout << "Input your " << AMOUNT_OF_BEINGS << " points coords \n";
    for (int i = 0; i < AMOUNT_OF_BEINGS; ++i) {
        cout << "Input x[1.." << X_DIMENSION - 1 << "]:";
        cin >> xCoords[i];
        cout << "Input y[1.." << Y_DIMENSION - 1 << "]:";
        cin >> yCoords[i];
    }

    system("cls");
}