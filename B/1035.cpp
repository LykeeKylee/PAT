#include <bits/stdc++.h>
using namespace std;

void show(int a[], int size){
    for(int i = 0; i < size; ++i)
        printf("%s%d", (i == 0 ? "" : " "), a[i]);
}

bool equal(int a[], int b[], int size) {
    for(int i = 0; i < size; ++i) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int n, *a, *b, pos = 0;
    bool flag = true, ret = true;
    cin >> n;
    a = new int[n], b = new int [n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        if(i > 0 && flag && b[i] < b[i - 1]) {
            flag = false;
            pos = i;
        }
        if(!flag && ret && b[i] != a[i]) ret = false;
    }
    if(ret) {
        cout << "Insertion Sort" << endl;
        sort(b, b + pos + 1);
        show(b, n);
    }
    else {
        cout << "Merge Sort" << endl;
        int size = 2;
        while(!equal(a, b, n)) {
            for(int i = 0; i < n / size * size; i += size)
                 sort(a + i, a + i + size);
            if(n - n / size * size != 0)
                sort(a + n / size * size, a + n / size * size + n - n / size * size);
            size *= 2;
        }
        if(size >= n) sort(b, b + n);
        else {
            for(int i = 0; i < n / size * size; i += size)
                sort(b + i, b + i + size);
            if(n - n / size * size != 0)
                sort(b + n / size * size, b + n / size * size + n - n / size * size);
        }
        show(b, n);
    }
    delete[]a;
    delete[]b;
    return 0;
}