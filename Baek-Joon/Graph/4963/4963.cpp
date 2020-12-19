#include <queue>
#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

int v[51][51];
int map[51][51];

int dx[8] = {-1,1,0,0,-1,1,-1,1};
int dy[8] = {0,0,-1,1,-1,-1,1,1};

bool inmap(int x, int y, int w, int h) {
    return (0<=x && x<h) && (0<=y && y<w);
}

int main() {

    int w,h;
    while(true) {
        memset(v, 0, sizeof(v));
        memset(map, -1, sizeof(map));

        cin >> w >> h;
        if (w==0 && h==0) break;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                int tmp;
                scanf("%d", &tmp);
                map[i][j] = tmp;
            }
        }
        queue<pair<int,int>> q;
        int cnt = 0;

        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (v[i][j] == -1) continue;
                if (map[i][j] == 0) continue;
                q.push({i,j});
                cnt ++;
                v[i][j] = -1;
                while(!q.empty()) {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    for (int di=0; di<8; di++) {
                        int nx = cx + dx[di];
                        int ny = cy + dy[di];
                        if (!inmap(nx, ny, w, h)) continue;
                        if (map[nx][ny]==1 && v[nx][ny] != -1) {
                            q.push({nx, ny});
                            v[nx][ny] = -1;
                        } 
                    }
                }

            }
        }

        cout << cnt << endl;
    }
}