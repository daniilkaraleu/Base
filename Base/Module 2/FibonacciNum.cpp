//#include <iostream>
//
//using namespace std;
//// 1  -->  0
//// 3  -->  1
//// 7  -->  8
//// 100  --> -889489150
//
//double FibonacciSequence(int n);
//
//int main(){
//    int n = 100;
//    cout << FibonacciSequence(n);
//    return 0;
//}
//double FibonacciSequence(int n){
//    double currentNum = 0;
//    double nextNum = 1;
//    double tempSum = 0;
//    int lastIter = 1;
//
//    for (; lastIter < n; --n) {
//        tempSum = currentNum + nextNum;
//        currentNum = nextNum;
//        nextNum = tempSum;
//    }
//    return currentNum;
//}