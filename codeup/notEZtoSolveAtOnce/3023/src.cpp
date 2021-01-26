#include <iostream>
#include <string>
using namespace std;

int dp[10001] = {-1,0,0,1,0,0,1,0,0,1,};

int main() {
    long long a;
    long long b;
    cin >> a >> b;

    int cnt = 0;
    for (long long i=10; i<=b; i++) {
        dp[i] = dp[i/10] + dp[i%10];
    }

    cout << dp[b]-dp[a-1] << endl;
    return 0;
}