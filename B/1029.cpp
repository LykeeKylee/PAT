#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool flag[37];

int main() {
    string wishInput, realInput;
    cin >> wishInput >> realInput;
    memset(flag, false, sizeof(flag));
    for(int i = 0; i < wishInput.length(); ++i) {
        if(wishInput[i] >= '0' && wishInput[i] <= '9' && !flag[26 + wishInput[i] - '0']) {
            flag[26 + wishInput[i] - '0'] = true;
            if(realInput.find(wishInput[i]) == string::npos)
                cout << wishInput[i];
        }
        else if(wishInput[i] >= 'a' && wishInput[i] <= 'z' && !flag[wishInput[i] - 'a']) {
            flag[wishInput[i] - 'a'] = true;
            if(realInput.find(wishInput[i]) == string::npos)
                cout << char(wishInput[i] - 'a' + 'A');
        }
        else if(wishInput[i] >= 'A' && wishInput[i] <= 'Z' && !flag[wishInput[i] - 'A']) {
            flag[wishInput[i] - 'A'] = true;
            if(realInput.find(wishInput[i]) == string::npos)
                cout << wishInput[i];
        }
        else if(wishInput[i] == '_' && !flag[36]) {
            flag[36] = true;
            if(realInput.find(wishInput[i]) == string::npos)
                cout << wishInput[i];
        }
    }
    return 0;
}

//���ģʽ
//#include <iostream>
//#include <cctype>
//using namespace std;
//int main() {
//    string s1, s2, ans;
//    cin >> s1 >> s2;
//    for (int i = 0; i < s1.length(); i++)
//        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
//            ans += toupper(s1[i]);
//    cout << ans;
//    return 0;
//}
//��������������������������������
//��Ȩ����������ΪCSDN����������051����ԭ�����£���ѭ CC 4.0 BY ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/shiliang97/article/details/100085619