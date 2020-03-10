#include <bits/stdc++.h>
using namespace std;

int a[10005];

// O(n^3)
void func1(int size) {
    int sum = -999999999, start = -1, end = -1;
    for(int i = 0; i < size; ++i) {
        int temp = 0;
        for(int j = i; j < size; ++j) {
            temp += a[j];
            if(temp > sum) {
                sum = temp;
                start = i;
                end = j;
            }
        }
    }
    printf("%d %d %d", sum, a[start], a[end]);
}

//O(n^2)
void func2(int size) {
    int sum = -999999999, start = -1, end = -1;
    for(int i = 0; i < size; ++i) {
        for(int j = i; j < size; ++j) {
            int temp = 0;
            for(int k = i; k <= j; ++k) temp += a[k];
            if(temp > sum) {
                sum = temp;
                start = i;
                end = j;
            }
        }
    }
    printf("%d %d %d", sum, a[start], a[end]);
}

//  O(nlogn)
int partition(int left, int right) {
    if(left == right) return (a[left] > 0 ? a[left] : 0);

    int center = (left + right) / 2,
//        find max sum in the left
        maxLeft = partition(left, center),
//        find max sum in the right
        maxRight = partition(center + 1, right);

//    find max sum in the middle
    int ls = 0, mls = 0;
    for(int i = center; i >=left; --i) {
        ls += a[i];
        mls = ls > mls ? ls : mls;
    }
    int rs = 0, mrs = 0;
    for(int i = center + 1; i <= right; ++i) {
        rs += a[i];
        mrs = rs > mrs ? rs : mrs;
    }
    return max(max(maxLeft, maxRight), mrs + mls);
}


// O(n) dp[i]=max{0, dp[i-1]+a[i]}, if i >= 1 and dp[0]=max{0, a[0]}
void dynamic_programming(int size) {
//    from Liu Ruo
//    int temp = 0, start = 0, end = size - 1, sum = -999999999, tempstart = 0;
//    for(int i = 0; i < size; ++i) {
//        temp += a[i];
//        if(temp < 0) {
//            temp = 0;
//            tempstart = i + 1;
//        }
//        else if(temp > sum) {
//            sum = temp;
//            start = tempstart;
//            end = i;
//        }
//    }
//    printf("%d %d %d", sum, a[start], a[end]);

//    maybe a little problem
//    vector<int> dp(size), start(size, -1);
//    int maxSum = -999999999, flag = -1;
//    if(a[0] >= 0) {
//        start[0] = 0;
//        dp[0] = a[0];
//    }
//    else dp[0] = 0;
//    for(int i = 1; i < size; ++i) {
//        if(dp[i - 1] + a[i] > 0) {
//            dp[i] = dp[i - 1] + a[i];
//            start[i] = dp[i - 1] == 0 ? i : start[i - 1];
//        }
//        else dp[i] = 0;
//        if(dp[i] > maxSum) {
//            maxSum = dp[i];
//            flag = i;
//        }
//    }
//    printf("%d %d %d", maxSum, a[start[flag]], a[flag]);

    vector<int> dp(size);
    int maxSum = -999999999, flag = 0;
    dp[0] = max(0, a[0]);
    for(int i = 1; i < size; ++i) {
        dp[i] = max(0, dp[i - 1] + a[i]);
        if(dp[i] > maxSum) {
            maxSum = dp[i];
            flag = i;
        }
    }
    int k = flag;
    while(maxSum != 0) {
        maxSum -= a[k--];
    }
    while(k >= 0 && a[k] == 0){
        k--;
    }
    printf("%d %d %d", dp[flag], a[k + 1], a[flag]);
}

int main() {
    int k, neg = 0;
    cin >> k;
    for(int i = 0; i < k; ++i) {
        cin >> a[i];
        if(a[i] < 0) neg++;
    }
    if(neg == k) printf("%d %d %d", 0, a[0], a[k - 1]);
    else if(k == 1) printf("%d %d %d", a[0], a[0], a[k - 1]);
    else {
//        func1(k);
//        func2(k);
//        cout << partition(0, k - 1);
        dynamic_programming(k);
    }
    return 0;
}