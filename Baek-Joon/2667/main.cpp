#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

//global
string map[25];
vector<vector<int>> v;
int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
//main
int main() {
    scanf("%d", &N);
    int tmp = N;
    v.resize(N);
    for (int i=0; i<N; i++) {
        v[i].resize(N,-1);
        cin >> map[i];
    }

    queue<pair<int,int>> q;
    int cntg = 0; //단지 수
    vector<int> h; //단지 당 집 수

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!(map[i][j] == '1' && v[i][j] == -1)) continue;
            cntg += 1;
            q.push({i,j});
            v[i][j] = 0;
            int cnth = 1; //단지 내 집 수
            while (!q.empty()) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                for (int m=0; m<4; m++)  {
                    int nx = cx + dx[m];
                    int ny = cy + dy[m];
                    if (nx<0 || nx>N-1 || ny<0 || ny>N-1) continue;
                    if (v[nx][ny] == -1 && map[nx][ny] == '1') {
                        q.push({nx,ny});
                        v[nx][ny] = 0;
                        cnth += 1;
                    }
                }
            }
            h.push_back(cnth);
        }
    }

    cout << cntg << endl;
    sort(h.begin(), h.end());
    for (auto e : h) {
        cout << e << endl;
    }
    return 0;
}