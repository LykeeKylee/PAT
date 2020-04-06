#include <bits/stdc++.h>
using namespace std;
int maps[505][505], visit[505], distances[505], num[505], teams[505], weight[505];
const int inf = 999999999;

//use fill() to replace;
//void init() {
//    int i, j;
//    for(i = 0; i < 505; ++i) {
//        visit[i] = teams[i] = 0;
//        distances[i] = inf;
//        pre_city[i] = -1;
//        for(j = 0; j < 505; ++j) maps[i][j] = inf;
//    }
//}

int main() {
    int cities, roads, start, terminal, i, j, left;
    cin >> cities >> roads >> start >> terminal;
    left = cities;
//    init();
    fill(visit, visit + 505, 0);
    fill(teams, teams + 505, 0);
    fill(distances, distances + 505, inf);
    fill(num, num + 505, 1);
    fill(maps[0], maps[0] + 505 * 505, inf);
    for(i = 0; i < cities; ++i) cin >> weight[i];
    for(i = 0; i < roads; ++i) {
        int from, to, len;
        cin >> from >> to >> len;
        maps[to][from] = maps[from][to] = len;
    }

    //start city init
    distances[start] = 0;
    num[start] = 1;
    teams[start] += weight[start];
    while(--left > 0) {
        int cur = inf, curdst = inf;
        //select the city with minimum distance and it has not been visted
        for(i = 0; i < cities; ++i) {
            if(distances[i] < curdst && visit[i] == 0) {
                cur = i;
                curdst = distances[i];
            }
        }
        visit[cur] = 1;

        for(i = 0; i < cities; ++i) {
            if(visit[i] == 0 && maps[cur][i] != inf) {
                int to = i, w = maps[cur][i];
                if(curdst + w < distances[to]) {
                    distances[to] = curdst + w;
                    // Note that there may be more than one road to the current city!!!So all the roads need to be counted!
                    num[to] = num[cur];
                    teams[to] = teams[cur] + weight[to];
                }
                else if(curdst + w == distances[to]) {
                    num[to] += num[cur];
                    if(teams[cur] + weight[to] > teams[to])
                        teams[to] = teams[cur] + weight[to];
                }
            }
        }
    }
//    for(i = 0; i < cities; ++i) {
//        cout << distances[i] << ' ';
//    }
//    cout << endl;
    printf("%d %d", num[terminal], teams[terminal]);
    return 0;
}
