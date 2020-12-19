#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>
using namespace std;

#define INF 987654321
vector<string> m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dist[101][101];

class DQ {
    public:
        int x,y; //map탐색용
        int d; //x,y의  cost
        DQ(int a, int b, int c) {
            x = a;
            y = b;
            d = c;
        }
};

class cmp
{
public:
	int operator()(DQ t, DQ u){
		return t.d > u.d;
	}
};

bool inmap(int a,int b,int c, int d){
    return (0<=a&&a<c) && (0<=b&&b<d);
}

int main() {
    int N,M;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string tmp;
        cin >> tmp;
        m.push_back(tmp);
        for (int j=0; j<M; j++) {
            dist[i][j] = INF;
        }
    }

    priority_queue<DQ, vector<DQ>, cmp> q;
    q.push(DQ(0,0,1));
    dist[0][0] = 1;

    while (!q.empty()) {
        int cx = q.top().x;
        int cy = q.top().y;
        int cd = q.top().d;
        q.pop();
        
        if (cd > dist[cx][cy]) continue;

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!inmap(nx,ny,N,M)) continue;
            if (m[nx][ny] == '1') {
                if (dist[nx][ny] > cd+1) {
                    dist[nx][ny] = cd+1;
                    q.push(DQ(nx,ny,cd+1));
                }
            }
        }

    }

    cout      << dist[N-1][M-1] << endl;
    
}