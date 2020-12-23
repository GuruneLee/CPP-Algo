# 스도쿠
https://www.acmicpc.net/problem/2580

## Solution
백트래킹..!  

## Trouble Shooting
1. isOK함수에서 3x3박스 내부 검사:  
**[(x/3)\*3, (x/3)\*3+3) X  [(y/3)\*3, (y/3)\*3+3)**  
가 x,y가 포함되어 있는 박스임  
2. 시간초과:  
isOK함수를 어떻게 만드느냐에 따라 시간초과 여부가 갈림  
처음에 sorting해서 하려다가 시간초과남...  
3. 백트래킹:  
map에 값을 집어넣은 다음, 백트래킹이 되면 다시 초기화 시켜줘야 함  
~~~
    map[p[0].first][p[0].second] = curV;
    go(curV, 0);   
    map[p[0].first][p[0].second] = 0;
~~~
그렇지 않으면, 값이 그대로 들어있게 되어서 비교가 제대로 안됨  

**백준 백트래킹 문제 모음집**
https://www.acmicpc.net/step/34  