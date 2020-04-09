#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j;
	scanf("%d", &n);
	getchar();
	string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly","aug", "sep", "oct", "nov", "dec"}, 
	high[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	map<string, int> convertLow, convertHigh;
	for(i = 0; i < 13; ++i) {
		convertLow[low[i]] = i;
		convertHigh[high[i]] = i;
	}
	for(i = 0; i < n; ++i) {
		string x;
		getline(cin, x);
		if(isdigit(x[0])) {
			int num = atoi(x.c_str());
			vector<int> mars;
			if(num == 0) mars.emplace_back(0);
			while(num != 0) {
				mars.emplace_back(num % 13);
				num /= 13;
			}
			if(mars.size() == 1) printf("%s\n", low[mars[0]].c_str());
			else {
				if(mars[0] == 0) printf("%s\n", high[mars[1]].c_str());
				else printf("%s %s\n", high[mars[1]].c_str(), low[mars[0]].c_str());
			}
			
		}
		else {
			auto blank = x.find(' ');
			if(blank == x.npos) {
				if(convertLow.find(x) != convertLow.end()) printf("%d\n", convertLow[x]);
				else printf("%d\n", convertHigh[x] * 13);
			}
			else printf("%d\n", convertHigh[x.substr(0, blank)] * 13 + convertLow[x.substr(blank + 1, x.size() - 1 - blank)]);
		}
	}
	return 0;
}
