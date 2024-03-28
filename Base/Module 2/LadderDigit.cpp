//#include <iostream>
//
//using namespace std;
//
//void ColumnOfDigits(int n);
//
//void SumOfDigits(int n);
//
//double MultOfDigits(int n);
//
//bool IsIncrease(int n);
//
//void MaxAvgMin(int n);
//
//bool TwoInRow(int n);
//
//int main() {
//    int n = 11234;
//    ColumnOfDigits(n);
//    SumOfDigits(n);
//    cout << endl;
//    cout << MultOfDigits(n);
//    cout << endl;
//    cout << IsIncrease(n);
//    cout << endl;
//    MaxAvgMin(n);
//    cout << endl;
//    cout << TwoInRow(n);
//    return 0;
//}
//
//void ColumnOfDigits(int n) {
//    int digit = 0;
//    int remains = n;
//    while (remains > 0) {
//        digit = remains % 10;
//        cout << digit << endl;
//        remains /= 10;
//    }
//}
//
//void SumOfDigits(int n) {
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
//double MultOfDigits(int n) {
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
//bool IsIncrease(int n) {
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
//void MaxAvgMin(int n) {
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
//bool TwoInRow(int n) {
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