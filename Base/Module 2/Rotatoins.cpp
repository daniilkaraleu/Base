#include <iostream>

using namespace std;
// 5 --> It's alternate
// 7 --> It's not alternate
// 2 --> It's alternate

bool isAlternate(int num);

int main(){
    int num = 2;

//    cout << "Input yor number";
//    cin >> num;

    if (isAlternate(num)){
        cout << "It's alternate";
    }else{
        cout << "It's not alternate";
    }

    return 0;
}

bool isAlternate(int num){
    int number = num;
    int previousIsSame = number % 2;
    number /= 2;

    while (number > 0){
        int current = number % 2;
        if (previousIsSame == current) {
            return false;
        }
        else{
            previousIsSame = current;
            number /= 2;
        }
    }

    return true;
}