#include <string>
#include <vector>
#define mod 1000000007
using namespace std;

int dp[60001];

int solution(int n) {
    int answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<n+1; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
    answer = dp[n];
    return answer;
}