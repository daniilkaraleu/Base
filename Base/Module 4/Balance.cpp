#include <iostream>

using namespace std;

char const ASCII_OPEN_BLOCK_BRACES = '{';
char const ASCII_CLOSE_BLOCK_BRACES = '}';
char const ASCII_CLOSE_PARENTHESIS = ')';
char const ASCII_OPEN_PARENTHESIS = '(';
char const ASCII_CLOSE_SQUARE_BRACES = ']';
char const ASCII_OPEN_SQUARE_BRACES = '[';

int const N = 2048;

char pullOfBraces[N] = "";

int countBraces(char text[]);
int getStringLength(char str[]);
int lastBraceOut(int index, char c);
bool checkBalance(int index);
bool checkOutOfRange(char text[]);


int main() {
    char text[N] = "([])()";

    if (checkOutOfRange(text))
        return -1;
    checkBalance(countBraces(text));

    return 0;
}

bool checkBalance(int index) {
    if (index == 0) {
        cout << "Balanced!";
        return true;
    } else
        cout << "Not balanced!";

    return false;
}

int getStringLength(char str[]) {
    int counter = 0;

    while (true) {
        if (str[counter] == 0)
            break;
        counter++;
    }
    return counter + 1;
}

int countBraces(char text[]) {
    int index = 0;
    int lastBrace = 0;

    for (int i = 0; i < getStringLength(text); ++i) {
        if (text[i] == ASCII_OPEN_SQUARE_BRACES or text[i] == ASCII_OPEN_PARENTHESIS or
            text[i] == ASCII_OPEN_BLOCK_BRACES) {
            pullOfBraces[index] = text[i];
            index++;
        } else if (text[i] == ASCII_CLOSE_SQUARE_BRACES) {
            index--;
            lastBrace = lastBraceOut(index, ASCII_CLOSE_SQUARE_BRACES);
        } else if (text[i] == ASCII_CLOSE_PARENTHESIS) {
            index--;
            lastBrace = lastBraceOut(index, ASCII_CLOSE_PARENTHESIS);
        } else if (text[i] == ASCII_CLOSE_BLOCK_BRACES) {
            index--;
             lastBrace = lastBraceOut(index, ASCII_CLOSE_BLOCK_BRACES);
        } else
            continue;

        if (lastBrace)
            return -1;
    }
    if (index)
        return -1;
    else
        return 0;
}

int lastBraceOut(int index, char c) {
    if (pullOfBraces[index] == ASCII_OPEN_BLOCK_BRACES and c == ASCII_CLOSE_BLOCK_BRACES);
    else if (pullOfBraces[index] == ASCII_OPEN_PARENTHESIS and c == ASCII_CLOSE_PARENTHESIS);
    else if (pullOfBraces[index] == ASCII_OPEN_SQUARE_BRACES and c == ASCII_CLOSE_SQUARE_BRACES);
    else
        return 1;
    pullOfBraces[index] = '\0';
    return 0;
}

bool checkOutOfRange(char text[]){
    if (getStringLength(text) <= N)
        return false;
    else{
        cout << "Error! Out of range!";
        return true;
    }
}
