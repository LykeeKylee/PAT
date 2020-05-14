#include<bits/stdc++.h>
using namespace std;
vector<long long> posc, negc, posp, negp;
int main() {
	int nc, np, i, j;
	long long t, cnt = 0;
	scanf("%d", &nc);
	for(i = 0; i < nc; ++i) {
		scanf("%lld", &t);
		if(t > 0) posc.emplace_back(t);
		else negc.emplace_back(t);
	}
	scanf("%d", &np);
	for(i = 0; i < np; ++i) {
		scanf("%lld", &t);
		if(t > 0) posp.emplace_back(t);
		else negp.emplace_back(t);
	}
	sort(posc.begin(), posc.end(), greater<long long>());
	sort(negc.begin(), negc.end());
	sort(posp.begin(), posp.end(), greater<long long>());
	sort(negp.begin(), negp.end());
	int len = posc.size() > posp.size() ? posp.size() : posc.size();
	for(i = 0; i < len; ++i) {
		cnt += (posc[i] * posp[i]);
	}
	len = negc.size() > negp.size() ? negp.size() : negc.size();
	for(i = 0; i < len; ++i) {
		cnt += (negc[i] * negp[i]);
	}
	printf("%d\n", cnt);
	return 0;
}
