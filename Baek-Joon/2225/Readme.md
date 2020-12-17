# 합분해
https://www.acmicpc.net/problem/2225

## Solution
dp문제임 - 이거 답 본거니까, 다시 생각해봐 진짜루  
  
    
      
        
          
            
              
dp[N][K] : K개의 수를 써서, N을 만드는 경우의 수  
=> dp[N][K] = SUM(dp[N-i][K-1]) when i=0~N