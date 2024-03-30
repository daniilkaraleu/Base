//#include <iostream>
//#include <cmath>
//
//// 111 --> 7
//// 0  --> 0
//// 1 --> 1
//// 101 --> 5
//
//using namespace std;
//
//int getDecimal(int binary);
//
//int main() {
//    int binary = 111;
//    int decimal = 0;
//
////    cout << "Input your binary number: ";
////    cin >> binary;
//
//    decimal = getDecimal(binary);
//    cout << "Consequent number is: " << decimal;
//
//    return 0;
//}
//
//int getDecimal(int binary) {
//    int basis = 2;
//    int decimal = 0;
//    int power = 0;
//    int digit = 0;
//
//    while (binary > 0) {
//        digit = binary % 10;
//        decimal += digit * pow(basis, power);
//        binary /= 10;
//        power += 1;
//    }
//
//    return decimal;
//}
