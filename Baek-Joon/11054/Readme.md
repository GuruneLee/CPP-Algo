# 가장 긴 바이토닉 부분수열
https://www.acmicpc.net/problem/11054

## Solution
| 수열의 최대값이 바이토닉수열의 최대값인가?
No. 반례 : 1 100 2 3 10 9 8 7 -> 1 2 3 10 9 8 7

| ans[i] : i번째 수를 바이토닉 수열의 최대값으로 하는 바이토닉 수열의 최대 길이 구하기(i : 1 ~ input.size())
-> input에 대해 
indp[i] : i번째 수 포함하는 최대 증가 부분수열 길이
dedp[i] : input.reverse에 대해, i번째 수 포함하는 최대 증가 부분수열의 길이
=> ans[i] = indp[i] + dedp[len-i-1] - 1
=> 시간복잡도 O(N^2) 