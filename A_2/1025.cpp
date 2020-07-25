#include<bits/stdc++.h>
using namespace std;
struct grade {
	string id;
	int g;
	int frank = 0;
	int loc;
	int lrank = 0;
};
bool cmp(grade &a, grade &b) {
	if(a.g != b.g) return a.g > b.g;
	else return a.id < b.id;
}
int n, k;
vector<grade> testee;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j, cnt = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &k);
		for(j = 0; j < k; ++j) {
			grade tmp;
			tmp.loc = i + 1;
			cin >> tmp.id;
			scanf("%d", &tmp.g);
			testee.push_back(tmp);
		}
	}
	sort(testee.begin(), testee.end(), cmp);
	int curg = -1, curank = 1, offset = 0;
	vector<int> lcurg(n, -1), lcurank(n, 1), loffset(n, 0);
	for(i = 0; i < testee.size(); ++i) {
		if(curg != testee[i].g) {
			testee[i].frank = curank + offset;
			curank += offset;
			offset = 1;
			curg = testee[i].g;
		}
		else {
			testee[i].frank = curank;
			offset++;
		}
		int loc = testee[i].loc - 1;
		if(lcurg[loc] != testee[i].g) {
			testee[i].lrank = lcurank[loc] + loffset[loc];
			lcurank[loc] += loffset[loc];
			loffset[loc] = 1;
			lcurg[loc] = testee[i].g;
		}
		else {
			testee[i].lrank = lcurank[loc];
			loffset[loc]++;
		}
	}
	printf("%d\n",testee.size());
	for(i = 0; i < testee.size(); ++i) {
		printf("%s %d %d %d\n", testee[i].id.c_str(), testee[i].frank, testee[i].loc, testee[i].lrank);
	}
	return 0;
}
