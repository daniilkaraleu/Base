//#include <iostream>
//
//using namespace std;
//
//void columnOfDigits(int n);
//
//void sumOfDigits(int n);
//
//double multOfDigits(int n);
//
//bool isIncrease(int n);
//
//void maxAvgMin(int n);
//
//bool twoInRow(int n);
//
//int main() {
//    int n = 11234;
//    columnOfDigits(n);
//    sumOfDigits(n);
//    cout << endl;
//    cout << multOfDigits(n);
//    cout << endl;
//    cout << isIncrease(n);
//    cout << endl;
//    maxAvgMin(n);
//    cout << endl;
//    cout << twoInRow(n);
//    return 0;
//}
//
//void columnOfDigits(int n) {
//    int digit = 0;
//    int remains = n;
//    while (remains > 0) {
//        digit = remains % 10;
//        cout << digit << endl;
//        remains /= 10;
//    }
//}
//
//void sumOfDigits(int n) {
//    int digit = 0;
//    int remains = n;
//    double sum = 0;
//    while (remains > 0) {
//        digit = remains % 10;
//        sum += digit;
//        remains /= 10;
//    }
//    cout << sum;
//}
//
//double multOfDigits(int n) {
//    int digit = 0;
//    int remains = n;
//    double mult = 1;
//    while (remains > 0) {
//        digit = remains % 10;
//        mult *= digit;
//        remains /= 10;
//    }
//    return mult;
//}
//
//bool isIncrease(int n) {
//    int digit = 0;
//    int remains = n;
//    int previous = remains % 10;
//    remains /= 10;
//    bool result = true;
//    while (remains > 0) {
//        digit = remains % 10;
//        if (previous <= digit) {
//            result = false;
//            break;
//        }
//        previous = digit;
//        remains /= 10;
//    }
//    return result;
//}
//
//void maxAvgMin(int n) {
//    int digit = n % 10;
//    int remains = n;
//    int max = digit;
//    int min = digit;
//    double average = 0;
//    double sum = 0;
//    int counter = 0;
//    double difference = 0;
//    int mediumDigit = 0;
//
//    while (remains > 0) {
//        digit = remains % 10;
//        sum += digit;
//        counter += 1;
//        if (max < digit)
//            max = digit;
//        if (min > digit)
//            min = digit;
//        remains /= 10;
//    }
//
//    remains = n;
//    average = sum / counter;
//    digit = n % 10;
//    difference = abs(average - digit);
//    mediumDigit = digit;
//
//    while (remains > 0) {
//        digit = remains % 10;
//        if (difference > abs(average - digit)) {
//            difference = abs(average - digit);
//            mediumDigit = digit;
//        }
//        remains /= 10;
//    }
//
//    cout << "Max: " << max << " Medium: " << mediumDigit << " Min: " << min;
//}
//
//bool twoInRow(int n) {
//    int digit = 0;
//    int remains = n;
//    int previus = -1;
//    bool result = true;
//    while (remains > 0) {
//        digit = remains % 10;
//        if (previus == digit) {
//            result = true;
//            break;
//        }
//        previus = digit;
//        remains /= 10;
//    }
//    return result;
//}