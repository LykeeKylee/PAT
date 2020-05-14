#include<bits/stdc++.h>
using namespace std;
struct cake {
	int id;
	double price;
};
double inventory[1002], total_price[1002], total = 0.0;
cake price[1002];
bool cmp(cake &a, cake &b) {
	return a.price > b.price;
}
int main() {
	int n, d, i, j;
	scanf("%d %d", &n, &d);
	for(i = 0; i < n; ++i) scanf("%lf", inventory + i);
	for(i = 0; i < n; ++i) {
		scanf("%lf", total_price + i);
		price[i].id = i;
		price[i].price = total_price[i] / inventory[i];
	}
	sort(price, price + n, cmp);
	i = 0;
	while(d > 0 && i < n) {
		if(inventory[price[i].id] <= d) {
			total += total_price[price[i].id];
			d -= inventory[price[i].id];
		}
		else {
			total += price[i].price * d;
			d -= d;
		}
		++i;
	}
	printf("%0.2lf\n", total);
}
