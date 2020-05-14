#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int cyear = 2014, cmonth = 9, cday = 6;

struct birthdate {
    string name;
    int year;
    int month;
    int day;
};

void assign(birthdate &a, birthdate &b) {
    a.year = b.year;
    a.name = b.name;
    a.month = b.month;
    a.day = b.day;
}

void compare(string &name, int year, int month, int day, bool &flag, birthdate &youngest, birthdate &eldest) {
    birthdate tmp = {name, year, month, day};
    if(flag) {
        assign(youngest, tmp);
        assign(eldest, tmp);
        flag = false;
    }
    else {
        if(year > youngest.year || (year == youngest.year && month > youngest.month) || (year == youngest.year && month == youngest.month && day > youngest.day)) {
            assign(youngest, tmp);
        }

        if(year < eldest.year || (year == eldest.year && month < eldest.month) || (year == eldest.year && month == eldest.month && day < eldest.day)) {
            assign(eldest, tmp);
        }
    }
}

int main() {
    int n;
    cin >> n;
    string name, date;
    int legal = 0,  year, month, day;
    birthdate youngest, eldest;
    bool flag = true;
    vector<birthdate> seq;
    while(n--) {
        cin >> name >> date;
        year =  atoi(date.substr(0, 4).c_str());
        month = atoi(date.substr(5, 2).c_str());
        day = atoi(date.substr(8, 2).c_str());

        if(cyear - year < 200 && cyear - year > 0) {
            compare(name, year, month, day, flag, youngest, eldest);
            legal++;
        }
        else if(cyear - year == 200) {
            if(month > cmonth || (month == cmonth && day >= cday)) {
                compare(name, year, month, day, flag, youngest, eldest);
                legal++;
            }
        }
        else if(cyear - year == 0) {
            if(month < cmonth || (month == cmonth && day <= cday)) {
                compare(name, year, month, day, flag, youngest, eldest);
                legal++;
            }
        }
    }

    cout << legal;
    if(legal != 0)
        cout << ' ' << eldest.name << ' ' << youngest.name;
    return 0;
}