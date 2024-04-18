//#include <iostream>
//
//using namespace std;
//
//// ()[]{} --> Balanced!
//// ()[{]} --> Not balanced!
//
//int const N = 2048;
//
//char pullOfBraces[N] = "";
//
//bool countBraces(char text[]);
//
//int getStringLength(char str[]);
//
//int lastBraceOut(int index, char c);
//
//bool checkOutOfRange(char text[]);
//
//
//int main() {
//    char text[N] = "([]<<[>][ ]>)()";
//
//    if (checkOutOfRange(text)) {
//        cout << "Error! Out of range.";
//        return -1;
//    }
//
//    if (countBraces(text))
//        cout << "Balanced!";
//    else
//        cout << "Not balanced!";
//
//
//    return 0;
//}
//
//
//int getStringLength(char str[]) {
//    int counter = 0;
//
//    while (true) {
//        if (str[counter] == '\0')
//            break;
//        counter++;
//    }
//    return counter + 1;
//}
//
//bool countBraces(char text[]) {
//    int index = 0;
//    int lastBrace = 0;
//
//    for (int i = 0; text[i] != '\0'; ++i) {
//        if (text[i] == '[' or text[i] == '(' or text[i] == '{' or text[i] == '<') {
//            pullOfBraces[index] = text[i];
//            index++;
//        } else if (text[i] == ']') {
//            index--;
//            lastBrace = lastBraceOut(index, ']');
//        } else if (text[i] == '>') {
//            index--;
//            lastBrace = lastBraceOut(index, '>');
//        } else if (text[i] == ')') {
//            index--;
//            lastBrace = lastBraceOut(index, ')');
//        } else if (text[i] == '}') {
//            index--;
//            lastBrace = lastBraceOut(index, '}');
//        } else
//            continue;
//
//        if (lastBrace)
//            return false;
//    }
//    if (index == 0)
//        return true;
//    return false;
//}
//
//int lastBraceOut(int index, char c) {
//    if (pullOfBraces[index] == '{' and c == '}');
//    else if (pullOfBraces[index] == '(' and c == ')');
//    else if (pullOfBraces[index] == '[' and c == ']');
//    else if (pullOfBraces[index] == '<' and c == '>');
//    else
//        return 1;
//
//    pullOfBraces[index] = '\0';
//    return 0;
//}
//
//bool checkOutOfRange(char text[]) {
//    if (getStringLength(text) <= N)
//        return false;
//    else {
//        return true;
//    }
//}