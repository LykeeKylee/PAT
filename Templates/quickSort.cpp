#include<bits/stdc++.h>
using namespace std;
const int msize = 9;
int a[msize] = {4, 5, 1, 3, 6, 8, 3, 2, 9};
int get_rand(int L, int R) {
	return (int)(rand() % (R - L + 1) + L);
} 
int partition(int L, int R) {
	int pivot = get_rand(L, R), tmp;
	swap(a[L], a[pivot]);
	tmp = a[L];
	while(L < R) {
		while(L < R && a[R] > tmp) R--;
		a[L] = a[R];
		while(L < R && a[L] <= tmp) L++;
		a[R] = a[L]; 
	}
	a[L] = tmp;
	return L;
}
int quickSort(int L, int R) {
	if(L < R) {
		int P = partition(L, R);
		quickSort(L, P - 1);
		quickSort(P + 1, R);
	}
}
int main() {
	int i = 0;
	for(i = 0; i < 9; ++i) cout << a[i] << ' ';
	cout << endl;
	quickSort(0, 8);
	for(i = 0; i < 9; ++i) cout << a[i] << ' ';
	cout << endl; 
} 
