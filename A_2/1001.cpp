#include<bits/stdc++.h>
using namespace std;
int a, b;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j = 1, c;
	string sign, str;
	scanf("%d %d", &a, &b);
	c = a + b;
	if(c < 0) sign = "-";
	else sign = "";
	str = to_string(abs(c));
	vector<char> ans;
	for(i = str.length() - 1, j = 0; i >= 0; --i) {
		++j;
		ans.push_back(str[i]);
		if(j % 3 == 0 && i != 0) {
			ans.push_back(',');
			j = 0;
		}
	}
	printf("%s", sign.c_str());
	for(i = ans.size() - 1; i >= 0; --i) printf("%c", ans[i]);
	return 0;
} 
