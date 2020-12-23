#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
int map[10][10];
vector<pair<int,int>> p;
bool mv[10][10];

void display() {
    //map 거시기 하기
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d ", map[i][j]);
        }
        cout << "\n";
    }
}

bool isOK(int x, int y, int v) {
    for (int i=0; i<9; i++) {
        if (i!=y && v == map[x][i]) return false;
        if (i!=x && v == map[i][y]) return false;
    }

    int lx = (x/3)*3;
    int ly = (y/3)*3;
    for (int i=lx; i<lx+3; i++) {
        for (int j=ly; j<ly+3; j++) {
            if (i==x && j==y) continue;
            if (v == map[i][j]) return false;
        }
    }

    return true;
}

void go(int curV, int curP) {
    //cout << curP << " ";
    int cx = p[curP].first;
    int cy = p[curP].second;

    if(!isOK(cx, cy, curV)) {
        return;
    }

    if (curP == p.size()-1) {
        display();
        exit(0);
    }

    for (int nV=1; nV<10; nV++) {
        map[p[curP+1].first][p[curP+1].second] = nV;
        go(nV, curP+1);
        map[p[curP+1].first][p[curP+1].second] = 0;
    }

}

int main(){
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            mv[i][j] = true;
            int tmp;
            scanf("%d", &tmp);
            map[i][j] = tmp;
            if (tmp == 0) {
                p.push_back({i,j});
                mv[i][j] = false;
            }
        }
    }

    for (int curV=1; curV<10; curV ++) {
        map[p[0].first][p[0].second] = curV;
        go(curV, 0);   
        map[p[0].first][p[0].second] = 0;
    }



    return 0;
}