//n퀸
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int cnt = 0;

bool isOK(int row, int put, vector<int>& dp) { //row,put에 넣을 수 있는가용
    for (int i=0; i<row; i++) {//i번째 row랑 비교해볼게요, dp[i]번째 칸에 말이 있어요
        //가로는 겹칠 일이 없어요
        //세로가 겹치려면 dp[i]와 put이 같아야돼요 그럼 아웃이에요
        if (dp[i] == put) return false;
        //대각선이 겹치려면 row,i의 차와 put,dp[i]의 차가 같아야돼요
        if (abs(row-i) == abs(put-dp[i])) return false;
    }
    return true;
}

void go(int row, vector<int>& dp) { //row번째 줄을 채울거임
    if (row == N) { //0~N-1을 모두 채운 후 이므로 패스패스
        cnt ++;
        return;
    }

    for (int i=0; i<N; i++) { //row번째 줄의 모든 칸을 탐색
        if (isOK(row, i, dp)){ //row번째 줄, i번째 칸에 넣을 수 있는가?
            //되면 넣어보고 다음 칸으로 가봅시다
            dp[row] = i;
            go(row+1, dp);
            //다시 빼고 다음 경우의 수를 봅시다
            dp[row] = -1;
        }
    }
}

int main() {
    cin >> N;
    vector<int> dp(N,-1);
    go(0, dp);

    cout << cnt ;
    return 0;
}