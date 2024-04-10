#include <iostream>

using namespace std;

int const N = 3;

int cube[N][N][N] ={{{1,1,0},
                          {1,0,1},
                          {1,1,1}},

                    {{1,1,0},
                         {1,1,1},
                         {1,1,1}},

                    {{1,1,0},
                         {1,0,1},
                         {1,1,1}}};

bool hasInRow();
bool hasInColumn();
bool hasInLine();

int main(){
    if (hasInRow());
    else if(hasInColumn());
    else if (hasInLine())
    return 0;
}

bool hasInRow(){
    int counter = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (!cube[i][j][k])
                    counter++;
            }
            if (counter == 3) {
                cout << "It has clearance!";
                return true;
            }
            counter = 0;
        }
    }
    return false;
}
bool hasInColumn(){
    int counter = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (!cube[i][k][j])
                    counter++;
            }
            if (counter == 3) {
                cout << "It has clearance!";
                return true;
            }
            counter = 0;
        }
    }
    return false;
}

bool hasInLine(){
    int counter = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (!cube[k][j][i])
                    counter++;
            }
            if (counter == 3) {
                cout << "It has clearance!";
                return true;
            }
            counter = 0;
        }
    }
    return false;
}

