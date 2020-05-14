#include<bits/stdc++.h>
#define IN 1
#define OUT 2
using namespace std;
struct car {
	string plate;
	int ctime;
	int status;
};
bool cmp(car &a, car &b) {
	return a.ctime < b.ctime;
}
vector<car> timelist, carlist;
map<string, int> timecnt;
int main() {
	int n, k, i, j, maxtime = -1, hh, mm, ss, cnt = 0;
	string plate, status;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; ++i) {
		cin >> plate;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cin >> status;
		car tmp {plate, hh * 60 * 60 + mm * 60 + ss, status == "in" ? IN : OUT};
		timelist.emplace_back(tmp);
	}
	sort(timelist.begin(), timelist.end(), cmp);
	for(auto s = timelist.begin(); s != timelist.end(); ++s) {
		if(s->status == IN) {
			auto ss = s;
			++ss;
			for(; ss != timelist.end(); ++ss) {
				if(s->plate == ss->plate && ss->status == OUT) {
					carlist.emplace_back(*s);
					carlist.emplace_back(*ss);
					int gap = ss->ctime - s->ctime;
					timecnt[s->plate] += gap;
					maxtime = maxtime < timecnt[s->plate] ? timecnt[s->plate] : maxtime;
					break;
				} else if(s->plate == ss->plate && ss->status == IN) break;
			}
		}
	}
	sort(carlist.begin(), carlist.end(), cmp);
	j = 0;
	for(i = 0; i < k; ++i) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int qtime = hh * 60 * 60 + mm * 60 + ss;
		while(j < carlist.size() && carlist[j].ctime <= qtime) {
			if(carlist[j].status == IN) ++cnt;
			else --cnt;
			++j;
		}
		printf("%d\n", cnt);
	}
	for(auto m = timecnt.begin(); m != timecnt.end(); ++m) {
		if(m->second == maxtime) printf("%s ", m->first.c_str());
	}
	printf("%02d:%02d:%02d\n", maxtime / 3600, maxtime % 3600 / 60, maxtime % 3600 % 60);
	return 0;
}
