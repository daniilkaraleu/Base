//#include <iostream>
//
//using namespace std;
//// 1  -->  0
//// 3  -->  1
//// 7  -->  8
//// 100  --> -889489150
//
//int FibonacciSequence(int n);
//
//int main(){
//    int n = 100;
//    cout << FibonacciSequence(n);
//    return 0;
//}
//int FibonacciSequence(int n){
//    int currentNum = 0;
//    int nextNum = 1;
//    int tempSum = 0;
//    int lastIter = 1;
//
//    for (; lastIter < n; --n) {
//        tempSum = currentNum + nextNum;
//        currentNum = nextNum;
//        nextNum = tempSum;
//    }
//    return currentNum;
//}