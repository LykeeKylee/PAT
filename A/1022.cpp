#include <bits/stdc++.h>
using namespace std;

//unordered_map<string, vector<int>> title, author, keywords, publisher;
//unordered_map<int, vector<int>> year;

//int main() {
//    int n, m, i;
//    string notfound = "Not Found";
//    cin >> n;
//    getchar();
//    for(i = 0; i < n; ++i) {
//        string a, b, c, d, e, f;
//        getline(cin, a);
//        getline(cin, b);
//        getline(cin, c);
//        getline(cin, d);
//        getline(cin, e);
//        getline(cin, f);
//        int id = atoi(a.c_str()), y = atoi(f.c_str());
//        transform(b.begin(), b.end(), b.begin(), ::tolower);
//        transform(c.begin(), c.end(), c.begin(), ::tolower);
//        transform(d.begin(), d.end(), d.begin(), ::tolower);
//        transform(e.begin(), e.end(), e.begin(), ::tolower);
//        title[b].emplace_back(id);
//        author[c].emplace_back(id);
//        auto left = d.begin(), right = d.begin();
//        for(; right != d.end(); ++right) {
//            if(*right == ' ') {
//                string tmp(left, right);
//                keywords[tmp].emplace_back(id);
//                left = right + 1;
//            }
//        }
//        string tmp(left, right);
//        keywords[tmp].emplace_back(id);
//        publisher[e].emplace_back(id);
//        year[y].emplace_back(id);
//    }
//    cin >> m;
//    getchar();
//    for(i = 0; i < m; ++i) {
//        string xx;
//        getline(cin, xx);
//        auto fenhao = find(xx.begin(), xx.end(), ':');
//        int type = atoi(xx.substr(0, fenhao - xx.begin()).c_str());
//        string k = xx.substr(fenhao - xx.begin() + 2, xx.end() - fenhao);
//        transform(k.begin(), k.end(), k.begin(), ::tolower);
//        if(type >= 1 && type <= 5) {
//            printf("%s\n", xx.c_str());
////            cout << k << endl;
//            if(type == 1) {
//                if(title.find(k) != title.end()) {
//                    vector<int> ptr = title[k];
//                    sort(ptr.begin(), ptr.end());
//                    for(auto j = ptr.begin(); j != ptr.end(); ++j)
//                        printf("%07d\n", *j);
//                }
//                else
//                    printf("%s\n", notfound.c_str());
//            }
//            else if(type == 2) {
//                if(author.find(k) != author.end()) {
//                    vector<int> *ptr = &author[k];
//                    sort(ptr->begin(), ptr->end());
//                    for(auto j = ptr->begin(); j != ptr->end(); ++j)
//                        printf("%07d\n", *j);
//                }
//                else
//                    printf("%s\n", notfound.c_str());
//            }
//            else if(type == 3) {
//                if(keywords.find(k) != keywords.end()) {
//                    vector<int> *ptr = &keywords[k];
//                    sort(ptr->begin(), ptr->end());
//                    for(auto j = ptr->begin(); j != ptr->end(); ++j)
//                        printf("%07d\n", *j);
//                }
//                else
//                    printf("%s\n", notfound.c_str());
//            }
//            else if(type == 4) {
//                if(publisher.find(k) != publisher.end()) {
//                    vector<int> *ptr = &publisher[k];
//                    sort(ptr->begin(), ptr->end());
//                    for(auto j = ptr->begin(); j != ptr->end(); ++j)
//                        printf("%07d\n", *j);
//                }
//                else
//                    printf("%s\n", notfound.c_str());
//            }
//            else {
//                int yy = atoi(k.c_str());
//                if(year.find(yy) != year.end()) {
//                    vector<int> *ptr = &year[yy];
//                    sort(ptr->begin(), ptr->end());
//                    for(auto j = ptr->begin(); j != ptr->end(); ++j)
//                        printf("%07d\n", *j);
//                }
//                else
//                    printf("%s\n", notfound.c_str());
//            }
//        }
//        else {
//            printf("%s\n", xx.c_str());
//            printf("%s\n", notfound.c_str());
//        }
//    }
//    return 0;
//}

unordered_map<string, vector<int>> title, author, keywords, publisher, year;

int main() {
    int n, m, i, id, type;
    string notfound = "Not Found", xx, query;
    cin >> n;
    getchar();
    for(i = 0; i < n; ++i) {
        string a, b, c, d, e, f;
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);
        getline(cin, d);
        getline(cin, e);
        getline(cin, f);
        id = atoi(a.c_str());
        title[b].emplace_back(id);
        author[c].emplace_back(id);
        auto left = d.begin(), right = d.begin();
        for(;right != d.end(); ++right) {
            if(*right == ' ') {
                string tmp(left, right);
                keywords[tmp].emplace_back(id);
                left = right + 1;
            }
        }
        string tmp(left, right);
        keywords[tmp].emplace_back(id);
        publisher[e].emplace_back(id);
        year[f].emplace_back(id);
    }
    cin >> m;
    getchar();
    for(i = 0; i < m; ++i) {
        getline(cin, xx);
        type = xx[0] - '0';
        query = xx.substr(3, xx.size() - 3);
        vector<int> *ptr = nullptr;
        if(type == 1 && title.find(query) != title.end()) ptr = &title[query];
        else if(type == 2 && author.find(query) != author.end()) ptr = &author[query];
        else if(type == 3 && keywords.find(query) != author.end()) ptr = &keywords[query];
        else if(type == 4 && publisher.find(query) != author.end()) ptr = &publisher[query];
        else if(type == 5 && year.find(query) != author.end()) ptr = &year[query];
        printf("%s\n", xx.c_str());
        if(ptr) {
            sort(ptr->begin(), ptr->end());
            for(auto j = ptr->begin(); j != ptr->end(); ++j) printf("%07d\n", *j);
        }
        else printf("%s\n", notfound.c_str());
    }
    return 0;
}