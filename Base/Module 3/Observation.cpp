//#include <iostream>
//
//using namespace std;
//
//// 1, 2, 3, 2, 5 --> 3 2 5 - These are invisible heights.
//// 5, 2, 3, 4, 5  --> All heights are visible!
//
//int const LENGTH = 5;
//
//bool isHeightVisible(double location[]);
//void printVisibleHeights(bool isInvisible);
//
//int main(){
//    double location[LENGTH] = { 5, 2, 3, 4, 5};
//    bool visible = false;
//
//    visible = isHeightVisible(location);
//    printVisibleHeights(visible);
//    return 0;
//}
//
//bool isHeightVisible(double location[]){
//    double maxA = 0;
//    double a = 0;
//    double observerPosition = 0;
//    bool allVisible = true;
//
//    observerPosition = location[0];
//    maxA = (location[1] - observerPosition);
//
//    for (int i = 2; i < LENGTH; ++i) {
//        a = (location[i] - observerPosition) /  i;
//        if (maxA >= a){
//            allVisible = false;
//            cout << location[i] << " ";
//        } else
//            maxA = a;
//    }
//    return allVisible;
//}
//
//void printVisibleHeights(bool visible){
//    if (visible)
//        cout << "All heights are visible!";
//    else
//        cout << " - These are invisible heights.";
//}
