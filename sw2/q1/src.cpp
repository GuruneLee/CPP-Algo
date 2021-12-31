#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M,N; //row, column
        cin >> M >> N;
        pair<int,int> g; //보물상자 - 2
        pair<int,int> e; //소마 - 3
        pair<int,int> k; //열쇠 - 4
        vector<vector<int>> map(M, vector<int>(N,0));
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                cin >> map[i][j];
                if (map[i][j] == 2) g={i,j};
                if (map[i][j] == 3) e={i,j};
                if (map[i][j] == 4) k={i,j};
            }
        }

        vector<vector<int>> visit(M, vector<int>(N,-1));
        queue<pair<int,int>> q;
        q.push(e);
        visit[e.first][e.second] = 1;

        //열쇠 찾기
        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if (k.first==cx && k.second==cy) { //열쇠 찾음
                e = k; //소마의 위치를 열쇠로 옮기기
                break;
            }

            for (int i=0; i<4; i++) {
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if (nx<0||nx>=M||ny<0||ny>=N) continue;
                if (map[nx][ny] != 1 && visit[nx][ny] == -1) {
                    q.push({nx,ny});
                    visit[nx][ny] = 1;
                }
            }
            
        }

        if (e != k) { //열쇠 못찾았으면 바로 다음 케이스로 ㄱㄱ
            cout << 0 << endl;
            continue;
        }

        //보물상자 찾기
        vector<vector<int>> visit2(M, vector<int>(N,-1));
        q.push(e);
        visit[e.first][e.second] = 1;

        //열쇠 찾기
        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if (g.first==cx && g.second==cy) { //상자 찾음
                e = g; //소마의 위치를 상자로 옮기기
                break;
            }

            for (int i=0; i<4; i++) {
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if (nx<0||nx>=M||ny<0||ny>=N) continue;
                if (map[nx][ny] != 1 && visit2[nx][ny] == -1) {
                    q.push({nx,ny});
                    visit2[nx][ny] = 1;
                }
            }
            
        }

        if (e != g) { //상자 못찾았으면 바로 다음 케이스로 ㄱㄱ
            cout << 0 << endl;
            continue;
        }

        cout << 1 << endl;

    }
    return 0;
}