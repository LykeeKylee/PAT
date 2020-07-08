#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string n1, n2;
ll tag, radix;
ll convert(string x, ll rad) {
	ll r = 0, flag = 1;
	for(int i = x.length() - 1; i >= 0; --i) {
		if(isdigit(x[i])) r += (x[i] - '0') * flag;
		else r += (x[i] - 'a' + 10) * flag;
		flag *= rad;
	}
	return r;
}
ll find_radix() {
	ll nn = tag == 1 ? convert(n1, radix) : convert(n2, radix), r = 2, ans = -1;
	string a = tag == 1 ? n2 : n1;
	char maxc = *max_element(a.begin(), a.end());
	ll low = (isdigit(maxc) ? maxc - '0': maxc - 'a' + 10) + 1;
	ll high = max(low, nn);
	while(low <= high) {
		ll mid = (low + high) / 2;
		ll c = convert(a, mid);
		if(c == nn) {
			ans = mid;
			break;
		}
		else if(c < 0 || c > nn) high = mid - 1;
		else low = mid + 1;
	}
	return ans;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	cin >> n1 >> n2 >> tag >> radix;
	ll ans = find_radix();
	if(ans == -1) printf("Impossible");
	else cout << ans;
	return 0;
}
