#include <iostream>
#include <string>
#include <map>
using namespace std;

//struct problem {
//    int no;
//    int point;
//    int cnum;
//    int anum;
//    char *aseq;
//};
//
//int judge(char &c, int &len, const char seq[]) {
//    for(int i = 0; i < len; ++i) {
//        if(seq[i] == c)
//            return i;
//    }
//    return -1;
//}

//int main() {
//    int pnum, snum, i, j;
//    cin >> snum >> pnum;
//    auto pro = new problem[pnum];
//    for(i = 0; i < pnum; ++i) {
//        int point, cnum, anum;
//        cin >> point >> cnum >> anum;
//        pro[i].no = i + 1;
//        pro[i].point = point;
//        pro[i].cnum = cnum;
//        pro[i].anum = anum;
//        pro[i].aseq = new char[anum];
//        for(j = 0; j < anum; ++j) {
//            cin >> pro[i].aseq[j];
//        }
//    }
//    getchar();
//    map<string, int> wrongInfo;
//    auto *grade = new double[snum];
//    for(i = 0; i < snum; ++i) {
//        for(j = 0; j < pnum; ++j) {
//            int n, wcnt = 0, rcnt = 0;
//            char c;
//            scanf("(%d", &n);
//            bool *defen = new bool[pro[j].anum];
//            for(int k = 0; k < n; ++k) {
//                scanf(" %c", &c);
//                int ret = judge(c, pro[j].anum, pro[j].aseq);
//                if(ret != -1)
//                    defen[ret] = true;
//                else {
//                    wrongInfo[to_string(pro[j].no)+ '-' + c]++;
//                    wcnt++;
//                }
//            }
//            for(int k = 0; k < pro[j].anum; ++k){
//                if(!defen[k]) {
//                    wrongInfo[to_string(pro[j].no)+ '-' + pro[j].aseq[k]]++;
//                }
//                else
//                    ++rcnt;
//            }
//            if(rcnt == pro[j].anum && wcnt == 0) {
//
//                grade[i] += double(pro[j].point);
//            }
//            else if(rcnt < pro[j].anum && rcnt > 0 && wcnt == 0) {
//                grade[i] += (double(pro[j].point) / 2);
//            }
//            getchar();
//            getchar();
//            delete[]defen;
//        }
//    }
//
//    for(i = 0; i < snum; ++i) {
//        printf("%0.1lf\n", grade[i]);
//    }
//    if(wrongInfo.empty()) {
//        cout << "Too simple" << endl;
//    }
//    else {
//        int max = 0;
//        for(auto it = wrongInfo.begin(); it != wrongInfo.end(); ++it) {
//            if(it->second > max)
//                max = it->second;
//        }
//        for(auto it = wrongInfo.begin(); it != wrongInfo.end(); ++it) {
//            if(it->second == max)
//                printf("%d %s\n", it->second, it->first.c_str());
//        }
//    }
//    delete[]pro;
//    for(i = 0; i < pnum; ++i)
//        delete[]pro[i].aseq;
//    return 0;
//}

struct problem {
    int point;
    int anum;
    uint aseq;
};

uint bit[5] = {1, 2, 4, 8, 16};

int main() {
    int pnum, snum, i, j;
    cin >> snum >> pnum;
    auto pro = new problem[pnum];
    for(i = 0; i < pnum; ++i) {
        int point, cnum, anum;
        char c;
        cin >> point >> cnum >> anum;
        pro[i].point = point, pro[i].anum = anum, pro[i].aseq = 0x00;
        while(anum--) {
            cin >> c;
            pro[i].aseq |= bit[c - 'a'];
        }
    }
    getchar();
    map<string, int> wrongInfo;
    int max = 0;
    for(i = 0; i < snum; ++i) {
        double grade = 0.0;
        for(j = 0; j < pnum; ++j) {
            uint answer = 0x00, n, judge;
            char c;
            scanf("(%d", &n);
            while(n--) {
                scanf(" %c", &c);
                answer |= bit[c - 'a'];
            }
            judge = answer ^ pro[j].aseq;
            if(judge == 0) grade += pro[j].point;
            else {
                if((judge & pro[j].aseq) == judge) grade += (double(pro[j].point) / 2);
                for(int b = 4; b >= 0; --b) {
                    if(judge >= bit[b]) {
                        judge -= bit[b];
                        ++wrongInfo[to_string(j + 1) + '-' + char('a' + b)];
                        max = max > wrongInfo[to_string(j + 1) + '-' + char('a' + b)] ? max : wrongInfo[to_string(j + 1) + '-' + char('a' + b)];
                    }
                }
            }
            getchar(); getchar();
        }
        printf("%0.1f\n", grade);
    }
    if(max == 0)
        cout << "Too simple" << endl;
    else {
        for(auto it = wrongInfo.begin(); it != wrongInfo.end(); ++it) {
            if(it->second == max) printf("%d %s\n", max, it->first.c_str());
        }
    }
    return 0;
}