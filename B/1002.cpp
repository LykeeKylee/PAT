#include <string>
#include <iostream>
using namespace std;

void translate(int x){
	switch(x){
		case 0:
			cout << "ling";
			break;
		case 1:
			cout << "yi";
			break;
		case 2:
			cout << "er";
			break;
		case 3:
			cout << "san";
			break;
		case 4:
			cout << "si";
			break;
		case 5:
			cout << "wu";
			break;
		case 6:
			cout << "liu";
			break;
		case 7:
			cout << "qi";
			break;
		case 8:
			cout << "ba";
			break;
		case 9:
			cout << "jiu";
			break;
        default:
            break;
	}
}

int main(){
	string number, re;
	int sum = 0;
	cin >> number;
	for(int i = 0; i < number.length(); ++i)
	{
		sum += int(number[i] - '0');
	}
	re = to_string(sum);
	for(int i = 0; i < re.length(); ++i)
	{
		translate(int(re[i] - '0'));
		if(i < re.length() - 1){
			cout<<' ';
		}
	}
	return 0;
}
