#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct problem {
    int point;
    int choices;
    int rightNum;
    string rightChoice;
};

int main() {
    int stuNum, proNum, num;
    cin >> stuNum >> proNum;
    num = proNum;
    auto *proSeq = new problem[proNum];
    while(num--) {
        int point, choices, rightNum;
        cin >> point >> choices >> rightNum;
        proSeq[proNum - num - 1].point = point;
        proSeq[proNum - num - 1].choices = choices;
        proSeq[proNum - num - 1].rightNum = rightNum;
        getchar();
        getline(cin, proSeq[proNum - num - 1].rightChoice);
//        cout << proSeq[proNum - num - 1].rightChoice << endl;
    }

    int *wrongCnt = new int[proNum], *pointCnt = new int[stuNum];
    memset(wrongCnt, 0, proNum * 4);
    memset(pointCnt, 0, stuNum * 4);
    string ans;
    num = stuNum;
    while(num--) {
        int proNo = 0;
        getline(cin, ans);
        for(int i = 0; i < ans.length(); ++i) {
            int pos;
            if(ans[i] == '(') {
                pos = i;
                while(ans[i] != ')')
                    ++i;
                if(int(ans[pos + 1] - '0') != proSeq[proNo].rightNum) {
                    ++wrongCnt[proNo];
                }
                else {
                    string stuChoice = ans.substr(pos + 3, i - pos - 3);
                    if(stuChoice == proSeq[proNo].rightChoice) {
                        pointCnt[stuNum - num - 1] += proSeq[proNo].point;
                    }
                    else {
                        ++wrongCnt[proNo];
                    }
                }
                ++proNo;
            }
        }
    }

    for(int i = 0; i < stuNum; ++i) {
        printf("%d\n", pointCnt[i]);
    }

    int max = 0;
    string ret;
    for(int i = 0; i < proNum; ++i) {
        if(wrongCnt[i] > max) {
            max = wrongCnt[i];
            ret = to_string(max) + ' ' + to_string(i + 1);
        }
        else if(wrongCnt[i] == max) {
            ret += (' ' + to_string(i + 1));
        }
    }
    if(max == 0)
        cout << "Too simple" << endl;
    else
        cout << ret << endl;

    return 0;
}