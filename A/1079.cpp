#include<bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> supply;
bool status[100005] = {false};
double sales = 0.0;
void dfs(int root, double p, double r, int level) {
	if(status[root]) {
		int cnt = supply[root][0];
		sales += cnt * p * pow(1.0 + r / 100.0, level);
		return;
	}
	vector<int> *v = &supply[root];
	for(int i = 0; i < (*v).size(); ++i) 
		dfs((*v)[i], p, r, level + 1);
}
int main() {
	int n, i, k, j, x;
	double price, r;
	scanf("%d %lf %lf", &n, &price, &r);
	for(i = 0; i < n; ++i) {
		scanf("%d", &k);
		if(k == 0) {
			scanf("%d", &x);
			supply[i].emplace_back(x);
			status[i] = true;
		}
		else {
			for(j = 0; j < k; ++j) {
				scanf("%d", &x);
				supply[i].emplace_back(x);
			}
		}
	}
	dfs(0, price, r, 0);
	printf("%0.1lf\n", sales);
	return 0;
}
