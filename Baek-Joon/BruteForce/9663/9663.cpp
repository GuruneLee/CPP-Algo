#include <iostream>
#include <cstring>
using namespace std;


int p[16] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //p[a]=b; a번째 row의 b번째 column에 말이있다~ 
int ans = 0;
int N;
int go(int x, int y) {
    for (int i=0; i<x; i++) {
        //cout << "a" << endl;
        if (p[i] == y) return 0;
        if (abs(i-x) == abs(p[i]-y)) return 0;
    }

    p[x] = y;

    if (x == N-1) {
        return 1;
    }

    int re = 0;
    for (int i=0; i<N; i++) {
        re += go(x+1, i);
    }

    return re;
}

int main() {
    cin >> N;
    int ans = 0;

    for (int i=0; i<N; i++) {
        ans += go(0,i);
    }
    
    cout << ans << endl;
}