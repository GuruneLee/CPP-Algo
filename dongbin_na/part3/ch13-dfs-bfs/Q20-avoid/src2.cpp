//감시 피하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int N;
vector<vector<char>> map;
vector<pair<int,int>> T;
vector<pair<int,int>> S;
vector<pair<int,int>> O;
vector<pair<int,int>> X;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool isHidden(vector<vector<char>>& tm) {
    for (int i=0; i<T.size(); i++) {
        int cx = T[i].first;
        int cy = T[i].second;
        for (int d=0; d<4; d++) {
            int nx = cx;
            int ny = cy;
            while (true) {
                nx = nx + dx[d];
                ny = ny + dy[d];
                if (nx >= N || nx < 0 || ny >= N || ny < 0) break;
                if (tm[nx][ny] == 'O') break;
                if (tm[nx][ny] == 'S'){
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    string answer = "NO";

    cin >> N;
    map = vector<vector<char>>(N, vector<char>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp;
            if (tmp == 'T') T.push_back({i,j});
            if (tmp == 'S') S.push_back({i,j});
            if (tmp == 'X') X.push_back({i,j});
        }
    }

    vector<int> sel(X.size());
    sel[0] = 1;
    sel[1] = 1;
    sel[2] = 1;

    do {
        vector<vector<char>> tm(map);
        //돌 넣기
        for (int i=0; i<sel.size(); i++) {
            if (sel[i] == 1) {
                tm[X[i].first][X[i].second] = 'O';
            }
        }
        
        if (isHidden(tm)) {
            answer = "YES";
            break;
        }

    } while (prev_permutation(sel.begin(), sel.end()));
    

    cout << answer;
    return 0;
    
}

