#include<bits/stdc++.h>
using namespace std;
struct pocketmoney {
	string name;
	int age, worth;
};
bool cmp(pocketmoney &a, pocketmoney &b) {
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}
vector<pocketmoney> rich;
int main() {
	int n, k, i, j, m, low, high, cnt;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; ++i) {
		pocketmoney p;
		cin >> p.name;
		scanf("%d %d", &p.age, &p.worth);
		rich.emplace_back(p); 
	}
	sort(rich.begin(), rich.end(), cmp);
	for(i = 1; i <= k; ++i) {
		scanf("%d %d %d", &m, &low, &high);
		j = cnt = 0;
		printf("Case #%d:\n", i);
		while(cnt < m && j < n) {
			if(rich[j].age >= low && rich[j].age <= high) {
				printf("%s %d %d\n", rich[j].name.c_str(), rich[j].age, rich[j].worth);
				++cnt;
			}
			++j;
		}
		if(cnt == 0) printf("None\n");
	}
	return 0;
} 
