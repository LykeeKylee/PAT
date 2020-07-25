#include<bits/stdc++.h>
using namespace std;
map<char, int> precedence;
void init() {
	precedence['('] = 0;
	precedence[')'] = 0;
	precedence['+'] = 1;
	precedence['-'] = 1;
	precedence['*'] = 2;
	precedence['/'] = 2;
	precedence['%'] = 2;
}
// 1+((2+3)*4)-5
string normal2RPN(string &normal) {
    stack<char> s1, s2;
    string rpn;
    for(int i = 0; i < normal.size(); ++i) {
        if(isdigit(normal[i]))
            s2.push(normal[i]);
        else {
            if(s1.empty() || s1.top() == '(' || normal[i] == '(' || precedence[normal[i]] > precedence[s1.top()])
                s1.push(normal[i]);
            else if(normal[i] == ')') {
                while(s1.top() != '(') {
                    char t = s1.top();
                    s1.pop();
                    s2.push(t);
                }
                s1.pop();
            }
            else if(precedence[normal[i]] <= precedence[s1.top()]) {
                while(!s1.empty() && precedence[normal[i]] <= precedence[s1.top()]) {
                    char t = s1.top();
                    s1.pop();
                    s2.push(t);
                }
                s1.push(normal[i]);
            }
        }
    }
    while(!s1.empty()) {
        char t = s1.top();
        s2.push(t);
        s1.pop();
    }
    while(!s2.empty()) {
        char t = s2.top();
        rpn = t + rpn;
        s2.pop();
    }
    return rpn;
}
int calRPN(string &rpn) {
    stack<int> s;
    for(int i = 0; i < rpn.size(); ++i) {
        if(isdigit(rpn[i]))
            s.push(rpn[i] - '0');
        else {
            int a, b, c;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            switch (rpn[i]) {
                case '+': c = a + b;break;
                case '-': c = a - b;break;
                case '*': c = a * b;break;
                case '/': c = a / b;break;
                case '%': c = a % b;break;
            }
            s.push(c);
        }
    }
    return s.top();
}
string normal2PN(string &normal) {
    stack<char> s1, s2;
    string rpn;
    for(int i = normal.size() - 1; i >= 0; --i) {
        if(isdigit(normal[i]))
            s2.push(normal[i]);
        else {
            if(s1.empty() || s1.top() == ')' || normal[i] == ')' || precedence[normal[i]] >= precedence[s1.top()])
                s1.push(normal[i]);
            else if(normal[i] == '(') {
                while(s1.top() != ')') {
                    char t = s1.top();
                    s1.pop();
                    s2.push(t);
                }
                s1.pop();
            }
            else if(precedence[normal[i]] < precedence[s1.top()]) {
                while(!s1.empty() && precedence[normal[i]] < precedence[s1.top()]) {
                    char t = s1.top();
                    s1.pop();
                    s2.push(t);
                }
                s1.push(normal[i]);
            }
        }
    }
    while(!s1.empty()) {
        char t = s1.top();
        s2.push(t);
        s1.pop();
    }
    while(!s2.empty()) {
        char t = s2.top();
        rpn += t;
        s2.pop();
    }
    return rpn;
}
int calPN(string &pn) {
    stack<int> s;
    for(int i = pn.size() - 1; i >= 0; --i) {
        if(isdigit(pn[i]))
            s.push(pn[i] - '0');
        else {
            int a, b, c;
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            switch (pn[i]) {
                case '+': c = a + b;break;
                case '-': c = a - b;break;
                case '*': c = a * b;break;
                case '/': c = a / b;break;
                case '%': c = a % b;break;
            }
            s.push(c);
        }
    }
    return s.top();
}
int main() {
	init();
	string normal;
	cin >> normal;
    string rpn = normal2RPN(normal);
    string pn = normal2PN(normal);
    cout << pn << " = " << calPN(pn) << endl;
    cout << rpn << " = " << calRPN(rpn) << endl;
	return 0;
} 
