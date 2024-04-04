#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

const double USD_RATE = 3.27;
const double EUR_RATE = 3.56;
const double CNY_RATE = 0.45;

double getMoney();

void printMoney();

double convertBYNtoUSD(double cash);

double convertBYNtoEUR(double cash);

double convertBYNtoCNY(double cash);

void printNoCash();

int main() {
    int choice = 0;
    double cash = 0.0;

    while (true) {
        printMoney();
        cout << " Your choice:" << endl;
        cin >> choice;
        if (choice == 1) {
            cash = getMoney();
            system("cls");
            cout << "Ok, " << cash << " BYN deposited" << endl;
            Sleep(2500);
        } else if (choice == 5) {
            break;
        } else if (choice == 2) {
            if (cash == 0){
                printNoCash();
                continue;
            }
            system("cls");
            cout << "Your money: " << convertBYNtoUSD(cash) << " USD" << endl;
            cash = 0;
            Sleep(2500);
        } else if (choice == 3) {
            if (cash == 0){
                printNoCash();
                continue;
            }
            system("cls");
            cout << "Your money: " << convertBYNtoEUR(cash) << " EUR" << endl;
            cash = 0;
            Sleep(2500);
        } else if (choice == 4) {
            if (cash == 0){
                printNoCash();
                continue;
            }
            system("cls");
            cout << "Your money: " << convertBYNtoCNY(cash) << " CNY" << endl;
            cash = 0;
            Sleep(2500);
        } else {
            system("cls");
            cout << "Input [1..5], please" << endl;
            Sleep(2500);
        }
    }

    return 0;
}

double getMoney() {
    double roubles = 0;
    double kopecks = 0;
    double money = 0;

    system("cls");
    cout << "Insert your roubles BYN:" << endl;
    cin >> roubles;
    cout << "Insert your kopecks BYN:" << endl;
    cin >> kopecks;

    money = roubles + kopecks/100;

    return money;
}

void printMoney() {
    system("cls");
    cout << " Menu: " << endl;
    cout << " 1 - Deposit" << endl;
    cout << " 2 - Convert to USD" << endl;
    cout << " 3 - Convert to EUR" << endl;
    cout << " 4 - Convert to CNY" << endl;
    cout << " 5 - Exit" << endl;

}

double convertBYNtoUSD(double cash) {
    double cashUSD = 0;
    double rounded = 0;

    cashUSD = cash / USD_RATE;
    cashUSD = round(cashUSD * 100) / 100;

    return cashUSD;
}

double convertBYNtoEUR(double cash) {
    double cashEUR = 0;

    cashEUR = cash / EUR_RATE;
    cashEUR = round(cashEUR * 100) / 100;

    return cashEUR;
}

double convertBYNtoCNY(double cash) {
    double cashCNY = 0;

    cashCNY = cash / CNY_RATE;
    cashCNY = round(cashCNY * 100) / 100;

    return cashCNY;
}

void printNoCash(){
    system("cls");
    cout << "You haven't deposited money yet" << endl;
    Sleep(2500);
    return;
}