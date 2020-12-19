#include <iostream>
#include <vector>

using namespace std;

#define mod 1000000000
int dp[201][201];

int main() {
    int N,K;
    cin >> N >> K;

    for (int i=0; i<=K; i++) {
        dp[i][0] = 1;
    }

    for (int k=1; k<=K; k++) {
        for (int n=1; n<=N; n++) {
            for (int l=0; l<=n; l++) {
                dp[k][n] += dp[k-1][n-l]%mod;
                dp[k][n] %= mod;
            }
        }
    }

    cout << dp[K][N]%mod << endl;

    return 0;
}