//#include <iostream>
//
//using namespace std;
//// 1234 --> 4321
//// 123456789 --> 987654321
//// 000000000 --> 0
//
//int ReversedNum(int number);
//double ReversedNum(double number);
//int main() {
//    int num = 10;
//
//    cout << ReversedNum(num);
//    return 0;
//}
//
//int ReversedNum(int num) {
//    int reversedNumber = 0;
//    const int arrayLength = 10;
//    int arrayOfDigits[arrayLength] = {};
//    int i = -1;
//    int rank = 1;
//    int number = num;
//    int lastDigit = 0;
//
//    while (number > lastDigit) {
//        i++;
//        arrayOfDigits[i] = number % 10;
//        number /= 10;
//    }
//
//    for (; i >= lastDigit; --i) {
//        reversedNumber += rank * arrayOfDigits[i];
//        rank *= 10;
//    }
//
//    return reversedNumber;
//}