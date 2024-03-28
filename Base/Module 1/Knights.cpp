//#include <iostream>
//
//using namespace std;
//// 1,1    2,3  -->  Beat!
//// 1,1    3,3  -->  Don't beat!
//// 1,1    1,1  -->  These figures are at the same position!
//int main(){
//    int x1 = 0;
//    int y1 = 0;
//    int x2 = 0;
//    int y2 = 0;
//    int xDifference = 0;
//    int yDifference = 0;
//    string result = "These figures are at the same position!";
//
//    cout << "Input x coord for the 1st knight \n";
//    cin >> x1;
//    cout << "Input y coord for the 1st knight \n";
//    cin >> y1;
//    cout << "Input x coord for the 2nd knight \n";
//    cin >> x2;
//    cout << "Input y coord for the 2nd knight \n";
//    cin >> y2;
//
//    xDifference = abs(x1 - x2);
//    yDifference = abs(y1 - y2);
//    if (x1 == x2 and y1 == y2){
//        cout << result;
//        return 0;
//    }
//    if ((yDifference == 2 or xDifference == 2) and (xDifference == 1 or yDifference == 1)){
//        result = "Beat!";
//    }else{
//        result = "Don't beat!";
//    }
//    cout << result;
//    return 0;
//}