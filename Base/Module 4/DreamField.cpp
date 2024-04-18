//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//
//int const LENGTH = 2000;
//char const SYMBOL = '-';
//int const SLEEP = 2000;
//int const AMOUNT_OF_WORDS = 4;
//int const SYMBOL_DIFFERENCE = 32;
//
//char container[AMOUNT_OF_WORDS][LENGTH] = {"Multiplet", "Migration", "Exciton", "Dissipation"};
//char questions[AMOUNT_OF_WORDS][LENGTH] = {"What\'s the name of the peak on H-NMR spectra for t-butanol?",
//                                           "One of te ways of mass transfer for ions in solution under under current",
//                                           "A quasiparticle, which is an electronic excitation in a dielectric, semiconductor or metal, migrating throughout the crystal and not associated with the transfer of electric charge and mass.",
//                                           "The transition of part of the energy of ordered processes (kinetic energy of a moving body, electric current energy, etc.) into the energy of disordered processes, and eventually into heat."};
//char jokes[AMOUNT_OF_WORDS][LENGTH] = {
//        "Field meeting of the \"Field of Miracles\". The first three on the reel are: private, lieutenant and general. Yakubovich gives a task - a musical instrument with five letters. The private spins the drum, typing the letter \"T\".\n"
//        "- There is no such letter in this word, the move goes to the lieutenant.\n"
//        "This is also the letter \"T\".\n"
//        "- Lieutenant, you need to be careful, there is no such number in this word.\n"
//        "General, you will name a letter or just a word.\n"
//        "- I will say the word right away, but first I want to apologize for the idiocy of my subordinates. This word is \"TAMBER!\"",
//        "Three from the Arctic came to participate in the TV show \"Field of Dreams\".\n"
//        "- What will you insure yourself against? - asks Leonid Yakubovich.\n"
//        "\"I started playing and didn\'t break the drum,\" the first one answers.\n"
//        "\"I guessed all the letters, but couldn\'t name the word,\" said the second one.\n"
//        "\"I guessed all the letters, named the word, but forgot to say hello to my fellow villagers,\" answered the third.\n"
//        "\n"
//        "The game \"Field of Dreams\" is playing. The player receives a prize.\n"
//        "- I\'ll take the prize!\n"
//        "Yakubovich:\n"
//        "- I give you one hundred thousand rubles.\n"
//        "- Prize!\n"
//        "- Two hundred thousand!\n"
//        "- Prize!\n"
//        "- OK then. I give you three hundred thousand and the prize is yours if, without looking, you can guess with your hand what\'s in the box.\n"
//        "The player agrees and puts his hand into the box. He pulls it out sharply, screaming: \"Damn!\"\n"
//        "Yakubovich:\n"
//        "- But they didn\'t guess right. This is a Philips trap.",
//        "Plays as a truck driver in the Field of Dreams. Yakubovich asks a question:\n"
//        "- Blood-sucking insect from 3 letters!!\n"
//        "The player spins the reel and calls the letter M.\n"
//        "Yakubovich:\n"
//        "- There is such a letter, and the first one. Will you spin the drum or say a word?\n"
//        "Player:\n"
//        "- I\'ll say the word!!!!\n"
//        "Yakubovich:\n"
//        "- So, this is.......\n"
//        "Player:\n"
//        "- This is a COP!!!!!",
//        "Field of Dreams in the USA. Yakubovich: \"A simple question. The name of the new US President. Three letters.\" 100 thousand residents of Florida still cannot answer."};
//char hiddenWord[LENGTH] = "";
//int wordIndex = -1;
//
//
//int checkTheLetter(char l, int index);
//void startNewGame();
//int getStringLength(char str[]);
//void hideWord();
//void openLetters(char l);
//bool checkClosedLetters();
//char toUpperCase(char c);
//void printStartScreen();
//
//int main() {
//    char choice = ' ';
//
//    while (true) {
//        system("cls");
//        cout << "Would you like to start a New Game?" << endl;
//        cout << "[Y|N]" << endl;
//        cin >> choice;
//        wordIndex = rand() % AMOUNT_OF_WORDS;
//        if (choice == 'Y' or choice == 'y') {
//            startNewGame();
//        } else if (choice == 'N' or choice == 'n') {
//            break;
//        } else
//            continue;
//    }
//
//    return 0;
//}
//
//void startNewGame() {
//    char letter = ' ';
//    int index = 0;
//    bool guessed = true;
//
//    printStartScreen();
//    while (guessed) {
//        guessed = false;
//        cout << "What's your letter [a..z]?" << endl;
//        cin >> letter;
//        openLetters(letter);
//        cout << questions[wordIndex] << endl;
//        cout << hiddenWord << endl;
//        guessed = checkClosedLetters();
//    }
//    system("cls");
//    cout << "You've guessed the word!" << endl;
//    cout << hiddenWord;
//    Sleep(SLEEP);
//}
//
//int checkTheLetter(char l, int index) {
//    for (int i = index; container[wordIndex][i] != 0; ++i) {
//        if (toUpperCase(l) == toUpperCase(container[wordIndex][i]) and toUpperCase(l) != toUpperCase(hiddenWord[i])) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int getStringLength(char str[]) {
//    int counter = 0;
//
//    while (true) {
//        if (str[counter] == 0)
//            break;
//        counter++;
//    }
//    return counter + 1;
//}
//
//void hideWord() {
//    int i = 0;
//    for (; i < getStringLength(container[wordIndex]) - 1; ++i) {
//        hiddenWord[i] = SYMBOL;
//    }
//    hiddenWord[i] = container[wordIndex][i];
//}
//
//void openLetters(char l) {
//    int index = 0;
//    bool wasOpened = false;
//
//    while (true) {
//        index = checkTheLetter(l, index);
//        if (index == -1 and wasOpened)
//            break;
//        else if (index == -1 and !wasOpened) {
//            system("cls");
//            cout << "There is no such letter" << endl;
//            cout << endl;
//            break;
//        } else {
//            system("cls");
//            hiddenWord[index] = toUpperCase(container[wordIndex][index]);
//            wasOpened = true;
//            cout << "Correct!" << endl;
//            index++;
//        }
//    }
//}
//
//bool checkClosedLetters() {
//    for (int i = 0; i < getStringLength(hiddenWord); ++i) {
//        if (hiddenWord[i] == '-')
//            return true;
//    }
//    return false;
//}
//
//char toUpperCase(char c) {
//    char upperReg = ' ';
//    if (c >= 'a' and c <= 'z')
//        upperReg = c - SYMBOL_DIFFERENCE;
//    else
//        upperReg = c;
//
//    return upperReg;
//}
//void printStartScreen(){
//    system("cls");
//    cout << jokes[wordIndex] << endl;
//    Sleep(SLEEP);
//    cout << endl;
//    cout << endl;
//    cout << questions[wordIndex] << endl;
//    cout << endl;
//    hideWord();
//    cout << hiddenWord << endl;
//}