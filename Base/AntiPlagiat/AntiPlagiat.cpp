#include <iostream>

using namespace std;

string text = "";

int checkPlagiarism(string text, string fragment);

void removePunctuationMarks(string text, string fragment);

void removeExcessSpaces(string text, string fragment);

void removeArticles(string text, string fragment);

void removePrepositions(string text, string fragment);

void setUpperRegister(string text, string fragment);

bool checkIsCopy();

int main() {
    string fragment = "";
    int choice = 0;

    cout << text;
    while (true) {
        cout << "1) Verify new fragment \n2) Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Input your text:" << endl;
            cin >> fragment;
            checkPlagiarism(text, fragment);
        } else {
            break;
        }
    }


    return 0;
}

int checkPlagiarism(string text, string fragment) {

}
