#include<bits/stdc++.h>
using namespace std;
int w[1004], turn[1005];
pair<int, int> ranks[1005];
vector<int> cur;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}
int main() {
	int np, ng, i, j, cturn, mw, mp;
	scanf("%d %d", &np, &ng);
	for(i = 0; i < np; ++i) scanf("%d", w + i);
	cur.resize(np);
	for(i = 0; i < np; ++i) scanf("%d", &cur[i]);
	cturn = 1;
	while(cur.size() != 1) {
		vector<int> next;
		for(i = 0; i < cur.size(); i += ng) {
			mp = cur[i];
			mw = w[mp];
			for(j = i + 1; j < cur.size() && j < i + ng; ++j) {
				if(w[cur[j]] > mw) {
					turn[mp] = cturn;
					mp = cur[j];
					mw = w[mp];
				} else turn[cur[j]] = cturn;
			}
			next.emplace_back(mp);
		}
		++cturn;
		cur = next;
	}
	turn[cur[0]] = cturn;
	for(i = 0; i < np; ++i) ranks[i] = make_pair(i, turn[i]);
	sort(ranks, ranks + np, cmp);
	int offset = 1, cur_rank = 0;
	cturn = ranks[0].second + 1;
	for(i = 0; i < np; ++i) {
		if(ranks[i].second != cturn) {
			cur_rank += offset;
			offset = 1;
		} 
		else ++offset;
		w[ranks[i].first] = cur_rank;
		cturn = ranks[i].second;
	}
	for(i = 0; i < np; ++i) printf("%d%s", w[i], i == np - 1 ? "\n" : " ");
	return 0;
}
