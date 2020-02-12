//
// Created by Lykee on 2020/2/11.
//
#include <iostream>
#include <string>
using namespace std;

struct stu{
    string name;
    string course;
    int score;
};

void copy(stu &x, string &name, string &course, int &score){
    x.name = name;
    x.course = course;
    x.score = score;
}

int main()
{
    int samples, score;
    string name, course;
    stu minStu, maxStu;
    cin >> samples;
    for(int i = 0; i < samples; ++i)
    {
        cin >> name >> course >> score;
        if(i == 0)
        {
            copy(minStu, name, course, score);
            copy(maxStu, name, course, score);
        }
        else
        {
            if(score > maxStu.score)
                copy(maxStu, name, course, score);
            if(score < minStu.score)
                copy(minStu, name, course, score);
        }
    }
    cout<<maxStu.name<<' '<<maxStu.course<<endl;
    cout<<minStu.name<<' '<<minStu.course;
    return 0;
}