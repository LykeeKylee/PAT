#include<bits/stdc++.h>
using namespace std;
struct bill {
	string name;
	int age;
	int wealth;
};
bool cmp(bill &a, bill &b) {
	if(a.wealth != b.wealth) return a.wealth > b.wealth;
	else if(a.age != b.age) return a.age < b.age;
	return a.name < b.name;
}
int n, k;
vector<bill> blist;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; ++i) {
		bill tmp;
		cin >> tmp.name;
		scanf("%d %d", &tmp.age, &tmp.wealth);
		blist.push_back(tmp);
	}
	sort(blist.begin(), blist.end(), cmp);
	for(i = 0; i < k; ++i) {
		int amin, amax, m, cnt = 0;
		scanf("%d %d %d", &m, &amin, &amax);
		printf("Case #%d:\n", i + 1);
		for(j = 0; j < n && cnt < m; ++j) {
			if(blist[j].age <= amax && blist[j].age >= amin) {
				printf("%s %d %d\n", blist[j].name.c_str(), blist[j].age, blist[j].wealth);
				cnt++;
			}
		}
		if(cnt == 0) printf("None\n");
	}
	return 0;
}
