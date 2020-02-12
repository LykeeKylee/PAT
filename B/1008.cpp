#include <iostream>
using namespace std;

int main(){
    int length, cycle;
    cin>>length>>cycle;
    int *seq = new int[length];
    for(int i = 0; i < length; ++i){
        cin>>seq[i];
    }
    cycle %= length;
    for(int i = length - cycle; i < length; ++i){
        if(i == length - cycle)
            cout<<seq[i];
        else
            cout<<' '<<seq[i];
    }
    for(int i = 0; i < length - cycle; ++i){
        if(i == 0 && cycle == 0)
            cout<<seq[i];
        else
            cout<<' '<<seq[i];
    }
    return 0;
}