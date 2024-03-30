//#include <iostream>
//
//using namespace std;
//
//void printDigits(int n);
//
//void printSumOfDigits(int n);
//
//double multOfDigits(int n);
//
//bool isIncrease(int n);
//
//double getAvgOfDigits(int n);
//
//int getMediumDigit(int n);
//
//void printMaxAvgMin(int n);
//
//bool hasTwoInRow(int n);
//
//int main() {
//    int n = 1234;
//
////    cout << "Input your number";
////    cin >> n;
//    cout << "The column of digits:\n";
//    cout << getAvgOfDigits(n);
//    cout << endl;
//    printDigits(n);
//    cout << "The sum of digits: ";
//    printSumOfDigits(n);
//    cout << endl;
//    cout << "The product of digits is: " << multOfDigits(n);
//    cout << endl;
//    cout << "Digits increase (1 - true, 0 - false): " << isIncrease(n);
//    cout << endl;
//    printMaxAvgMin(n);
//    cout << endl;
//    cout << "The number has two same digits in a row (1 - true, 0 - false): " << hasTwoInRow(n);
//
//    return 0;
//}
//
//void printDigits(int n) {
//    int digit = 0;
//
//    while (n > 0) {
//        digit = n % 10;
//        cout << digit << endl;
//        n /= 10;
//    }
//}
//
//void printSumOfDigits(int n) {
//    int digit = 0;
//    double sum = 0;
//
//    while (n > 0) {
//        digit = n % 10;
//        sum += digit;
//        n /= 10;
//    }
//    cout << sum;
//}
//
//double multOfDigits(int n) {
//    int digit = 0;
//    double mult = 1;
//
//    while (n > 0) {
//        digit = n % 10;
//        mult *= digit;
//        n /= 10;
//    }
//    return mult;
//}
//
//bool isIncrease(int n) {
//    int digit = 0;
//    int previous = n % 10;
//    n /= 10;
//    while (n > 0) {
//        digit = n % 10;
//        if (previous <= digit) {
//            return false;
//        }
//        previous = digit;
//        n /= 10;
//    }
//    return true;
//}
//
//void printMaxAvgMin(int n) {
//    int digit = n % 10;
//    int max = digit;
//    int min = digit;
//    int mediumDigit = getMediumDigit(n);
//
//    while (n > 0) {
//        digit = n % 10;
//        if (max < digit)
//            max = digit;
//        if (min > digit)
//            min = digit;
//        n /= 10;
//    }
//
//    cout << "Max: " << max << " Medium: " << mediumDigit << " Min: " << min;
//}
//
//bool hasTwoInRow(int n) {
//    int digit = 0;
//    int previus = -1;
//    while (n > 0) {
//        digit = n % 10;
//        if (previus == digit) {
//            return true;
//        }
//        previus = digit;
//        n /= 10;
//    }
//    return false;
//}
//
//double getAvgOfDigits(int n) {
//    double avg = 0;
//    int digit = 0;
//    int counter = 0;
//
//    while (n > 0) {
//        counter += 1;
//        digit = n % 10;
//        avg += digit;
//        n /= 10;
//    }
//    avg /= counter;
//    return avg;
//}
//
//int getMediumDigit(int n) {
//    double average = getAvgOfDigits(n);
//    int digit = n % 10;
//    double difference = abs(average - digit);
//    int mediumDigit = digit;
//
//    while (n > 0) {
//        digit = n % 10;
//        if (difference > abs(average - digit)) {
//            difference = abs(average - digit);
//            mediumDigit = digit;
//        }
//        n /= 10;
//    }
//    return mediumDigit;
//}