#include <iostream>
#include <string>
using namespace std;


int const AMOUNT_OF_WORDS = 3;
string shinglesText[100] = {};
string shinglesFragment[100] = {};

int checkPlagiarism(string text, string fragment);
void removePunctuationMarks(string text, string fragment);
void removeExcessSpaces(string text, string fragment);
void removeArticles(string text, string fragment);
void removePrepositions(string text, string fragment);
void setUpperRegister(string text, string fragment);
bool checkIsCopy();
int makeShingles(string text, string shingles[]);
bool compareShingles(string shingleText, string shingleFragment);
int getStringLength(string str);
double countPlagiarism(int amountOfShinglesText, int amountOfShinglesFragment);
void printPlagiarism(string fragment);

int main() {
    string fragment = "";
    int choice = 0;

    while (true) {
        cout << "1) Verify new fragment \n2) Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Input your text:" << endl;
            getline(cin, fragment);
            getline(cin, fragment);
            checkPlagiarism(text, fragment);
        } else {
            break;
        }
    }


    return 0;
}

int checkPlagiarism(string text, string fragment) {





    printPlagiarism(fragment);
    return 0;
}

int makeShingles(string text, string shingles[]) {
    int spaces = 0;
    int iShingle = 0;

    for (int i = 0; text[i] != '\0';) {
        if (text[i] == '\0')
            break;
        for (int spaces = 0; spaces < AMOUNT_OF_WORDS;) {
            if (text[i] == ' ')
                spaces++;
            else if (text[i] == '\0')
                break;
            else
                shingles[iShingle] += text[i];

            i++;
        }
        iShingle++;
    }
    return iShingle;
}

bool compareShingles(string shingleText, string shingleFragment) {
    if (getStringLength(shingleText) != getStringLength(shingleFragment))
        return false;
    for (int i = 0; shingleFragment[i] != 0; ++i) {
        if (shingleFragment[i] != shingleText[i])
            return false;
    }
    return true;
}

int getStringLength(string str) {
    int counter = 0;

    while (true) {
        if (str[counter] == '\0')
            break;
        counter++;
    }
    return counter + 1;
}

double countPlagiarism(int amountOfShinglesText, int amountOfShinglesFragment) {
    double plagiarism = 0;

    for (int i = 0; i < amountOfShinglesText; ++i) {
        for (int j = 0; j < amountOfShinglesFragment; ++j) {
            if (compareShingles(shinglesText[j], shinglesFragment[i]))
                plagiarism++;
        }
    }
    return plagiarism;
}

void printPlagiarism(string fragment) {
    double plagiarism = 0;
    int amountOfShinglesText = 0;
    int amountOfShinglesFragment = 0;

    amountOfShinglesText = makeShingles(text, shinglesText);
    amountOfShinglesFragment = makeShingles(fragment, shinglesFragment);

    plagiarism = countPlagiarism(amountOfShinglesText, amountOfShinglesFragment) / amountOfShinglesFragment;
    plagiarism *= 100.0;
    cout << "Your plagiarism percent: " << plagiarism << "%" << endl;
}
