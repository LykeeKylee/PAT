#include<bits/stdc++.h>
using namespace std;
const int off = 0, on = 1;
struct record {
	string name;
	int recordTime;
	int status;
};
int toll[24], n, month = -1;
double daybill = 0.0;
vector<record> records;
bool cmp(record &a, record &b) {
	if(a.name != b.name) return a.name < b.name;
	else return a.recordTime < b.recordTime;
}
double getbillformzero(int d, int h, int m) {
	double bill = 0.0;
	bill += d * daybill;
	for(int i = 0; i < h; ++i) bill += toll[i] * 60;
	bill += m * toll[h];
	return bill;
}
double calbill(int ontime, int offtime) {
	int dd1, hh1, mm1, dd2, hh2, mm2, delta;
	double bill1 = 0.0, bill2 = 0.0, bill;
	delta = offtime - ontime;
	dd1 = ontime / (24 * 60);
	ontime %= (24 * 60);
	hh1 = ontime / 60;
	ontime %= 60;
	mm1 = ontime;
	dd2 = offtime / (24 * 60);
	offtime %= (24 * 60);
	hh2 = offtime / 60;
	offtime %= 60;
	mm2 = offtime;
	bill = (getbillformzero(dd2, hh2, mm2) - getbillformzero(dd1, hh1, mm1)) / 100.0;
	printf("%02d:%02d:%02d %02d:%02d:%02d %d $%0.2lf\n", dd1, hh1, mm1, dd2, hh2, mm2, delta, bill);
	return bill;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	for(i = 0; i < 24; ++i) {
		scanf("%d", toll + i);
		daybill += toll[i] * 60;
	}
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		record tmp;
		int MM, DD, hh, mm, recordTime = 0;
		char status[10];
		cin >> tmp.name;
		scanf("%d:%d:%d:%d", &MM, &DD, &hh, &mm);
		scanf("%s", status);
		if(month == -1) month = MM;
		if(strlen(status) == 7) tmp.status = on;
		else tmp.status = off;
		recordTime = DD * 24 * 60 + hh * 60 + mm;
		tmp.recordTime = recordTime;
		records.push_back(tmp);
	}
	sort(records.begin(), records.end(), cmp);
	vector<record> recordlist;
	string curName = records[0].name;
	for(i = 0; i < records.size(); ++i) {
		if(records[i].name != curName)
			curName = records[i].name;
		if(records[i].name == curName) {
			 if(records[i].status == on) {
			 	if(i + 1 < records.size() && records[i + 1].name == curName && records[i + 1].status == off) {
			 		recordlist.push_back(records[i]);
			 		recordlist.push_back(records[i + 1]);
				 }
			 }
		}
	}
	i = 0;
	curName = "0";
	double billcnt = 0.0;
	while(i < recordlist.size()) {
		if(curName != recordlist[i].name) {
			if(curName != "0") {
				printf("Total amount: $%0.2lf\n", billcnt);
				billcnt = 0.0;
			}
			curName = recordlist[i].name;
			printf("%s %02d\n", curName.c_str(), month);
		}
		billcnt += calbill(recordlist[i].recordTime, recordlist[i + 1].recordTime);
		i += 2;
		if(i >= recordlist.size()) printf("Total amount: $%0.2lf\n", billcnt);
	}
	return 0;
}
