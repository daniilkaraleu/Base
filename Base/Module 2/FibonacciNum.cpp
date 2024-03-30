//#include <iostream>
//
//using namespace std;
//// 1  -->  0
//// 3  -->  1
//// 7  -->  8
//// 100  --> 2.18923+e20
//
//double getFibonacciN(int n);
//
//int main(){
//    int n = 100;
//
////    cout << "Input your preferred fibonacci number";
////    cin >> n;
//    cout << "The number is: " << getFibonacciN(n);
//    return 0;
//}
//double getFibonacciN(int n){
//    double currentNum = 0;
//    double nextNum = 1;
//    double tempSum = 0;
//    int stopIterate = 1;
//
//    for (; stopIterate < n; --n) {
//        tempSum = currentNum + nextNum;
//        currentNum = nextNum;
//        nextNum = tempSum;
//    }
//    return currentNum;
//}