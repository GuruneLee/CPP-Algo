#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,K;
int W[101];
int V[101];

//dp[i][W] = W의 제한으로, i번째 물건까지 고려할 때, 담을 수 있는 최대 value
//dp[i][W]
//if i번째 무게가 제한W 보다 크면 (i번째를 못넣을때는)
// - dp[i-1][W]. 같은 제한의 i-1번째까지 고려했을 때랑 value가 같다
//if i번째 무게가 제한W 보다 작으면 (i번째를 어떻게든 넣을 수 있으면)
// - dp[i-1][W-w[i]] + v[i]. i번째 물건 넣었을 때 value와
// - dp[i-1][W]. 그냥 i번째거 안넣었을 때 value 중 최대값
int dp[101][100001]; 




/*이렇게 하면 시간초과가 나요
int go(int sumW, int sumV, int i) {
    if (sumW > K) {
        return 0; //못써먹는 경우
    }
    if (i == N) {
        return sumV;
    }

    int t1 = go(sumW, sumV, i+1);
    int t2 = go(sumW+W[i], sumV+V[i], i+1);

    return t1>t2?t1:t2;
}
*/

int main() {
    cin >> N >> K;
    for (int i=1; i<N+1; i++) {
        cin >> W[i] >> V[i];
    }
    /*시간초과가 나요*/
    //cout << go(0,0,0);
    for (int i=1; i<N+1; i++) {
        for (int w=1; w<K+1; w++) {
            if (W[i] > w) {
                dp[i][w] = dp[i-1][w];
            } else {
                dp[i][w] = max(dp[i-1][w-W[i]]+V[i], dp[i-1][w]);
            }
        }
    }

    cout << dp[N][K];
    return 0;
}