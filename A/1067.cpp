#include<bits/stdc++.h>
using namespace std;
int a[100005], pos[100005];
set<int> unordered;
int main() {
	int n, i, j, step = 0, ordered = 0;
	scanf("%d", &n);
//	for(i = 0; i < n; ++i) {
//		scanf("%d", a + i);
//		pos[a[i]] = i;
//		if(a[i] == i && i != 0) ++ordered;
//		else if(i != 0) unordered.insert(i);
//	}
//	while(ordered < n - 1) {
//		if(pos[0] == 0) {
//			i = *unordered.begin();
//			swap(a[0], a[pos[i]]);
//			pos[0] = pos[i];
//			pos[i] = 0;
//			++step;
//			continue;
//		}
//		int next = pos[0], next_pos = pos[pos[0]];
//		swap(a[pos[0]], a[next_pos]);
//		pos[0] = next_pos;
//		pos[next] = next;
//		unordered.erase(next);
//		++ordered;
//		++step;
//	}

	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		pos[j] = i;
	}
	for(i = 1; i < n; ++i) {
		if(pos[i] != i) {
			while(pos[0] != 0) {
				swap(pos[0], pos[pos[0]]);
				++step; 
			}
			if(pos[i] != i) {
				swap(pos[0], pos[i]);
				++step;
			} 
		}
	}
	cout << step << endl;
	return 0;
}
