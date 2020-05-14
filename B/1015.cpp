#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct grade {
    string id;
    int de;
    int cai;
    int sum;
};

bool cmp(grade &t1, grade &t2) {
    if(t1.sum > t2.sum)
        return true;
    else if(t1.sum == t2.sum) {
        if(t1.de > t2.de)
            return true;
        else if(t1.de == t2.de)
            return t1.id < t2.id;
        else
            return false;
    }
    else
        return false;
}

int main() {
    int num, low, high;
    cin >> num >> low >> high;
    vector<grade> seq1, seq2, seq3, seq4;
    int stuSum = 0;
    for(int i = 0; i < num; ++i) {
        grade t;
        cin >> t.id >> t.de >> t.cai;
        if(t.de >= low && t.cai >=low) {
            t.sum = t.de + t.cai;
            if(t.de >= high && t.cai >= high) {
                seq1.emplace_back(t);
            }
            else if(t.de >= high &&  t.cai < high) {
                seq2.emplace_back(t);
            }
            else if(t.de < high && t.cai < high && t.de >= t.cai) {
                seq3.emplace_back(t);
            }
            else {
                seq4.emplace_back(t);
            }
            ++stuSum;
        }
    }
    sort(seq1.begin(), seq1.end(), cmp);
    sort(seq2.begin(), seq2.end(), cmp);
    sort(seq3.begin(), seq3.end(), cmp);
    sort(seq4.begin(), seq4.end(), cmp);

    cout << stuSum << endl;
    for(int i = 0; i < seq1.size(); ++i)
        printf("%s %d %d\n", seq1[i].id.c_str(), seq1[i].de, seq1[i].cai);
    for(int i = 0; i < seq2.size(); ++i)
        printf("%s %d %d\n", seq2[i].id.c_str(), seq2[i].de, seq2[i].cai);
    for(int i = 0; i < seq3.size(); ++i)
        printf("%s %d %d\n", seq3[i].id.c_str(), seq3[i].de, seq3[i].cai);
    for(int i = 0; i < seq4.size(); ++i)
        printf("%s %d %d\n", seq4[i].id.c_str(), seq4[i].de, seq4[i].cai);
    return 0;
}
