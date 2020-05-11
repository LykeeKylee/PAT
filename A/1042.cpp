#include<bits/stdc++.h>
using namespace std;
vector<string> card(60), tmp(60);
int shuffles[60];
int main() {
	int k, i, j, cnt = 1;
	string color[] = {"S", "H", "C", "D", "J"};
	scanf("%d", &k);
	for(i = 0; i < 5; ++i) {
		if(color[i] != "J") {
			for(j = 1; j <= 13; ++j) {
				card[cnt++] = color[i] + to_string(j);
			}
		}
		else {
			for(j = 1; j <= 2; ++j) {
				card[cnt++] = color[i] + to_string(j);
			}
		}
	}
	for(i = 1; i <= 54; ++i) scanf("%d", shuffles + i);
	for(i = 0; i < k; ++i) {
		for(j = 1; j <= 54; ++j) tmp[shuffles[j]] = card[j];
		card = tmp;
	}
	for(i = 1; i <= 54; ++i) printf("%s%s", card[i].c_str(), i == 54 ? "\n" : " ");
	return 0;
} 
