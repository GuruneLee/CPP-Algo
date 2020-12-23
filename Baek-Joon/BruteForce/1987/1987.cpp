#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int R,C;
vector<string> map;
int vm[21][21];
vector<char> vc;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool inMap(int x, int y) {
    return (0<=x&&x<R) && (0<=y&&y<C);
}

int go(int cx, int cy, int curO) {
    for (int i=0; i<curO; i++) {
        if (vc[i] == map[cx][cy]) return 0;
    }

    int ans=0;
    int tmp = 0;
    for (int i=0; i<4; i++) {
        int nx = cx+dx[i];
        int ny = cy+dy[i];
        if (inMap(nx,ny) && vm[nx][ny] == 0) {
            vm[nx][ny] = 1;
            vc.push_back(map[nx][ny]);
            tmp = go(nx, ny, curO+1);
            vm[nx][ny] = 0;
            vc.pop_back();
        }
        if (ans < tmp+1)
            ans = tmp+1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        string tmp;
        cin >> tmp;
        map.push_back(tmp);
    }

    vm[0][0] = 1; //visited
    vc.push_back(map[0][0]);
    int ans = go(0,0,0);

    cout << ans << endl;
    return 0;
}
