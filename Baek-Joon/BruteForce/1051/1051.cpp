#include <iostream>
#include <string>

using namespace std;

string map[51];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> map[i];
    }

    int sl = M > N ? N:M;
    for (int i=sl; i>0; i--) {
        //길이가 i인 정사각형 중 조건에 맞는 하나 고르기
        for (int x=0; x<N-i+1; x++) {
            for (int y=0; y<M-i+1; y++) {
                if (map[x][y] == map[x+i-1][y+i-1] && map[x][y] == map[x+i-1][y] && map[x][y] == map[x][y+i-1]) {
                    cout << i*i << endl;
                    exit(0);
                }
            }
        }
    }

    return 0;
}