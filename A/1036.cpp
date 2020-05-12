#include<bits/stdc++.h>
using namespace std;
vector<string> ids, pwds;
int main() {
	int n, i, j, cnt = 0;
	scanf("%d", &n);
	char id[20], pwd[20];
	bool flag = false;
	for(i = 0; i < n; ++i) {
		scanf("%s %s", id, pwd);
		flag = false;
		for(j = 0; j < strlen(pwd); ++j) {
			if(pwd[j] == '1' || pwd[j] == '0' || pwd[j] == 'l' || pwd[j] == 'O') {
				flag = true;
				switch (pwd[j]) {
					case '1':
						pwd[j] = '@';
						break;
					case '0':
						pwd[j] = '%';
						break;
					case 'l':
						pwd[j] = 'L';
						break;
					case 'O':
						pwd[j] = 'o';
						break;
				}
			}
		}
		if(flag) {
			++cnt;
			string tid(id, strlen(id)), tpwd(pwd, strlen(pwd));
			ids.emplace_back(tid);
			pwds.emplace_back(tpwd);
		}
	}
	if(cnt == 0) printf("There %s %d account%s and no account is modified\n", n == 1 ? "is":"are", n, n == 1 ? "": "s");
	else {
		printf("%d\n", cnt);
		for(i = 0; i < cnt; ++i) printf("%s %s\n", ids[i].c_str(), pwds[i].c_str());
	}
	return 0;
}
