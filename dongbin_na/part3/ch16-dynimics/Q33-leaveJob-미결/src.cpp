#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int answer = 0;
void go(int sum, int n, int index){
  if(index==n){
    answer = sum>answer? sum:answer;
    return;
  }
  if(index > n){
    return;
  }
  go(sum+P[index], n, index+T[index]);
  go(sum, n, index+1);
}*/

int main() {
    int N;
    cin >> N;
    vector<int> T(N+1);
    vector<int> P(N+1);
    for (int i=1; i<N+1; i++) {
        cin >> T[i] >> P[i];
    }
    vector<int> dp(N+1); //dp[i] : i
    int MAX = 0;
    for (int i=N; i>0; i--) {
        int end_day = T[i] + i;
        if (end_day <= N) {
            dp[i] = max(P[i]+dp[end_day], MAX);
            MAX = dp[i];
        } else {
            dp[i] = MAX;
        }
    }

    cout << MAX ;
    return 0;
}