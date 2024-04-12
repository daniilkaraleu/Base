#include <iostream>
#include <windows.h>
#include <random>

using namespace std;

int const ROWS = 3;
int const COLUMNS = 3;
char const X_SYMBOL = 'X';
char const O_SYMBOL = 'O';
int const SLEEP = 1000;
int const WIN_POINTS = 3;
int const TIE_POINTS = 1;

char field[ROWS][COLUMNS] = {};
char playerSymbol = ' ';
char computerSymbol = ' ';
int playerScore = 0;
int computerScore = 0;
int bannedTurns[9] = {};
int index = 0;

int attack();
int defend();
void printField();
void setFieldNull();
void printNumbersField();
void chooseSymbol();
void startGame();
char checkWinLine();
bool checkHasEmpty();
bool makeTurn(int turn, char symbol);
bool protectDiagonal();
bool protectLine();
bool randomCell();
bool attackDiagonal();
bool attackLine();
bool firstTurnAngle();
int firstTurnMiddle(int nextCell);
bool firstTurnCenter();
void printScore(int win);
int defineResults();
void addBannedTurn();
int firstRandomTurn();

int main() {
    char choice = 0;

    while (true) {
        printNumbersField();
        cout << "Would you like to start a new game?" << endl;
        cout << "[Y/N]" << endl;
        cin >> choice;
        if (choice == 89 or choice == 121) {
            setFieldNull();
            chooseSymbol();
            startGame();
        } else if (choice == 78 or choice == 110) {
            break;
        } else ;
    }
    return 0;
}

void printField() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << "|";
            if (field[i][j])
                cout << field[i][j];
            else
                cout << " ";
        }
        cout << "|";
        cout << endl;
    }
}
void printNumbersField() {
    int num = 1;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << "|";
            cout << num;
            num++;
        }
        cout << "|";
        cout << endl;
    }
    cout << endl;
}
void chooseSymbol() {
    int choice = 0;

    system("cls");
    cout << "Choose your symbol, X goes first:" << endl;
    cout << "(1)X" << endl;
    cout << "(2)O" << endl;
    cin >> choice;

    if (choice == 1) {
        playerSymbol = X_SYMBOL;
        computerSymbol = O_SYMBOL;
    } else {
        playerSymbol = O_SYMBOL;
        computerSymbol = X_SYMBOL;
    }
}
void startGame() {
    int win = 0;

    if (playerSymbol == X_SYMBOL) {
        win = defend();
    } else {
        win = attack();
    }
    printScore(win);
}

int attack() {
    int turn = 0;
    int i = 0;
    int firstTurn = 0;
    int nextCell = 0;

    addBannedTurn();
    cout << "Player's turn!" << endl;
    cin >> turn;
    firstTurn = turn;
    while (1) {
        if (makeTurn(turn, playerSymbol)) {

            if(!checkHasEmpty() or checkWinLine())
                break;

            cout << "Computer's turn" << endl;
            Sleep(SLEEP);
            if (firstTurn % 2 == 1 and firstTurn != 5){
                if (attackLine());
                else if(attackDiagonal());
                else if (protectDiagonal());
                else if (protectLine());
                else if (firstTurnAngle()){
                    system("cls");
                    printNumbersField();
                    printField();
                }else
                    randomCell();
            } else if (firstTurn % 2 == 0) {
                if (attackLine());
                else if (attackDiagonal());
                else if (protectDiagonal());
                else if (protectLine());
                else if ((nextCell = firstTurnMiddle(nextCell))) {
                    system("cls");
                    printNumbersField();
                    printField();
                } else
                    randomCell();
            }else{
                if (attackLine());
                else if (attackDiagonal());
                else if (protectDiagonal());
                else if (protectLine());
                else if (firstTurnCenter()) {
                    system("cls");
                    printNumbersField();
                    printField();
                } else{
                    randomCell();
                }
            }
        } else {
            cout << "Try again!" << endl;
        }

        if(!checkHasEmpty() or checkWinLine())
            break;

        cout << "Player's turn!" << endl;
        cin >> turn;
    }
    return defineResults();
}

int defend() {
    int turn = 0;
    int firstTurn = 0;
    int nextCell = 0;

    system("cls");
    printNumbersField();
    printField();
    cout << "Player's turn!" << endl;
    cin >> turn;
    firstTurn = turn;
    while (1) {
        if (makeTurn(turn, playerSymbol)) {
            if(!checkHasEmpty() or checkWinLine())
                break;
            cout << "Computer's turn" << endl;
            Sleep(SLEEP);
            if (firstTurn % 2 == 1 and firstTurn != 5){
                if (attackLine());
                else if(attackDiagonal());
                else if (protectDiagonal());
                else if (protectLine());
                else if (firstTurnAngle()){
                    system("cls");
                    printNumbersField();
                    printField();
                }else
                    randomCell();
            } else if (firstTurn % 2 == 0) {
                if (attackLine());
                else if (attackDiagonal());
                else if (protectDiagonal());
                else if (protectLine());
                else if ((nextCell = firstTurnMiddle(nextCell))) {
                    system("cls");
                    printNumbersField();
                    printField();
                } else
                    randomCell();
            }else{
                if (attackLine());
                else if (attackDiagonal());
                else if (protectDiagonal());
                else if (protectLine());
                else if (firstTurnCenter()) {
                    system("cls");
                    printNumbersField();
                    printField();
                } else{
                    randomCell();
                }
            }
        }
        else {
            cout << "Try again!" << endl;
        }
        if(!checkHasEmpty() or checkWinLine())
            break;
        cout << "Player's turn!" << endl;
        cin >> turn;
    }
    return defineResults();
}
bool checkHasEmpty() {
    bool hasEmpty = false;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (!field[i][j])
                hasEmpty = true;
        }
    }
    return hasEmpty;
}
bool makeTurn(int turn, char symbol) {
    int counter = 1;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (counter == turn and !field[i][j]) {
                field[i][j] = symbol;
                system("cls");
                printNumbersField();
                printField();
                return true;
            }
            counter++;
        }
    }
    return false;
}
char checkWinLine() {
    int winLineCounter = 0;
    char cell = ' ';

    for (int i = 0; i < ROWS; ++i) {
        winLineCounter = 0;
        cell = field[i][0];
        for (int j = 1; j < COLUMNS; ++j) {
            if (cell == field[i][j] and cell)
                winLineCounter += 1;
        }
        if (winLineCounter >= 2)
            return cell;
        winLineCounter = 0;
        cell = field[0][i];
        for (int j = 1; j < COLUMNS; ++j) {
            if (cell == field[j][i] and field[j][i])
                winLineCounter += 1;
        }
        if (winLineCounter >= 2)
            return cell;
    }

    winLineCounter = 0;
    cell = field[0][0];
    for (int i = 1; i < ROWS; ++i) {
        for (int j = 1; j < COLUMNS; ++j) {
            if (i == j and cell == field[i][j] and cell)
                winLineCounter += 1;
        }
    }
    if (winLineCounter >= 2)
        return cell;

    winLineCounter = 0;
    cell = field[0][2];
    for (int i = 1; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS - 1; ++j) {
            if (i + j == 2 and cell == field[i][j] and cell)
                winLineCounter += 1;
        }
    }
    if (winLineCounter >= 2)
        return cell;

    return false;
}
bool protectDiagonal() {
    int j = 0;
    int counter = 0;
    int turn = 1;
    int result = 0;

    for (int i = 0; i < ROWS; ++i) {
        if (field[i][j] == playerSymbol)
            counter++;
        else if (!field[i][j])
            result = turn;
        else
            counter--;
        j++;
        turn += 4;
    }

    if (counter == 2) {
        makeTurn(result, computerSymbol);
        return true;
    }

    j = 2;
    counter = 0;
    turn = 3;
    result = 0;

    for (int i = 0; i < ROWS; ++i) {
        if (field[i][j] == playerSymbol)
            counter++;
        else if (!field[i][j])
            result = turn;
        else
            counter--;
        j--;
        turn += 2;
    }

    if (counter == 2) {
        makeTurn(result, computerSymbol);
        return true;
    }

    return false;
}
bool protectLine() {
    int turn = 1;
    int result = 0;
    int counter = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (field[i][j] == playerSymbol)
                counter++;
            else if (!field[i][j])
                result = turn;
            else
                counter--;
            turn++;
        }
        if (counter == 2) {
            makeTurn(result, computerSymbol);
            return true;
        } else
            counter = 0;
    }

    turn = 1;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (field[j][i] == playerSymbol)
                counter++;
            else if (!field[j][i])
                result = turn;
            else
                counter--;

            turn += 3;
        }
        turn -= 8;
        if (counter == 2) {
            makeTurn(result, computerSymbol);
            return true;
        } else
            counter = 0;
    }
    return false;
}
bool attackLine() {
    int turn = 1;
    int result = 0;
    int counter = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (field[i][j] == computerSymbol)
                counter++;
            else if (!field[i][j])
                result = turn;
            else
                counter--;
            turn++;
        }
        if (counter == 2) {
            makeTurn(result, computerSymbol);
            return true;
        } else
            counter = 0;
    }

    turn = 1;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (field[j][i] == computerSymbol)
                counter++;
            else if (!field[j][i])
                result = turn;
            else
                counter--;

            turn += 3;
        }
        turn -= 8;
        if (counter == 2) {
            makeTurn(result, computerSymbol);
            return true;
        } else
            counter = 0;
    }
    return false;
}
void setFieldNull(){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            field[i][j] = 0;
        }
    }
}
void printScore(int win){
    switch (win) {
        case 1:
            computerScore += WIN_POINTS;
            break;
        case 2:
            playerScore += WIN_POINTS;
            break;
        case 3:
            playerScore += TIE_POINTS;
            computerScore += TIE_POINTS;
            break;
    }
    system("cls");
    cout << "The score" << endl;
    cout << "Player's score is: " << playerScore << endl;
    cout << "Computer's score is: " << computerScore << endl;
    cout << endl;
    Sleep(SLEEP);
}
int defineResults(){
    if (checkWinLine() == computerSymbol) {
        cout << "computer won!" << endl;
        Sleep(SLEEP);
        return 1;
    } else if (checkWinLine() == playerSymbol) {
        cout << "player won!" << endl;
        Sleep(SLEEP);
        return 2;
    } else if (!checkHasEmpty() and !checkWinLine()) {
        cout << "It's a tie!" << endl;
        Sleep(SLEEP);
        return 3;
    }
}
bool randomCell(){
    int turn = 0;
    int i = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 9);

    while (true){
        turn = distr(gen);
        if (makeTurn(turn, computerSymbol))
            break;
    }
    return true;
}
bool attackDiagonal(){
    int j = 0;
    int counter = 0;
    int turn = 1;
    int result = 0;

    for (int i = 0; i < ROWS; ++i) {
        if (field[i][j] == computerSymbol)
            counter++;
        else if (!field[i][j])
            result = turn;
        else
            counter--;
        j++;
        turn += 4;
    }

    if (counter == 2) {
        makeTurn(result, computerSymbol);
        return true;
    }

    j = 2;
    counter = 0;
    turn = 3;
    result = 0;

    for (int i = 0; i < ROWS; ++i) {
        if (field[i][j] == computerSymbol)
            counter++;
        else if (!field[i][j])
            result = turn;
        else
            counter--;
        j--;
        turn += 2;
    }

    if (counter == 2) {
        makeTurn(result, computerSymbol);
        return true;
    }
    return false;
}
bool firstTurnAngle(){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if ((i == 2 or i == 0) and (j == 2 or j == 0) and !field[1][1]){
                field[1][1] = computerSymbol;
                return true;
            }
        }
    }
    if (!field[0][1] and field[2][0] and field[1][2]) {
        field[0][1] = computerSymbol;
        return true;
    } else if (!field[0][1] and field[2][2] and field[1][0]) {
        field[0][1] = computerSymbol;
        return true;
    } else if (!field[1][2] and field[2][0] and field[0][1]) {
        field[1][2] = computerSymbol;
        return true;
    } else if (!field[2][1] and field[0][0] and field[1][2]) {
        field[2][1] = computerSymbol;
        return true;
    } else if (!field[1][2] and field[2][1] and field[0][0]) {
        field[1][2] = computerSymbol;
        return true;
    } else if (!field[1][0] and field[2][1] and field[0][2]) {
        field[1][0] = computerSymbol;
        return true;
    } else if (!field[1][0] and field[2][2] and field[0][1]) {
        field[1][0] = computerSymbol;
        return true;
    } else if (!field[2][1] and field[0][2] and field[1][0]) {
        field[2][1] = computerSymbol;
        return true;
    }
    return false;
}
int firstTurnMiddle(int nextCell){
    if (field[2][1] == playerSymbol and nextCell == 0) {
        field[0][1] = computerSymbol;
        nextCell = 7;
        return nextCell;
    } else if (field[1][2] == playerSymbol and nextCell == 0) {
        field[1][0] = computerSymbol;
        nextCell = 9;
        return nextCell;
    } else if (field[1][0] == playerSymbol and nextCell == 0) {
        field[1][2] = computerSymbol;
        nextCell = 1;
        return nextCell;
    } else if (field[0][1] == playerSymbol and nextCell == 0) {
        field[2][1] = computerSymbol;
        nextCell = 3;
        return nextCell;
    } else if(nextCell){
        return makeTurn(nextCell, computerSymbol);
    }
    return 0;
}
bool firstTurnCenter(){
    if (field[1][1] and !field[0][0]) {
        field[0][0] = computerSymbol;
        return true;
    } else if (field[1][1] and !field[2][2]) {
        field[2][2] = computerSymbol;
        return true;
    } else if (field[1][1] and !field[0][2] and field[2][1] != playerSymbol) {
        field[0][2] = computerSymbol;
        return true;
    } else if (field[1][1] and !field[2][0]) {
        field[2][0] = computerSymbol;
        return true;
    }
    return false;
}
void addBannedTurn(){
    system("cls");
    bannedTurns[index] = firstRandomTurn();
    index++;
}
int firstRandomTurn(){
    int turn = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 9);

    while (true){
        bool isUsed = 1;

        while(isUsed){
            isUsed = 0;
            turn = distr(gen);
            for (int i : bannedTurns) {
                if (i == turn){
                    isUsed = 1;
                    break;
                }
            }
        }

        if (makeTurn(turn, computerSymbol))
            break;
    }
    return turn;
}