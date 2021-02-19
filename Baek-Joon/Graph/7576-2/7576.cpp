#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int m[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0,0,-1,1};
int main() {
    int N, M;
    cin >> M >> N;
    queue<pair<int,pair<int,int>>> q; //날짜, 좌표xy
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> m[i][j];
            if (m[i][j]==1) {
                q.push({0,{i,j}});
            }
        }
    }

    int day = 0;
    while(!q.empty()) {
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int cd = q.front().first;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nd = cd + 1;
            if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if (m[nx][ny] == 0) {
                q.push({nd,{nx,ny}});
                m[nx][ny] = 1;
                day = nd<day?day:nd;
            }
        }
    }

    bool flag = true;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (m[i][j]==0) {
                flag = false;
                break;
            }
        }
    }

    if (flag){
        cout << day << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

