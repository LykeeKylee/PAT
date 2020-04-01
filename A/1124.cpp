#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, n, s, i, j;
	scanf("%d %d %d", &m, &n, &s);
	vector<string> forward(m + 1), winners;
	for(i = 1; i <= m; ++i) cin >> forward[i];
	map<string, int> hasWin;
	i = s;
	while(i <= m) {
		if(hasWin[forward[i]] == 0) {
			winners.emplace_back(forward[i]);
			hasWin[forward[i]] = 1;
			i += n;
		}
		else i += 1;
	}
	if(winners.size() == 0) printf("Keep going...\n");
	else {
		for(i = 0; i < winners.size(); ++i) printf("%s\n", winners[i].c_str());
	}
	return 0;
} 
