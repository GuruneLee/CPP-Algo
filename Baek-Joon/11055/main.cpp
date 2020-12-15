#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int input[1001];

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        scanf("%d", input + i);
    }

    int max = 0;
    for (int i=1; i<=n; i++) {
        dp[i] = input[i];
        for (int j=1; j<i; j++) {
            if (input[j] < input[i] && dp[i] < dp[j] + input[i]) {
                dp[i] = dp[j] + input[i];
            }
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    cout<<max<<endl;

}