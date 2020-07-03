#include<bits/stdc++.h>
using namespace std;
int n;
bool judge(string &num) {
	int dot = -1;
	for(int i = 0; i < num.length(); ++i) {
		if(num[i] == '.') {
			if(dot == -1) 
				dot = i;
			else 
				return false;
		}
		else if(isalpha(num[i])) 
			return false;
	}
	if(dot != -1 && num.length() - 1 - dot > 2) return false;
	return true;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j = 0;
	double sum = 0.0;
	string num;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		cin >> num;
		if(judge(num)) {
			double t = atof(num.c_str());
			if(t <= 1000.0 && t >= -1000.0) {
				sum += atof(num.c_str());
				++j;
			}
			else printf("ERROR: %s is not a legal number\n", num.c_str());
		}
		else printf("ERROR: %s is not a legal number\n", num.c_str());
	}
	if(j == 0) printf("The average of 0 numbers is Undefined");
	else if(j == 1) printf("The average of 1 number is %0.2lf", sum);
	else printf("The average of %d numbers is %0.2lf", j, sum / j);
	return 0;
}
