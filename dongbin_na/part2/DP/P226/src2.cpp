#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main() {
    int n,m;
    cin >> n >> m;
    
    for (int i=0; i<m+1; i++) {
        dp[i] = 987654321;
    }

    vector<int> coin;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        coin.push_back(tmp);
        dp[tmp] = 1;
    }

    for (int i=1; i<m+1; i++) {
        for (auto c : coin) {
            if (i > c) {
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }

    if (dp[m] == 987654321) {
        dp[m] = -1;
    }
    cout << dp[m];
    

    return 0;
}