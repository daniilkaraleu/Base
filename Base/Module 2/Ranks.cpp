//#include <iostream>
//
//using namespace std;
//// 1234 --> 4321
//// 123456789 --> 987654321
//// 000000000 --> 0
//
//int reversedNum(int number);
//int main() {
//    int num = 1234;
//
////    cout << "Input your decimal number";
////    cin >> num;
//    cout << "Reversed number is: " <<reversedNum(num);
//    return 0;
//}
//
//int reversedNum(int num) {
//    int reversedNumber = 0;
//    const int arrayLength = 5;
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