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
//int binToDec(int binary);
//
//int main(){
//    int binary = 111;
//    int i = 0;
//    int decimal = binToDec( binary );
//
//    cout << decimal;
//
//    return 0;
//}
//
//int binToDec(int binary){
//    int basis = 2;
//    int decimal = 0;
//    int power = 0;
//    int digit = 0;
//    int remains = binary;
//
//    while (remains > 0) {
//        digit = remains % 10;
//        decimal += digit * pow(basis, power);
//        remains /= 10;
//        power += 1;
//    }
//
//    return decimal;
//}
