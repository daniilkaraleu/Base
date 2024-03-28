//#include <iostream>
//#include <cmath>
//// 24 -->  4
//// 1 -->  1
//// 3 --> 9
//using namespace std;
//
//int main() {
//    int counter = 0;
//    int lengthOfSquared = 1;
//    int squared = 0;
//    int num = 1;
//    int n = 3;
//    int nDigit = 0;
//    int lengthToSubtract = 0;
//
//
//    while (counter < n) {
//        squared = num * num;
//        if (1 <= squared / pow(10, lengthOfSquared)) {
//            lengthOfSquared += 1;
//        }
//        counter += lengthOfSquared;
//        num += 1;
//    }
//    lengthToSubtract = counter - n;
//    for (int j = 0; j <= lengthToSubtract; ++j) {
//        nDigit = squared % 10;
//        squared /= 10;
//    }
//    cout << nDigit;
//    return 0;
//}