#include<bits/stdc++.h>
using namespace std;
int a[8] = {2, 3, 5, 6, 8, 9, 11, 15},
	b[7] = {1, 2, 3, 3, 3, 4, 5};
int binary_search(int x) {
	int left = 0, right = 7, mid;
	while(left <= right) {
		// mid = (left + right) / 2;
		mid = left + (right - left) / 2;
		if(a[mid] == x) 
			return mid;
		else if(a[mid] < x) left = mid + 1;
		else right = mid - 1; 
	}
	return -1;
}
// [a, b]
int lower_bound(int x) {
	int left = 0, right = 6, mid;
	while(left < right) {
		mid = left + (right - left) / 2;
		if(b[mid] < x) left = mid + 1;
		else right = mid;
	}
	return left;
}
int upper_bound(int x) {
	int left = 0, right = 6, mid;
	while(left + 1 < right) {
		mid = left + (right - left) / 2;
		if(b[mid] > x) right = mid;
		else left = mid + 1;
	}
	return left;
}
int main() {
	cout << binary_search(2) << endl;
	cout << binary_search(6) << endl;
	cout << binary_search(11) << endl;
	cout << binary_search(15) << endl;
	cout << binary_search(22) << endl << endl;
	
	printf("[%d, %d]\n", lower_bound(3), upper_bound(3));
	return 0;
}
