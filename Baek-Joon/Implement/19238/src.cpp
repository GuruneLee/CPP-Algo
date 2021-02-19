#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

class XY {
    public:
        int row;
        int col;
};

class PQ {
    public:
        int dist;
        XY xy;
        int id;
};

class Compare{
public:
    bool operator() (PQ a, PQ b){
        if (a.dist > b.dist)  return true;
        if (a.dist < b.dist)  return false;
        if (a.xy.row > b.xy.row)  return true;
        if (a.xy.row < b.xy.row)  return false;
        if (a.xy.col > b.xy.col)  return true;
        return false;
    }
};

int F,nf;
int m[21][21];
int N,M;    
XY texi;
map<int, XY> mp;

void bfs1( priority_queue<PQ, vector<PQ>, Compare>& p) {
    //texi를 기준으로 사람이 있는 곳 까지의 거리를 알아낼거임
    vector<vector<int>> dist(N+1, vector<int>(N+1, -1));
    queue<pair<int,int>> q;
    q.push({texi.row, texi.col});
    dist[texi.row][texi.col] = 0;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (m[cx][cy] < 0) {
            p.push(PQ{dist[cx][cy], XY{cx,cy}, m[cx][cy]});
        }

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx<1 || nx>N || ny<1 || ny>N) continue;
            if (m[nx][ny] == 1) continue;
            if (dist[nx][ny] == -1){
                q.push({nx,ny});
                dist[nx][ny] = dist[cx][cy] + 1;
            }
        }
    }

}

int main() {
    scanf("%d %d %d", &N, &M, &F);
    for (int i=1; i<N+1; i++) {
        for (int j=1; j<N+1; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    scanf("%d %d", &texi.row, &texi.col);
    
    for (int i=1; i<M+1; i++) {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        m[a][b] = -i;
        mp[-i] = XY{c,d};
    }

    while (!mp.empty()) {
        priority_queue<PQ, vector<PQ>, Compare> p;
        //사람이 있는 곳 까지 거리 구해서 p에 넣기
        bfs1(p);
        //nf,F업데이트

        //목적지가 남아있는데, 탈 사람이 없다 -> 못가요못가
        if (p.empty()) {
            cout << -1 << endl;
            return 0;
        }

        nf = p.top().dist;
        if (nf > F) { //못감
            cout << -1 << endl;
            return 0;
        }
        //갈 수 있음
        texi = XY{p.top().xy.row, p.top().xy.col};//택시위치 수정
        F = F-nf; //연료 줄어듦
        m[texi.row][texi.col] = 0; //택시가 태웠으니 사람 없음
        
        //목적지
        XY des = mp[p.top().id];
    
        //현재 택시에서 목적지까지 거리 구하기
        vector<vector<int>> dist(N+1, vector<int>(N+1, -1));
        queue<pair<int,int>> q;
        q.push({texi.row, texi.col});
        dist[texi.row][texi.col] = 0;
        int tmp = -1;
        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            //목적지를 찾았으면 ㅇㅇ
            if (des.row == cx && des.col == cy) {
                tmp = dist[cx][cy];
                break;
            }

            for (int i=0; i<4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx<1 || nx>N || ny<1 || ny>N) continue;
                if (m[nx][ny] == 1) continue;
                if (dist[nx][ny] == -1){
                    q.push({nx,ny});
                    dist[nx][ny] = dist[cx][cy] + 1;
                }
            }
        }
        
        if (tmp == -1) {
            //목적지를 못찾은거임
            cout << -1 << endl;
            return 0;
        }
        //갈 수 있으면 감
        nf = tmp;
        if (nf > F) {
            cout << -1 << endl;
            return 0;
        }
        texi = des; //택시이동
        F = F-nf; //연료쓴거
        F = F+nf+nf; //연료충전

        //mp에서 목적지 삭제
        mp.erase(p.top().id);
    }

    cout << F << endl;

    return 0;
}