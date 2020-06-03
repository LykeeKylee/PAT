#include<bits/stdc++.h>
using namespace std;
const int msize = 10000;
int a[msize] = {4, 5, 1, 3, 6, 8, 3, 2, 9};
void merge(int left1, int right1, int left2, int right2) {
	int tmp[msize], idx = 0, i = left1, j = left2;
	while(i <= right1 && j <= right2) {
		if(a[i] <= a[j]) 
			tmp[idx++] = a[i++];
		else 
			tmp[idx++] = a[j++];
	}
	while(i <= right1) 
		tmp[idx++] = a[i++];
	while(j <= right2) 
		tmp[idx++] = a[j++];
	for(i = 0; i < idx; ++i) 
		a[left1 + i] = tmp[i];
}
void mergeSort1(int L, int R) {
	if(L < R) {
		int mid = L + (R - L) / 2;
		mergeSort1(L, mid);
		mergeSort1(mid + 1, R);
		merge(L, mid, mid + 1, R);
	}
}
void mergeSort2(int size) {
	for(int step = 2; step / 2 <= size; step *= 2) {
		for(int i = 0; i < size; i += step) {
			int mid = (i + i + step - 1) / 2;
			if(mid + 1 < size)
				merge(i, mid, mid + 1, min(i + step - 1, size));
		}
	}
}
int main() {
	int i = 0;
	for(i = 0; i < 9; ++i) cout << a[i] << ' ';
	cout << endl;
//	mergeSort1(0, 8);
	mergeSort2(9);
	for(i = 0; i < 9; ++i) cout << a[i] << ' ';
	cout << endl; 
} 
