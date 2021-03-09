#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n,l,r;

int m[51][51];
int visit[51][51];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void initVisit() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            visit[i][j] = -1;
        }
    }
}

void func (int i, int j, int un) {
    //bfs 시작
    vector<pair<int,int>> united;
    united.push_back({i,j});

    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] = un;

    int sum = m[i][j]; //연합국가 전체 인구수
    int cnt = 1; //연합국가 수

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for (int d=0; d<4; d++) {
            int nx = cx+dx[d];
            int ny = cy+dy[d];
            if (visit[nx][ny] != -1) continue;
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            
            int gap = abs(m[cx][cy] - m[nx][ny]);
            if (gap>=l && gap<=r) {
                sum += m[nx][ny];
                cnt ++;
                visit[nx][ny] = un;
                q.push({nx,ny});
                united.push_back({nx,ny});
            }
        }
    }

    //bfs 끝
    //map업데이트
    for (auto e : united) {
        m[e.first][e.second] = sum/cnt;
    }
    //cout<<1;
}

int main() {
    int answer = 0;

    cin >> n >> l >> r;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> m[i][j];
        }
    }

    while (true) {
        initVisit();
        int un = 0; //현재 연합 숫자

        //인구 대이동
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (visit[i][j] == -1) {
                    func(i,j,un);
                    un ++;
                }
            }
        }

        if (un == n*n) {
            break;
        }

        answer ++;
    }

    cout << answer;
    return 0;
}