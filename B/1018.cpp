#include <iostream>
#include <cstring>
using namespace std;

struct player {
    int chui;
    int jian;
    int bu;
    int win;
    int loss;
    int draw;
} players[2];

int main() {
    int round;
    cin >> round;
    char p[2];
    int player_num = 2;
    memset(players, 0, sizeof(players));
    while(round--) {
        cin >> p[0] >> p[1];
        if(p[0] == p[1]) {
            ++players[0].draw;
            ++players[1].draw;
        }
        else {
            if(p[0] == 'C') {
                if(p[1] == 'J') {
                    ++players[0].win;
                    ++players[0].chui;
                    ++players[1].loss;
                }
                else {
                    ++players[0].loss;
                    ++players[1].win;
                    ++players[1].bu;
                }
            }
            else if(p[0] == 'J') {
                if(p[1] == 'B') {
                    ++players[0].win;
                    ++players[0].jian;
                    ++players[1].loss;
                }
                else {
                    ++players[0].loss;
                    ++players[1].win;
                    ++players[1].chui;
                }
            }
            else{
                if(p[1] == 'C') {
                    ++players[0].win;
                    ++players[0].bu;
                    ++players[1].loss;
                }
                else {
                    ++players[0].loss;
                    ++players[1].win;
                    ++players[1].jian;
                }
            }
        }
    }
    while(player_num--) {
        cout << players[1 - player_num].win << ' ' << players[1 - player_num].draw << ' ' << players[1 - player_num].loss << endl;
    }
    player_num = 2;
    while(player_num--) {
        char x = 'B';
        if(players[1 - player_num].bu >= players[1 - player_num].chui) {
            if(players[1 - player_num].bu >= players[1 - player_num].jian)
                x = 'B';
            else
                x = 'J';
        }
        else {
            if(players[1 - player_num].chui >= players[1 - player_num].jian)
                x = 'C';
            else
                x = 'J';
        }
        if(player_num != 1)
            cout << ' ';
        cout << x;
    }
    return 0;
}