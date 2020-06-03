#include<bits/stdc++.h>
using namespace std;
int main() {
	srand((double)time(NULL));
	for(int i = 0; i < 10; ++i)
		cout << rand() << ' ';
	cout << endl;
	// [3, 7]
	for(int i = 0; i < 10; ++i)
		cout << rand() % 5 + 3 << ' ';
	cout << endl;
	// [100000, 500000]
	for(int i= 0; i < 10; ++i)
		cout <<	int(rand() * 1.0 / RAND_MAX * 400000 + 100000) << ' ';
	cout << endl;
	return 0; 
}
