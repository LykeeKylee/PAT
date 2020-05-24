#include<bits/stdc++.h>
using namespace std;
struct station {
	double price, dst;
};
bool cmp(station &a, station &b) {
	return a.dst < b.dst;
}
vector<station> allstations;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, i, j;
	double cmax, d, davg;
	scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
	for(i = 0; i <= n; ++i) {
		station tmp;
		if(i != n) scanf("%lf %lf", &tmp.price, &tmp.dst);
		else tmp = {0.0, d};
		allstations.emplace_back(tmp);
	}
	sort(allstations.begin(), allstations.end(), cmp);
	if(allstations.empty() || allstations.front().dst != 0.0) printf("The maximum travel distance = %0.2lf\n", 0.0);
	else {
		bool arrive = true;
		double curprice = 0.0, curdst = 0.0, curtank = 0.0, maxdst = 0.0, mins;
		i = 0;
		while(i < n) {
			bool flag = false;
			mins = j = i + 1;
			maxdst = cmax * davg + curdst;
			while(j < n + 1 && allstations[j].dst <= maxdst) {
				flag = true;
				mins = allstations[j].price < allstations[mins].price ? j : mins;
				++j;
				if(allstations[mins].price < allstations[i].price) break;
			}
			if(!flag) {
				if(j == n + 1) arrive = true;
				else arrive = false;
				break;
			}
			else {
				if(allstations[mins].price > allstations[i].price) {
					curprice += (cmax - curtank) * allstations[i].price;
					curtank = cmax - (allstations[mins].dst - curdst) / davg;
				}
				else {
					double gas = (allstations[mins].dst - curdst) / davg;
					if(gas >= curtank) {
						curprice += (gas - curtank) * allstations[i].price;
						curtank = 0.0;
					}
					else curtank -= gas;
				}
				curdst = allstations[mins].dst;
				i = mins;
			}
		}
		if(!arrive) printf("The maximum travel distance = %0.2lf\n", maxdst);
		else printf("%0.2f\n", curprice);
	}
	return 0;
} 
