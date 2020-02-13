#include <iostream>
#include <algorithm>
#include <cstring>
using std::sort;
using std::cin;
using std::cout;
using std::endl;
#define UNUSED 0
#define UNCOVERED 1
#define COVERED 2

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int len;
    cin >> len;
    short *seq = new short[len];
    char cover[150];
    memset(cover, UNUSED, sizeof(cover));
    for(int i = 0; i < len; ++i){
        cin>>seq[i];
        cover[seq[i]] = UNCOVERED;
    }
    sort(seq, seq + len, cmp);
    for(int i = 0; i < len; ++i){
        int temp = seq[i];
        temp = (temp % 2 == 0) ? (temp / 2) : ((temp * 3 + 1) / 2);
        while(temp != 1){
            if(cover[temp] == UNCOVERED)
                cover[temp] = COVERED;
            temp = (temp % 2 == 0) ? (temp / 2) : ((temp * 3 + 1) / 2);
        }
    }
    bool flag = true;
    for(int i = 100; i > 1; --i){
        if(cover[i] == UNCOVERED){
            if(flag){
                cout<<i;
                flag = false;
            }
            else{
                cout<<' '<<i;
            }
        }
    }
    return 0;
}