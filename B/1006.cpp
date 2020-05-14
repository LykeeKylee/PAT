#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    int example;
    cin >> example;
    for(int i = 0; i < example / 100; ++i){
        cout<<'B';
    }
    for(int i = 0; i < example % 100 / 10; ++i){
        cout<<'S';
    }
    for(int i = 0; i < example % 100 % 10; ++i){
        cout<<i + 1;
    }
    return 0;
}