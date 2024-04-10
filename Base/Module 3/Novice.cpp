//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//int const LENGTH = 7;
//int const LEFT = '<';
//int const RIGHT = '>';
//
//void printRow(char row[]);
//
//int main() {
//    bool isWrong = false;
//    int time = 0;
//    char currentSymbol = ' ';
//    char nextSymbol = ' ';
//    char row[LENGTH] = {'>', '<', '<', '>', '>', '<', '>'};
//
//    currentSymbol = row[0];
//    do{
//        isWrong = false;
//        for (int i = 0; i < LENGTH - 1; ++i) {
//            nextSymbol = row[i + 1];
//            if (currentSymbol == RIGHT and row[i + 1] == LEFT) {
//                row[i] = LEFT;
//                row[i + 1] = RIGHT;
//                isWrong = true;
//            }
//            currentSymbol = nextSymbol;
//        }
//
//        printRow(row);
//        Sleep(1000);
//    } while (isWrong);
//    cout << "\a";
//    cout << "CMIPHO!";
//    return 0;
//}
//
//void printRow(char row[]){
//    for (int i = 0; i < LENGTH - 1; ++i) {
//        cout << row[i];
//    }
//    cout << endl;
//}