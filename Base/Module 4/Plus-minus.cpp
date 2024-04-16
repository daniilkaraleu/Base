#include <iostream>

using namespace std;

int const RESULT_LENGTH = 10;
char result[RESULT_LENGTH] = "";

void convertToSymbol(int n, int indexIncr, char s);
int charToInt(char s);
void printConvertedString(char str[]);
int getStringLength(char str[]);
bool symbolIsDigit(char s);
bool checkOutOfRange(char text[]);


int main() {
    char text[] = "19";

    if (checkOutOfRange(text)){
        cout << "Error! Out of range!";
        return -1;
    } else {
        printConvertedString(text);
        return 0;
    }
}

int charToInt(char s){
    int num = 0;

    num = s - '0';

    return num;
}

void convertToSymbol(int n, int index, char s){
    for (int i = 0; i < n; ++i) {
        result[index + i] = s;
    }
}

void printConvertedString(char str[]){
    int n = 0;
    int index = 0;

    for (int i = 0; i < getStringLength(str); ++i) {
        if (symbolIsDigit(str[i])) {
            n = charToInt(str[i]);
            if (n % 2 == 0)
                convertToSymbol(n, index , '+');
            else
                convertToSymbol(n, index , '-');
            index += n;
        } else {
            result[index] = str[i];
            index++;

        }
    }
    result[index] = '\0';
    cout << result;
}

int getStringLength(char str[]){
    int counter = 0;

    while(true){
        if (str[counter] == 0)
            break;
        counter++;
    }
    return counter + 1;
}
bool symbolIsDigit(char s){
    if (s <= '9' and s >= '0')
        return true;
    return false;
}

bool checkOutOfRange(char text[]){
    int predictedLength = 0;

    for (int i = 0; i < getStringLength(text); ++i) {
        if (isdigit(text[i]))
            predictedLength += charToInt(text[i]) - 1;
    }
    predictedLength += getStringLength(text);

    if (predictedLength <= RESULT_LENGTH)
        return false;
    else
        return true;
}
