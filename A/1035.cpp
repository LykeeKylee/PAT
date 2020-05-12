#include<bits/stdc++.h>
using namespace std;
struct g {
	string name;
	char gender;
	string id;
	int grade;
};
vector<g> male, female;
bool cmp(g &a, g &b) {
	return a.grade < b.grade;
}
int main() {
	int n, i, j, grade;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		g tmp;
		cin >> tmp.name >> tmp.gender >> tmp.id >> tmp.grade;
		if(tmp.gender == 'M') male.emplace_back(tmp);
		else female.emplace_back(tmp);
	}
	sort(male.begin(), male.end(), cmp);
	sort(female.begin(), female.end(), cmp);
	if(female.empty()) printf("Absent\n");
	else printf("%s %s\n", female.back().name.c_str(), female.back().id.c_str());
	if(male.empty()) printf("Absent\n");
	else printf("%s %s\n", male.front().name.c_str(), male.front().id.c_str());
	if(female.empty() || male.empty()) printf("NA\n");
	else printf("%d\n", female.back().grade - male.front().grade);
	return 0;
}
