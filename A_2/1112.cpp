#include<bits/stdc++.h>
using namespace std;
#define UNKNOWN 0
#define SAFE 1
struct status {
	int cnt;
	int type;
};
int times;
string str;
status keyboard[256];
bool isStuck[256], visit[256];
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif
	int i, cnt = 0;
	char cc;
	scanf("%d", &times);
	getchar();
	getline(cin, str);
	str += "*";
	cc = str[0];
	for(i = 0; i < str.length(); ++i) {
		if(str[i] == cc) ++cnt;
		else {
			if(cnt % times == 0) keyboard[int(cc)].cnt += cnt / times;
			else keyboard[int(cc)].type = SAFE;
			cc = str[i];
			cnt = 1;
		}
	}
	for(i = 0; i < 256; ++i) {
		if(keyboard[i].type == UNKNOWN && keyboard[i].cnt > 0) isStuck[i] = true;
	}
	vector<char> stuckchar;
	string ans;
	for(i = 0; i < str.length() - 1; ++i) {
		if(isStuck[int(str[i])]) {
			ans += str[i];
			if(!visit[int(str[i])]) {
				stuckchar.push_back(str[i]);
				visit[int(str[i])] = true;
			}
			cc = str[i];
			i += (times - 1);
		} else
			ans += str[i];
	}
	for(i = 0; i < stuckchar.size(); ++i) printf("%c%s", stuckchar[i], i == stuckchar.size() - 1 ? "\n" : "");
	printf("%s", ans.c_str());
	return 0;
}
