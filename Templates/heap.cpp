#include<bits/stdc++.h>
using namespace std;
void shiftDown(int root, int high, int a[]) {
	int i = root, j = 2 * root + 1;
	while(j < high) {
		if(j + 1 < high && a[j] < a[j + 1])
			++j;
		if(a[i] < a[j]) {
			swap(a[i], a[j]);
			i = j;
			j = 2 * i + 1;
		}
		else break; 
	}
}
void heapify(int size, int a[]) {
	for(int i = size / 2 - 1; i >= 0; --i)
		shiftDown(i, size, a); 
}
void heapSort(int size, int a[]) {
	if(size <= 0) return;
	swap(a[0], a[size - 1]);
	size--;
	shiftDown(0, size, a);
	heapSort(size, a);
}
void print(int a[], int size) {
	for(int i = 0; i < size; ++i)
		cout << a[i] << (i == size - 1 ? "\n" : " ");
}
int main() {
	int a[10] = {8, 9, 2, 3, 5, 6, 1, 0, 4, 7};
	heapify(10, a);
	print(a, 10);
	heapSort(10, a);
	print(a, 10);
	return 0;
}
