#include <iostream>
#include <string>

using namespace std;

const int N = 4096;
const int AMOUNT_OF_WORDS = 3;
const int N_OF_PREPOSITIONS = 11;
const int N_OF_ARTICLES = 3;
const char SYMBOL_NULL = '\0';
const char SYMBOL_WHITESPACE = ' ';

string text = "Pheochromocytoma and paraganglioma are rare tumors arising from adrenal medullary "
              "chromaffin cells or extraadrenal sympathetic neurons, respectively. In most other respects, "
              "they are similar and are referred to collectively in this article as Pheo. "
              "Approximately 800 new cases of Pheo are diagnosed annually in the United States. "
              "Carcinoid is also a neuroendocrine tumor and shares several cytochemical features with Pheo. "
              "For the treatment of Pheo and carcinoid, surgery, chemotherapy, and radiotherapy are used. "
              "Once metastasis has occurred, treatment has met with limited success, and these treatments are themselves the cause of untoward side-effects. "
              "A promising treatment, originally developed by investigators at the University of Michigan, is the use of metaiodobenzylguanidine (MIBG) labeled with iodine131. "
              "1–8 MIBG is accumulated by neuroendocrine cancer cells via the norepinephrine transporter. "
              "Beta-particles emitted by 131I deliver energy that is cytotoxic; "
              "it is the combination of 131I cytotoxicity and MIBG target specificity that results in a selective, potentially lethal dose to tumor cells. "
              "Iodine-131 also emits gamma photons that can be detected by using a gamma camera for imaging the distribution of the radiopharmaceutical ";

int carriage = 0;
bool notTheEnd = true;
string shinglesText[N] = {};
string shinglesFragment[N] = {};
string separators = " ,!?:.\n\t-(){}[];";
string articles[N_OF_ARTICLES] = {"AN", "THE", "A"};
string prepositions[N_OF_PREPOSITIONS] = {"AT", "BY", "AS", "IN",
                                        "FROM", "INTO", "TO",
                                        "FOR", "FROM", "ON", "OF"};

// Plagiarism check algorithm
int checkPlagiarism(string text, string fragment);
void makeShinglesArray(string text, string shingles[], int index);
bool compareShingles(string shingleText, string shingleFragment);
int getStringLength(string str);
double getTotalCoincidence(string fragment, string text);
int findCoincidence(int amountOfShinglesText, string shingle);
void resetShingles(string shingle[N]);
int roundedToInt(double num);
int skipOneWord(string str, int index);
int getAmountOfShingles(string shingle[]);
string makeShingleOfFragment(string fragment);
void changeFragment(string &fragment, bool deletedShingle);
void removeShingle(string &fragment);
void removeFirstWord(string &text);
double calculateResultPlagiarism(string &fragment, string text);
// Text preprocessing algorithm
void cleanStr(string &str);
void replaceSeparatorsWithWhitespaces(string &str);
bool isSeparator(char sym);
void removeExcessSpaces(string &str);
void removeArticles(string &str);
void removePrepositions(string &str);
void capitalize(string &str);
void deleteSubstring(string &str, string &subStr);
void deleteNonLatinSymbols(string &str);
void deleteDuplicates(string &str);
void copyStr(string &str1, string str2);
bool isEqual(string str1, string str2);
void concatStr(string &str1, string str2);

int main() {
    string fragment = "Carcinoid is also tumor and shares several cytochemical features with Pheo.";
    int choice = 0;

    cout << text << endl;
    cout << endl;

    while (true) {
        cout << "1) Verify new fragment \n2) Exit" << endl;
        cin >> choice;

        if (choice != 1) {
            break;
        } else {
            cout << "Input your text:" << endl;
            getline(cin, fragment);
            getline(cin, fragment);
            cout << "Your plagiarism percent: " << checkPlagiarism(text, fragment) << "%" << endl;
            resetShingles(shinglesText);
            resetShingles(shinglesFragment);
            carriage = 0;
            notTheEnd = true;
        }
    }

    return 0;
}

int checkPlagiarism(string text, string fragment) {
    cleanStr(text);
    cleanStr(fragment);

    return roundedToInt(calculateResultPlagiarism(fragment, text));
}

void cleanStr(string &str) {
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
        if (str[counter] == SYMBOL_NULL) {
            break;
        }

        counter++;
    }

    return counter + 1;
}

bool isSeparator(char sym) {
    for (int i = 0; separators[i] != SYMBOL_NULL; i++) {
        if (sym == separators[i]) {
            return true;
        }
    }

    return false;
}

void replaceSeparatorsWithWhitespaces(string &str) {
    for (int i = 0; str[i] != SYMBOL_NULL; i++) {
        if (isSeparator(str[i])) {
            str[i] = SYMBOL_WHITESPACE;
        }
    }
}

void removeExcessSpaces(string &str) {
    string stack = "";
    int stackLength = 0;
    int spaceCounter = 0;

    while (str[spaceCounter] == SYMBOL_WHITESPACE) {
        spaceCounter++;
    }

    for (int i = spaceCounter; str[i] != SYMBOL_NULL; i++) {
        if (str[i] == SYMBOL_WHITESPACE && str[i + 1] == SYMBOL_WHITESPACE) {
            continue;
        } else {
            stack += str[i];
        }
    }

    stackLength = getStringLength(stack);
    if (stack[stackLength - 1] == SYMBOL_WHITESPACE) {
        stack[stackLength - 1] = SYMBOL_NULL;
    }

    copyStr(str, stack);
}

void capitalize(string &str) {
    for (int i = 0; str[i] != SYMBOL_NULL; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

void deleteSubstring(string &str, string &subStr) {
    string tempWord = "";
    string stack = "";

    for (int i = 0; str[i] != SYMBOL_NULL; i++) {
        if (str[i] != SYMBOL_WHITESPACE) {
            tempWord += str[i];
        } else if (!isEqual(tempWord, subStr)) {
            stack += tempWord + " ";
            tempWord = "";
        } else {
            tempWord = "";
        }
    }

    if (!isEqual(tempWord, subStr)) {
        concatStr(stack, tempWord);
        tempWord = "";
    }

    copyStr(str, stack);
}

void removeArticles(string &str) {
    for (int i = 0; i < N_OF_ARTICLES; i++) {
        deleteSubstring(str, articles[i]);
    }
}

void removePrepositions(string &str) {
    for (int i = 0; i < N_OF_PREPOSITIONS; i++) {
        deleteSubstring(str, prepositions[i]);
    }
}

void deleteDuplicates(string &str) {
    string tempWord = "";
    string preTempWord = "";
    string stack = "";

    for (int i = 0; str[i] != SYMBOL_NULL; i++) {
        if (str[i] != SYMBOL_WHITESPACE) {
            tempWord += str[i];
        } else if (str[i] == SYMBOL_WHITESPACE) {
            if (!isEqual(tempWord, preTempWord)) {
                stack += tempWord + " ";
            }
            preTempWord = tempWord;
            tempWord = "";
        }

        if (str[i + 1] == SYMBOL_NULL) {
            stack += tempWord;
        }
    }

    copyStr(str, stack);
}

void deleteNonLatinSymbols(string &str) {
    string tempWord = "";
    string stack = "";

    for (int i = 0; str[i] != SYMBOL_NULL; i++) {
        if (str[i] != ' ') {
            tempWord += str[i];
            if ((str[i] < 'A' || str[i] > 'Z') && str[i] != SYMBOL_NULL) {
                tempWord = "";
                continue;
            }
        } else if (str[i] == ' ') {
            stack += tempWord + " ";
            tempWord = "";
        }

        if (str[i + 1] == SYMBOL_NULL) {
            concatStr(stack, tempWord);
        }
    }

    copyStr(str, stack);
}

bool isEqual(string str1, string str2) {
    int len1 = getStringLength(str1);
    int len2 = getStringLength(str2);
    bool isSameStrings = false;

    if (len1 == len2) {
        isSameStrings = true;
        for (int i = 0; str1[i] != SYMBOL_NULL; i++) {
            if (str1[i] != str2[i]) {
                isSameStrings = false;
                break;
            }
        }
    }

    return isSameStrings;
}

void makeShinglesArray(string text, string shingles[], int index) {
    int spaces = 0;
    int iShingle = 0;
    int i = 0;

    i = index;
    while (text[i] != SYMBOL_NULL) {
        spaces = 0;

        while (spaces < AMOUNT_OF_WORDS) {
            if (text[i] == SYMBOL_WHITESPACE) {
                while (text[i + 1] == SYMBOL_WHITESPACE)
                    i++;
                spaces++;
            } else if (text[i] == SYMBOL_NULL) {
                break;
            } else {
                shingles[iShingle] += text[i];
            }
            i++;
        }

        iShingle++;
    }

    if (text[i - 1] == SYMBOL_WHITESPACE) {
        spaces--;
    }
    if (spaces < AMOUNT_OF_WORDS - 1) {
        shingles[iShingle - 1] = "";
    }
}

bool compareShingles(string shingleText, string shingleFragment) {
    if (getStringLength(shingleText) != getStringLength(shingleFragment)){
        return false;
    }

    for (int i = 0; shingleFragment[i] != 0; ++i) {
        if (shingleFragment[i] != shingleText[i]){
            return false;
        }
    }

    return true;
}

double getTotalCoincidence(string fragment, string text) {
    double total = 0.0;
    int plagiarism = 0;
    int amountOfShinglesText = 0;
    int indexText = 0;
    int indexFragment = 0;
    int totalAmountOfShingles = 0;
    string shingle = "";
    bool deletedShingle = false;

    makeShinglesArray(fragment, shinglesFragment, indexFragment);

    while (notTheEnd) {
        shingle = makeShingleOfFragment(fragment);

        for (int i = 0; i < AMOUNT_OF_WORDS; ++i) {
            makeShinglesArray(text, shinglesText, indexText);
            amountOfShinglesText = getAmountOfShingles(shinglesText);
            plagiarism = findCoincidence(amountOfShinglesText, shingle);
            total += plagiarism;
            resetShingles(shinglesText);
            indexText = skipOneWord(text, indexText);

            if (plagiarism) {
                deletedShingle = true;
                break;
            }
        }

        changeFragment(fragment, deletedShingle);
        shingle = "";
        deletedShingle = false;
    }

    return total;
}

void copyStr(string &str1, string str2) {
    char copy[N] = {};
    int i = 0;

    for (i = 0; str2[i] != SYMBOL_NULL; ++i) {
        copy[i] = str2[i];
    }

    copy[i] = SYMBOL_NULL;
    str1 = copy;
}

void concatStr(string &str1, string str2) {
    char copy[N] = {};
    int i = 0;
    int j = 0;

    for (i = 0; str1[i] != SYMBOL_NULL; i++) {
        copy[i] = str1[i];
    }

    for (j = 0; str2[j] != SYMBOL_NULL; j++) {
        copy[i] = str2[j];
        i++;
    }

    copy[i] = SYMBOL_NULL;
    str1 = copy;
}

int skipOneWord(string str, int index) {
    int i = index;

    while (str[i] != SYMBOL_WHITESPACE) {
        i++;
    }

    while (str[i] == SYMBOL_WHITESPACE){
        i++;
    }

    return i;
}

int findCoincidence(int amountOfShinglesText, string shingle) {
    int plagiarism = 0;

    for (int j = 0; j < amountOfShinglesText; ++j) {
        if (compareShingles(shinglesText[j], shingle)) {
            plagiarism++;
            break;
        }
    }

    return plagiarism;
}

void resetShingles(string shingle[N]) {
    for (int i = 0; i < N - 1; ++i) {
        shingle[i] = "";
    }
}

int roundedToInt(double num) {
    int result = 0;
    result = num + 0.5;
    return result;
}

int getAmountOfShingles(string shingle[]) {
    int counter = 0;
    while (shingle[counter] != "") {
        counter++;
    }

    return counter;
}

string makeShingleOfFragment(string fragment) {
    string shingle;
    int spaces = 0;

    while (fragment[carriage] == SYMBOL_WHITESPACE) {
        carriage++;
    }

    spaces = 0;
    while (spaces < AMOUNT_OF_WORDS) {
        if (fragment[carriage] == SYMBOL_WHITESPACE) {
            while (fragment[carriage + 1] == SYMBOL_WHITESPACE) {
                carriage++;
            }

            spaces++;
        } else if (fragment[carriage] == SYMBOL_NULL) {
            notTheEnd = false;
            break;
        } else {
            shingle += fragment[carriage];
        }

        carriage++;
    }

    return shingle;
}

void changeFragment(string &fragment, bool deletedShingle) {
    if (!deletedShingle) {
        removeFirstWord(fragment);
    } else {
        removeShingle(fragment);
    }
}

void removeFirstWord(string &text) {
    int index = 0;

    while (text[index] == SYMBOL_WHITESPACE) {
        index++;
    }

    while (text[index] != SYMBOL_WHITESPACE) {
        text[index] = SYMBOL_WHITESPACE;
        index++;
    }

    carriage = index;
}

void removeShingle(string &fragment) {
    for (int i = 0; i < carriage - 1; ++i) {
        fragment[i] = SYMBOL_WHITESPACE;
    }

    carriage = 0;
}

double calculateResultPlagiarism(string &fragment, string text) {
    double result = 0.0;
    double plagiarism = 0.0;
    int amountOfShingles = 0;

    plagiarism = getTotalCoincidence(fragment, text);
    amountOfShingles = getAmountOfShingles(shinglesFragment);

    if (amountOfShingles == 0) {
        result = 0;
    } else {
        result = plagiarism / amountOfShingles * 100.0;
    }

    return result;
}