#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int input[1001];
int main() {
    int n;
    cin >> n;
    int max = 1;
    for (int i=0; i<n; i++) {
        dp[i] = 1;
        scanf("%d", input+i);
        for (int j=0; j<i; j++) {
            if (input[i] < input[j] && dp[i] < dp[j]+1) {
                dp[i] = dp[j] + 1;
                if (max < dp[i]) {
                    max = dp[i];
                }
            }
        }   
    }

    cout << max << endl;

    return 0;
}