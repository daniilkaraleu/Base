//#include <iostream>
//
//using namespace std;
//// 5 --> true (1)
//// 7 --> false (0)
//// 2 --> true (1)
//
//bool IsAlternate(int num);
//
//int main(){
//    cout << IsAlternate(1);
//    return 0;
//}
//
//bool IsAlternate(int num){
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