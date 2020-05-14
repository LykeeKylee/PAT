#include <bits/stdc++.h>
using namespace std;
int pre[50005], in[50005];
map<int, int> posh;
bool findx = false;
void display(int low, int upper, int plow, int pupper) {
	if(low == upper && !findx) {
		cout << in[low] << endl;
		findx = true;
		return;
	}
	int root = pre[plow];
	int rpos = posh[root];
	if(rpos <= upper && rpos > low) {
		int size = rpos - low;
		display(low, rpos - 1, plow + 1, plow + size);
	} 
	else if(rpos == low) {
		int size = upper - rpos;
		display(low + 1, upper, plow + 1, plow + size);
	}
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for(i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
		posh[in[i]] = i;
	}
	display(0, n - 1, 0, n - 1);
	return 0;
}
