#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<string, string>> pwd;
bool judge(string &s) {
	bool flag = false;
	for(int i = 0; i < s.length(); ++i) {
		switch(s[i]) {
			case '1': 
				flag = true;
				s[i] = '@';
				break;
			case '0':
				flag = true;
				s[i] = '%';
				break;
			case 'l':
				flag = true;
				s[i] = 'L';
				break;
			case 'O':
				flag = true;
				s[i] = 'o';
				break;
		}
	}
	return flag;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	string id, p;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		cin >> id >> p;
		if(judge(p)) 
			pwd.push_back(make_pair(id, p)); 
	}
	if(pwd.empty()) 
		printf("There %s %d account%s and no account is modified", n == 1 ? "is" : "are", n, n == 1 ? "" : "s");
	else {
		printf("%d\n", pwd.size());
		for(i = 0; i < pwd.size(); ++i) {
			printf("%s %s\n", pwd[i].first.c_str(), pwd[i].second.c_str());
		}
	}
	return 0;
}
