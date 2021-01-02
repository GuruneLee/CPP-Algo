# 스타트와 링크
https://www.acmicpc.net/problem/14889

## Solution
두 팀으로 나누는 방식에 따라 문제 푸는 방식이 갈림  
나는 next_permutation함수를 구현해서 풀었음  

## Trouble Shooting
BufferedReader와 StringTokenizer를 이용해 입력을 받을때, StringTokenizer의 `hasMoreTokens`함수를 사용하지 않아서
런타임 에러가 발생한 것 같음. 근데 ㅅㅂ eclipse에서는 그냥 되든데;   