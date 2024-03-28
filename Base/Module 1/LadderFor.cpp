#include <iostream>

using namespace std;

int main() {
    int amountOfIter = 5;

    for (int i = 0; i < amountOfIter; ++i) {
        cout << i + 1 << " ";
    }
    cout << endl;

    double firstElement = -2;
    for (int i = 0; i < amountOfIter; ++i) {
        cout << firstElement << " ";
        firstElement += 1;
    }
    cout << endl;

    firstElement = -2;
    for (int i = 0; i < amountOfIter; ++i) {
        cout << firstElement << " ";
        firstElement += 2;
    }
    cout << endl;

    firstElement = 5;
    for (int i = 0; i < amountOfIter; ++i) {
        cout << firstElement << " ";
        firstElement -= 1;
    }
    cout << endl;

    firstElement = 5;
    for (int i = 0; i < amountOfIter; ++i) {
        cout << firstElement << " ";
        firstElement -= 3;
    }
    cout << endl;

    firstElement = 1;
    double square = 0;
    for (int i = 0; i < amountOfIter; ++i) {
        square = firstElement * firstElement;
        cout << square << " ";
        firstElement += 1;
    }
    cout << endl;

    firstElement = 1;
    int increment = 0;;
    for (int i = 0; i < amountOfIter; ++i) {
        int result = firstElement + increment;
        cout << result << " ";
        firstElement = result;
        increment++;
    }
    return 0;
}