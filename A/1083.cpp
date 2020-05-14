#include<bits/stdc++.h>
using namespace std;
struct grade{
	string name, id;
	int g;
};
vector<grade> stu;
bool cmp(grade &a, grade &b) {
	return a.g > b.g;
}
int main() {
	int n, i, g1, g2, cnt = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		grade tmp;
		cin >> tmp.name >> tmp.id >> tmp.g;
		stu.emplace_back(tmp); 
	}
	scanf("%d %d", &g1, &g2);
	sort(stu.begin(), stu.end(), cmp);
	for(i = 0; i < stu.size(); ++i) {
		if(stu[i].g >= g1 && stu[i].g <= g2) {
			printf("%s %s\n", stu[i].name.c_str(), stu[i].id.c_str());
			++cnt;
		}
	}
	if(cnt == 0) printf("NONE\n");
	return 0;
}
