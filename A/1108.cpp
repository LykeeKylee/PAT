#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j, cnt = 0;
	scanf("%d", &n);
	string num;
	double sum = 0.0, tmp;
	for(i = 0; i < n; ++i) {
		cin >> num;
		j = (num[0] == '-' ? 1 : 0);
		bool legal = true;
		int dot = -1;
		for(; j < num.length() && legal; ++j) {
			if(num[j] == '.') {
				if(dot == -1) dot = j;
				else legal = false;
			} else if(!isdigit(num[j])) legal = false;
		}
		if(!legal || (dot != -1 && num.length() - 1 - dot > 2)) printf("ERROR: %s is not a legal number\n", num.c_str());
		else {
			tmp = atof(num.c_str());
			if(tmp > 1000.0 || tmp < -1000.0) printf("ERROR: %s is not a legal number\n", num.c_str());
			else {
				sum += tmp;
				++cnt;
			}
		}
	}
	if(cnt == 0) printf("The average of %d numbers is Undefined", cnt);
	else printf("The average of %d %s is %0.2lf", cnt, (cnt == 1 ? "number" : "numbers"), sum / cnt);
	return 0;
}
