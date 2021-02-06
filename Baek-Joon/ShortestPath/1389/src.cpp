//Floyd Warshall을 쓰자
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    //인접 행렬
    vector<vector<int>> am(N+1, vector<int>(N+1, INF));
    for (int i=1; i<N+1; i++) {
        am[i][i] = 0;
    }
    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        am[a][b] = 1;
        am[b][a] = 1;
    }

    for (int k=1; k<N+1; k++) {
        for (int a=1; a<N+1; a++) {
            for (int b=1; b<N+1; b++) {
                am[a][b] = min(am[a][b], am[a][k]+am[k][b]);
            }
        }
    }

    int minV = INF;
    int minI = 0;
    for (int i=1; i<N+1; i++) {
        int sum = 0;
        for (int j=1; j<N+1; j++) {
            sum += am[i][j];
        }
        if (minV > sum) {
            minV = sum;
            minI = i;
        }
    }
    
    cout << minI;

    return 0;
}