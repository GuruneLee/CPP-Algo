#include <queue>
#include <iostream>
#include <utility>

using namespace std;

int v[1000001];

int main() {
    for (int i=0; i<1000001; i++) {
        v[i] = 987654321;
    }

    int N, K;
    int cnt = 0;
    int mt = 987654321;
    cin >> N >> K;

    queue<pair<int,int>> p;
    p.push({0,N});
    v[N] = 0;

    while (!p.empty()) {
        int ct = -p.front().first;
        int cp = p.front().second;
        p.pop();

        if (mt < ct) {
            continue;
        }

        if (cp == K) {
            cnt += 1;
            mt = ct;
        }

        int nt = ct+1;
        int np = 0;
        //+1
        np = cp + 1;
        if (nt <= mt && 0<=np && np<=1000000 && v[np]>=nt) {

            p.push({-nt, np});
            v[np] = nt;

        }
        //-1
        np = cp - 1;
        if (nt <= mt && 0<=np && np<=1000000 && v[np]>=nt) {

            p.push({-nt, np});
            v[np] = nt;
            
        }
        //*2
        np = cp * 2;
        if (nt <= mt && 0<=np && np<=1000000 && v[np]>=nt) {
        
            p.push({-nt, np});
            v[np] = nt;
        
        }
    }

    cout << v[K] << endl;
    cout << cnt << endl;

    return 0;
}