#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001]; //i번째 원소 포함하는 부분수열의 최대길이
int n;
vector<int> input;

int main() {
    //input.push_back(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        input.push_back(tmp);
    }
    
    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        int max = 0;
        for (int j=1; j<i; j++) {
            if (input[i-1] > input[j-1] && max < dp[j]) {
                max = dp[j];
            }
            dp[i] = max + 1;
        }
    }
    
    sort(dp+1, dp+n+1);
    cout << dp[n] << endl;
    return 0;
}