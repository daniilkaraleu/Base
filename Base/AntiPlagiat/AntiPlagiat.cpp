#include <iostream>
#include <string>
using namespace std;


string text = "abc fg6 at the moment hoi hoi; k";
string separators = " ,!?:.\n\t-(){}[];"; 
int const N = 4096;



int const AMOUNT_OF_WORDS = 3;
string shinglesText[100] = {};
string shinglesFragment[100] = {};

int checkPlagiarism(string text, string fragment);
int makeShingles(string text, string shingles[]);
bool compareShingles(string shingleText, string shingleFragment);
int getStringLength(string str);
double countPlagiarism(int amountOfShinglesText, int amountOfShinglesFragment);
void printPlagiarism(string fragment);

void cleanStr(string& str); 
void replaceSeparatorsWithWhitespaces(string& str);
bool isSeparator(char sym); 
void removeExcessSpaces(string& str);
void removeArticles(string& str); 
void removePrepositions(string& str); 
void capitalize(string& str); 
void deleteSubstring(string& str, string& subStr); 
void deleteNonLatinSymbols(string& str); 
void deleteDuplicates(string& str); 
void copyStr(string& str1, string str2);
bool isSame(string str1, string str2);
void concatStr(string& str1, string str2);

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


int checkPlagiarism(string text, string fragment){
    cleanStr(text); 
    cleanStr(fragment); 
 
//    cout << text << endl;
//    cout << fragment << endl;

    printPlagiarism(fragment);

    return 0;
}

void cleanStr(string& str) {

    replaceSeparatorsWithWhitespaces(str);
    removeExcessSpaces(str); 
    capitalize(str); 
    removeArticles(str); 
    removePrepositions(str); 
    deleteDuplicates(str); 
    deleteNonLatinSymbols(str); 
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

bool isSeparator(char sym) { 
    for (int i = 0; separators[i] != '\0'; i++) { 
        if (sym == separators[i]) 
            return true; 
    } 
    return false; 
} 
 
void replaceSeparatorsWithWhitespaces(string& str) {
    for (int i = 0; str[i] != '\0'; i++) { 
        if (isSeparator(str[i])) 
            str[i] = ' '; 
    } 
} 
 
void removeExcessSpaces(string& str) { 
    string stack = ""; 
 
    int spaceCounter = 0; 
    while (str[spaceCounter] == ' ') { 
        spaceCounter++; 
    } 
     
    for (int i = spaceCounter; str[i] != '\0'; i++) { 
        if (str[i] == ' ' and str[i + 1] == ' ') 
            continue; 
        else 
            stack += str[i]; 
    } 
    int stackLength = getStringLength(stack); 
    if (stack[stackLength - 1] == ' ') 
        stack[stackLength - 1] = '\0'; 
 
    copyStr(str, stack); 
} 
 
void capitalize(string& str) { 
    for (int i = 0; str[i] != '\0'; i++) { 
        if (str[i] >= 'a' and str[i] <= 'z') { 
            str[i] = str[i] - 32; 
        } 
    } 
} 
 
void deleteSubstring(string& str, string& subStr) { 
    string tempWord = ""; 
    string stack = ""; 
    for (int i = 0; str[i] != '\0'; i++) { 
        if (str[i] != ' ') { 
            tempWord += str[i]; 
        } 
        else if (!isSame(tempWord, subStr)) { 
            stack += tempWord + " "; 
            tempWord = ""; 
        } 
        else { 
            tempWord = ""; 
        } 
    } 
    if (!isSame(tempWord, subStr)) { 
        concatStr(stack, tempWord); 
        tempWord = ""; 
        } 
 
    copyStr(str, stack); 
} 
 
void removeArticles(string& str) { 
    int const nOfArticles = 3;

    string articles[nOfArticles] = {"AN", "THE", "A"};
    for (int i = 0; i < nOfArticles; i++){ 
        deleteSubstring(str, articles[i]); 
    } 
} 
 
void removePrepositions(string& str) { 
    int const nOfPrepositins = 11;
    string prepositions[nOfPrepositins] = {"AT", "BY", "AS", "IN", "FROM", "INTO", "AT", "FOR", "FROM", "ON", "OF"}; 
    for (int i = 0; i < nOfPrepositins; i++){ 
        deleteSubstring(str, prepositions[i]); 
    } 
} 
 
void deleteDuplicates(string& str) { 
    string tempWord = ""; 
    string preTempWord = ""; 
    string stack = ""; 
    for (int i = 0; str[i] != '\0'; i++) { 
        if (str[i] != ' ') { 
            tempWord += str[i]; 
        } 
        else if (str[i] == ' ') { 
            if (tempWord != preTempWord) { 
                stack += tempWord + " "; 
            }            
            preTempWord = tempWord; 
            tempWord = ""; 
        } 
        if (str[i + 1] == '\0') { 
            stack += tempWord; 
        } 
    } 
    copyStr(str, stack); 
} 
 
void deleteNonLatinSymbols(string& str) { 
    string tempWord = ""; 
    string stack = ""; 
    for (int i = 0; str[i] != '\0'; i++) { 
        if (str[i] != ' ') { 
            tempWord += str[i]; 
            if (str[i] < 'A' or str[i] > 'Z') { 
                tempWord = ""; 
                continue; 
            } 
        } 
        else if (str[i] == ' ') { 
            stack += tempWord + " "; 
            tempWord = ""; 
        } 
        if (str[i + 1] == '\0') { 
            concatStr(stack, tempWord); 
        } 
    } 
    copyStr(str, stack); 
}

bool isSame(string str1, string str2) {
    int len1 = getStringLength(str1);
    int len2 = getStringLength(str2);
    bool isSameStrings = false;

    if (len1 == len2) {
        isSameStrings = true;
        for (int i = 0; str1[1] != '\0'; i++) {
            if (str1[i] != str2[i])
                isSameStrings = false;
            break;
        }
    }
    return isSameStrings;
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

void copyStr(string& str1, string str2) {
    char copy[N] = {};
    int i = 0;
    for(i = 0; str2[i] != '\0'; ++i) {
        copy[i] = str2[i];
    }
    copy[i] = '\0';
    str1 = copy;
}

void concatStr(string& str1, string str2) {
    char copy[N] = {};
    int i = 0;
    int j = 0;
    for (i = 0; str1[i] != '\0'; i++) {
        copy[i] = str1[i];
    }
    for (j = 0; str2[j] != '\0'; j++) {
        copy[i] = str2[j];
        i++;
    }
    copy[i] = '\0';
    str1 = copy;    
}