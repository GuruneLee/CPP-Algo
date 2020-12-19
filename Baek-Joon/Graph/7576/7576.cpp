#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class D {
    public:
        int x,y;
        int day;
        D(int a, int b, int c) {
            x = a;
            y = b;
            day = c;
        }
};

bool inmap(int x, int y, int N, int M) {
    return (0<=x&&x<N) && (0<=y&&y<M);
}

int m[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool noZero(int N, int M) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (m[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}


int main () {
    int N, M;
    cin >> M >> N;
    
    queue<D> q;
    int Day = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &m[i][j]);
            if (m[i][j] == 1) {
                    q.push(D(i,j,0));
            }
        }
    }

    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cd = q.front().day;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nd = cd + 1;
            if (!inmap(nx,ny,N,M)) continue;
            if (m[nx][ny] == 0) {
                m[nx][ny] = 1;
                q.push(D(nx, ny, nd));
                if (nd > Day) {
                    Day += 1;
                }
            }
        }       
    }

    if (noZero(N, M)) {
        cout << Day << endl;
    } else {
        cout << -1 << endl;
    }
}