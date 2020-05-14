#include<bits/stdc++.h>
using namespace std;
int sums[100005];
vector<pair<int, int>> subseq;
int main() {
	int n, m, i, j, cnt = 0, mini = 999999999;
	scanf("%d %d", &n, &m);
	sums[0] = 0;
	for(i = 1; i <= n; ++i) {
		scanf("%d", sums + i);
		sums[i] += sums[i - 1];
	}
	
	
//	// My solution 
//	i = j = 1;
//	while(i <= n && j <= n) {
//		cnt = sums[j] - sums[i - 1];
//		if(cnt < m) ++j;
//		else if(cnt == m) {
//			if(mini != 0) {
//				mini = 0;
//				subseq.clear();
//			}
//			subseq.emplace_back(make_pair(i, j));
//			++i;
//			++j;
//		} else {
//			if(mini == -1 || cnt - m < mini) {
//				mini = cnt - m;
//				subseq.clear();
//				subseq.emplace_back(make_pair(i, j));
//			} else if(cnt - m == mini) subseq.emplace_back(make_pair(i, j));
//			++i;
//		}
//	}

	/*Binary Search*/
	for(i = 1; i <= n; ++i) {
		int left = i, right = n, mid;
		while(left < right) {
			mid = (left + right) / 2;
			if(sums[mid] - sums[i - 1] >= m) right = mid;
			else if(sums[mid] - sums[i - 1] < m) left = mid + 1;
		}
		j = right;
		cnt = sums[j] - sums[i - 1];
		if(cnt - m > mini || cnt < m) continue;
		else {
			if(cnt - m < mini) {
				subseq.clear();
				mini = cnt - m;
			}
			subseq.emplace_back(make_pair(i, j));
		}
	}
	for(i = 0; i < subseq.size(); ++i) printf("%d-%d\n", subseq[i].first, subseq[i].second);
	return 0;
}
