#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[33][33];

int MAX(int xu, int xd, int yl, int yr) {
    int re = -1;
    for (int i=xu; i<=xd; i++) {
        for (int j=yl; j<=yr; j++) {
            re = re<map[i][j]?map[i][j]:re;
        }
    }
    return re;
}

int split(int xu, int xd, int yl, int yr) {
    int re = -1;
    if (xu==xd && yl+1==yr) { //1x2
        //re = max(map[xu][yl], map[xu][yr]);
        re = MAX(xu,xd,yl,yr);
    } else if (xu+1==xd && yl==yr) { //2x1
        //re = max(map[xu][yl], map[xd][yl]);
        re = MAX(xu,xd,yl,yr);
    } else {

        //가로로 나누기 
        int tmpV=-1, tmpH=-1;
        if (xu != xd){
            int tmp1 = MAX(xu,(xd+xu)/2,yl,yr) + split((xd+xu)/2+1,xd,yl,yr);
            int tmp2 = split(xu,(xd+xu)/2,yl,yr) + MAX((xd+xu)/2+1,xd,yl,yr);
            tmpV = tmp1<tmp2?tmp2:tmp1;
        }
        //세로로 나누기
        if (yl != yr){
            int tmp1 = MAX(xu,xd,yl,(yl+yr)/2) + split(xu,xd,(yl+yr)/2+1,yr);
            int tmp2 = split(xu,xd,yl,(yl+yr)/2) + MAX(xu,xd,(yl+yr)/2+1,yr);
            tmpH = tmp1<tmp2?tmp2:tmp1;
        }
        re = tmpV<tmpH?tmpH:tmpV;
    }
    return re;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    cout << split(0,N-1,0,N-1);
    return 0;
}