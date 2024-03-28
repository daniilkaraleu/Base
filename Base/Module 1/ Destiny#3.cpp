//#include  <iostream>
//
//using namespace std;
//
//// 23102002 --> 1
//// 10101000 --> 3
//// 29091999 --> 3
//// 11111111 --> 8
//
//int main() {
//    int arrayLength = 3;
//    int dd = 0;
//    int mm = 0;
//    int yyyy = 0;
//    int sumOfDigits = 0;
//    int destinyNumber = 0;
//    int arrayOfDate[3] = {};
//
//
//    cout << "Input your full birthdate in DDMMYYYY format: days, months and years separately! \nDD:";
//    cin >> dd;
//    cout << "MM:";
//    cin >> mm;
//    cout << "YYYY:";
//    cin >> yyyy;
//    arrayOfDate[0] = dd;
//    arrayOfDate[1] = mm;
//    arrayOfDate[2] = yyyy;
//
//    for (int i = 0; i < arrayLength; ++i) {
//        while (arrayOfDate[i] > 9) {
//            sumOfDigits = 0;
//            do {
//                sumOfDigits += arrayOfDate[i] % 10;
//                arrayOfDate[i] /= 10;
//            } while (arrayOfDate[i] > 0);
//            arrayOfDate[i] = sumOfDigits;
//        }
//    }
//    for (int i: arrayOfDate) {
//        destinyNumber += i;
//    }
//
//    while (destinyNumber > 9) {
//        sumOfDigits = 0;
//        do {
//            sumOfDigits += destinyNumber % 10;
//            destinyNumber /= 10;
//        } while (destinyNumber > 0);
//        destinyNumber = sumOfDigits;
//    }
//    cout << "Your destiny number is " << destinyNumber;
//    return 0;
//}