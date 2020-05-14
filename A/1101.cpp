#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j, seq[100005], Left[100005], Right[100005], leftmax = -1, rightmin = 999999999;
	scanf("%d", &n);
	vector<int> pivot;
	for(i = 0; i < n; ++i) {
		scanf("%d", seq + i);
		Left[i] = leftmax;
		leftmax = seq[i] > leftmax ? seq[i] : leftmax;
	}
	for(i = n - 1; i >= 0; --i) {
		Right[i] = rightmin;
		rightmin = seq[i] < rightmin ? seq[i] : rightmin; 
	}
	for(i = 0; i < n; ++i) {
		if(Left[i] <= seq[i] && seq[i] <= Right[i]) pivot.push_back(seq[i]);
	}
	printf("%d\n", pivot.size());
	for(i = 0; i < pivot.size(); ++i) {
		printf("%d%s", pivot[i], i == (pivot.size() - 1) ? "" : " ");
	}
	printf("\n");
	return 0; 
} 
