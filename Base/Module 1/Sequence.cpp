//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    int counter = 0;
//    int lengthOfSquared = 1;
//    int squared = 0;
//    int num = 1;
//    int n = 23;
//    int nDigit = 0;
//    int lengthToSubtract = 0;
//    int arrayOfDigits[10] = {};
//    int i = 0;
//    int temp = 0;
//    int tempLength = 0;
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
//    tempLength = lengthOfSquared - lengthToSubtract;
//    while (lengthOfSquared != 0) {
//        lengthOfSquared -= 1;
//        arrayOfDigits[i] = squared / pow(10, lengthOfSquared);
//        i += 1;
//        temp = squared / pow(10, lengthOfSquared);
//        squared -= temp * pow(10, lengthOfSquared);
//    }
//    nDigit = arrayOfDigits[tempLength - 1];
//    cout << nDigit;
//    return 0;
//}