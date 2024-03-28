//#include <iostream>
//
//using namespace std;
//
//// 3,3 and 4,4  -->  Beat!
//// 3,3 and 4,5  -->  Don't beat!
//// 3,3 and 3,3  -->  These figures are at the same position!
//
//
//int main(){
//    int x1 = 0;
//    int y1 = 0;
//    int x2 = 0;
//    int y2 = 0;
//    string result = "Don't beat!";
//
//    cout << "Input x coord for the 1st bishop \n";
//    cin >> x1;
//    cout << "Input y coord for the 1st bishop \n";
//    cin >> y1;
//    cout << "Input x coord for the 2nd bishop \n";
//    cin >> x2;
//    cout << "Input y coord for the 2nd bishop \n";
//    cin >> y2;
//
//    if (x1 == x2 and y1 == y2){
//        cout << "These figures are at the same position!";
//        return 0;
//    }
//
//    if (abs(y2 - y1) == abs(x2 -x1)){
//        result = "Beat!";
//    }
//
//    cout << result;
//
//    return 0;
//}