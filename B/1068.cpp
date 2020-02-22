#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int eplison;
int row, col, **img;

bool judge(int a, int b, int c, int d) {
    return !(c >= 0 && c < row && d >= 0 && d < col && abs(img[a][b] - img[c][d]) <= eplison);
}

int main() {
    int cnt = 0, ii = 0, jj = 0;
    cin >> col >> row >> eplison;
    img = new int*[row];
    map<int, int> color;
    for(int i = 0; i < row; ++i) {
        img[i] = new int[col];
        for(int j = 0; j < col; ++j) {
            scanf("%d", *(img + i) + j);
            ++color[img[i][j]];
        }
    }

    for(int i = 0; i < row ; ++i) {
        for(int j = 0; j < col; ++j) {
            //todo:条件的判断不够仔细
            if(color[img[i][j]] == 1 && judge(i, j, i - 1, j - 1) && judge(i, j, i - 1, j) && judge(i, j, i - 1, j + 1) &&
            judge(i, j, i, j - 1) && judge(i, j, i, j + 1) && judge(i, j, i + 1, j - 1) && judge(i, j, i + 1, j)
            && judge(i, j, i + 1, j + 1)) {
                ++cnt;
                ii = i;
                jj = j;
            }
        }
    }

    if(cnt == 1) {
        printf("(%d, %d): %d", jj + 1, ii + 1, img[ii][jj]);
    }
    else if(cnt == 0)
        printf("%s", "Not Exist");
    else if(cnt > 1)
        printf("%s", "Not Unique");

    for(int i = 0; i < row; ++i) {
        delete[]img[i];
    }
    delete[]img;
    return 0;
}