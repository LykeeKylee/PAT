#include<bits/stdc++.h>
using namespace std;
const int msize = 100000;
int src[msize];
// initialize
void init() {
	for(int i = 0; i < msize; ++i) src[i] = i;
}
// find the root
int find_root(int child) {
	int root = child, childtmp;
	while(src[root] != root) root = src[root];
	while(src[child] != child) {
		childtmp = src[child];
		src[child] = root;
		child = src[childtmp];
	}
	return root;
}
// union
void unionize(int x, int y) {
	int x_root = find_root(x), y_root = find_root(y);
	// if x and y have different roots, merge them.
	if(x_root != y_root) src[y_root] = x_root;
}
int main() {
	init();
	/*
		input x, y
		unionize(x, y)
		
		x_root = find(root)
	*/
}
