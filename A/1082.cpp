#include<bits/stdc++.h>
using namespace std;
string num, digit[5] = {"Fu", "Ge", "Shi", "Bai", "Qian"}, number[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}, output;
string convert(int start, int end) {
	if(start > end) return "";
	string temp;
	for(int i = start; i <= end; ++i) {
		if(num[i] != '0') {
			if(i != start && num[i - 1] == '0') temp += (number[0] + " ");
			temp += (number[num[i] - '0'] + " ");
			if(end - i != 0) temp += (digit[end - i + 1] + " ");
		}
	}
	return temp;
}
int main() {
	string flag;
	getline(cin, num);
	if(!isdigit(num[0])) {
		flag = digit[0] + " ";
		num.erase(0, 1);
	}
	int i, len = num.length(), clip = num.length() / 4, left = num.length() % 4;
	if(num == "0") {
		output = "ling ";
	} else {
		output += convert(0, left - 1);
		if(clip == 1 && left != 0) output += "Wan ";
		else if(clip == 2 && left != 0) output += "Yi ";
		for(i = 0; i < clip; ++i) {
			output += convert(left + i * 4, left + i * 4 + 3);
			if(clip == 2 && i == 0) output += "Wan ";
		}
	}
	output = flag + output;
	if(output.back() == ' ') output.back() = '\n';
	printf("%s", output.c_str());
	return 0;
}
