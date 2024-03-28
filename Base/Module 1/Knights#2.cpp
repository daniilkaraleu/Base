//#include <iostream>
//
//// 1,1    2,3  -->  Beat!
//// 1,1    3,3  -->  Don't beat!
//// 1,1    1,1  -->  These figures are at the same position!
//using namespace std;
//
//int main() {
//    int x1 = 3;
//    int y1 = 3;
//    int x2 = 4;
//    int y2 = 4;
//    string result = "Don't beat";

//    if (x1 == x2 and y1 == y2){
//        cout << "These figures are at the same position!";
//        return 0;
//    }

//    for (int i = x1 - 2; i <= x1 + 2; ++i) {
//        for (int j = y1 - 2; j <= y1 + 2; ++j) {
//            if (abs(i - x1) == abs(j - y1))
//                continue;
//            else if (i == x1 or j == y1)
//                continue;
//            else if (i == x2 and j == y2)
//                result = "Beat!";
//            else
//                continue;
//        }
//    }

//    cout << result;
//    return 0;
//}