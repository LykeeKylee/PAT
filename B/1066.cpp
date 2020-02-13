#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int row, col, lower, upper, replace;
    cin >> row >> col >> lower >> upper >> replace;
    int **img = new int*[row];
    for(int i = 0; i < row; ++i) {
        img[i] = new int[col];
        for(int j = 0; j < col; ++j) {
            cin >> img[i][j];
            if(img[i][j] <= upper && img[i][j] >= lower)
                img[i][j] = replace;
        }
    }
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            if(j == 0)
                cout << setfill('0') << setw(3) << img[i][j];
            else if(j == col - 1){
                cout << ' ';
                cout << setfill('0') << setw(3) << img[i][j];
                cout << endl;
            }
            else{
                cout << ' ';
                cout << setfill('0') << setw(3) << img[i][j];
            }
        }
        delete[]img[i];
    }
    delete[]img;
    return 0;
}