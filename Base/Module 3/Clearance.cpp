//#include <iostream>
//
//using namespace std;
///*
// * 111 111 111                   011 111 111
// * 111 101 101  --> NO           011 111 111  --> YES
// * 111 111 111                   011 111 111
//*/
//int const N = 3;
//
//int cube[N][N][N] ={{  {0,1,1},
//                           {1,1,1},
//                           {0,1,1}},
//
//                    {   {1,1,1},
//                            {1,0,1},
//                            {1,1,1}},
//
//                    {   {1,1,1},
//                            {1,0,1},
//                            {1,1,1}}};
//
//bool hasInRow();
//bool hasInColumn();
//bool hasInLine();
//void printCube();
//
//int main(){
//    printCube();
//
//    if (hasInRow() or hasInColumn() or hasInLine())
//        cout << "YES";
//    else
//        cout << "NO";
//    return 0;
//}
//
//bool hasInRow(){
//    int counter = 0;
//
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            for (int k = 0; k < N; ++k) {
//                if (!cube[i][j][k])
//                    counter++;
//            }
//            if (counter == N)
//                return true;
//            counter = 0;
//        }
//    }
//    return false;
//}
//bool hasInColumn(){
//    int counter = 0;
//
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            for (int k = 0; k < N; ++k) {
//                if (!cube[i][k][j])
//                    counter++;
//            }
//            if (counter == N)
//                return true;
//            counter = 0;
//        }
//    }
//    return false;
//}
//
//bool hasInLine(){
//    int counter = 0;
//
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            for (int k = 0; k < N; ++k) {
//                if (!cube[k][j][i])
//                    counter++;
//            }
//            if (counter == N)
//                return true;
//            counter = 0;
//        }
//    }
//    return false;
//}
//
//void printCube(){
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            for (int k = 0; k < N; ++k) {
//                cout << cube[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//}