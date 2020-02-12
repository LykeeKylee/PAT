#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

bool judge(int x){
    bool flag = true;
    for(int i = 3; i <= sqrt(x); ++i){
        if(x % i == 0){
            flag = false;
        }
    }
    return flag;
}
//TODO:need optimalization
int main(){
    int N, sum = 0;
    cin>>N;
    for(int i = 3; i <= N - 2; i = i + 2){
        if(judge(i) && judge(i + 2))
            ++sum;
    }
    cout<<sum;
    return 0;
}