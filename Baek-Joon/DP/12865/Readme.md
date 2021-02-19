# 평범한 배낭
https:www.acmicpc.net/problem/12865

## Solution
2차원 dp는 왜이렇게 생각하기 힘들까

### 점화식
- dp[i][W] = W의 제한으로, i번째 물건까지 고려할 때, 담을 수 있는 최대 value
- dp[i][W]
- if i번째 무게가 제한W 보다 크면 (i번째를 못넣을때는)
    - dp[i-1][W]. 같은 제한의 i-1번째까지 고려했을 때랑 value가 같다
- if i번째 무게가 제한W 보다 작으면 (i번째를 어떻게든 넣을 수 있으면)
    - dp[i-1][W-w[i]] + v[i]. i번째 물건 넣었을 때 value와
    - dp[i-1][W]. 그냥 i번째거 안넣었을 때 value 중 최대값  
[reference](https://gsmesie692.tistory.com/113)  
