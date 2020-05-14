#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j, k, row, col, tmp;
	scanf("%d", &n);
	for(row = 1; row <= n; ++row) {
		col = n / row;
		if(row * col == n && row >= col) break;
	}
	vector<int> a(n);
	vector<vector<int>> matrix(row, vector<int>(col));
	for(i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end(), greater<int>());
	i = j = k = 0;
	while(i < n) {
		tmp = j + col;
		for(; j < tmp && i < n; ++j, ++i) matrix[k][j] = a[i];
		--j;
		++k;
		tmp = k + row - 2;
		for(; k < tmp && i < n; ++k, ++i) matrix[k][j] = a[i];
		tmp = j - col;
		for(; j > tmp && i < n; --j, ++i) matrix[k][j] = a[i];
		++j;
		--k;
		tmp = k - (row - 2);
		for(; k > tmp && i < n; --k, ++i) matrix[k][j] = a[i];
		++j;
		++k;
		row -= 2;
		col -= 2;
	}
	for(i = 0; i < matrix.size(); ++i) {
		for(j = 0; j < matrix[i].size(); ++j)
			printf("%d%s", matrix[i][j], j == matrix[i].size() - 1 ? "\n" : " ");
	}
	return 0;
}

