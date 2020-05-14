#include<bits/stdc++.h>
using namespace std;
struct info {
	int id;
	string name;
	int grade;
};
vector<info> v;
bool cmp1(info &a, info &b) {
	return a.id < b.id;
}
bool cmp2(info &a, info &b) {
	if(a.name != b.name) return a.name < b.name;
	else return a.id < b.id;
}
bool cmp3(info &a, info &b) {
	if(a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}
bool (*cmp)(info &a, info &b);
int main() {
	int n, c, i, j;
	char cname[10];
	scanf("%d %d", &n, &c);
	for(i = 0; i < n; ++i) {
		info tmp;
		scanf("%d %s %d", &tmp.id, cname, &tmp.grade);
		tmp.name = string(cname, strlen(cname));
		v.emplace_back(tmp);
	}
	if(c == 1) cmp = cmp1;
	else if(c == 2) cmp = cmp2;
	else cmp = cmp3;
	sort(v.begin(), v.end(), cmp);
	for(i = 0; i < v.size(); ++i) printf("%06d %s %d\n", v[i].id, v[i].name.c_str(), v[i].grade);
	return 0;
}
