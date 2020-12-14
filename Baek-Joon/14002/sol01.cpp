#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][2]; //i번째 원소 포함하는 부분수열의 최대길이
int n;
vector<int> input = {-1,};
vector<int> an;
void go(int ni) {
    if (ni == -1) {
        return;
    }
    go(dp[ni][1]);
    cout << input[ni] << " ";
}

int main() {
    //input.push_back(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        input.push_back(tmp);
    }
    
    dp[0][0] = -1;
    dp[0][1] = -1;
    dp[1][0] = 1;
    dp[1][1] = -1;

    int ans = dp[1][0];
    int ni = 1; //업데이트가 안 될수도 있음 ㅇㅇ

    for (int i=2; i<=n; i++) {
        dp[i][0] = 1; // 초기화를 안하면 
        dp[i][1] = -1;
        for (int j=1; j<i; j++) {
            if (input[i] > input[j] && dp[i][0] < dp[j][0] + 1) {
                dp[i][0] = dp[j][0] + 1;
                dp[i][1] = j;
            }
        }

        if (ans < dp[i][0]) {
            ans = dp[i][0];
            ni = i;
        }
    }
    
    
    cout << ans << endl;
    go(ni);
    
    return 0;
}