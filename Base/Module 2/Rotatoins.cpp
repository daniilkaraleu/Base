//#include <iostream>
//
//using namespace std;
//// 5 --> true (1)
//// 7 --> false (0)
//// 2 --> true (1)
//
//bool isAlternate(int num);
//
//int main(){
//    int num = 5;
//
////    cout << "Input yor number";
////    cin >> num;
//    cout << "It's alternate (1 - true, 0 - false): "<<isAlternate(num);
//    return 0;
//}
//
//bool isAlternate(int num){
//    int number = num;
//    bool result = false;
//    int previousIsSame = number % 2;
//    number /= 2;
//    while (number > 0){
//        int current = number % 2;
//        if (previousIsSame == current) {
//            result = false;
//            return result;
//        }
//        else{
//            previousIsSame = current;
//            number /= 2;
//            result = true;
//        }
//    }
//    return result;
//}