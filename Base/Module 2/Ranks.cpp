//#include <iostream>
//
//using namespace std;
//// 1234 --> 4321
//// 123456789 --> 987654321
//// 000000000 --> 0
//
//int getReversedNum(int number);
//
//int main() {
//    int num = 10000100;
//
////    cout << "Input your decimal number";
////    cin >> num;
//    cout << "Reversed number is: " << getReversedNum(num);
//    return 0;
//}
//
//int getReversedNum(int num) {
//    int reversedNumber = 0;
//    const int arrayLength = 10;
//    int arrayOfDigits[arrayLength] = {};
//    int i = -1;
//    int rank = 1;
//    const int BREAK_POINT = 0;
//
//    while (num > BREAK_POINT) {
//        i++;
//        arrayOfDigits[i] = num % 10;
//        num /= 10;
//    }
//
//    for (; i >= BREAK_POINT; --i) {
//        reversedNumber += rank * arrayOfDigits[i];
//        rank *= 10;
//    }
//
//    return reversedNumber;
//}