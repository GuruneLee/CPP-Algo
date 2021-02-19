#include <iostream>
#include <vector>

using namespace std;

int dice[7] = {0,0,0,0,0,0,0};
int m[20][20];

int dx[] = {0,0,-1,1}; //동0 서1 북2 남3
int dy[] = {1,-1,0,0}; //동0 서1 북2 남3
int main() {
    int N,M;
    int x, y;
    int K;
    cin >> N >> M >> x >> y >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> m[i][j];
        }
    }

    int dir;
    do {
        cin >> dir;
        dir --; //인덱스에 맞게 조정
        //move
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; //장외
        x = nx;
        y = ny;

        //rotate
        if (dir == 0) { //동
            dice[0] = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = dice[0];
        } else if (dir == 1) { //서
            dice[0] = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = dice[0];
        } else if (dir == 2) { //북
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = dice[0];
        } else if (dir == 3) { //남
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = dice[0];
        }

        //update
        if (m[x][y] == 0) {
            m[x][y] = dice[6]; //0이면 카피
        } else {
            dice[6] = m[x][y]; //반대로 카피, 0으로 만들기
            m[x][y] = 0;
        }

        //display top
        cout << dice[1] << endl;
    } while(getc(stdin) == ' ');
    return 0;
}