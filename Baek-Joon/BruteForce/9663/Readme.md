# N-Queen
https://www.acmicpc.net/problem/9663

## Solution
### Back-tracking
: DFS랑 비슷, 그러나 DFS는 모든 노드를 방문하는 것을 목표로 하는 반면  
백 트래킹은 후보해가 될 수 없으면 다음단계로 진행하지 않고 되돌아 나옴  
-> 유망하지 않은 경우의 수를 줄이는 것을 목표로 함
**구현**  
: 경우의 수 가지치기로 Tree를 만들어서 DFS를 수행하는 도중, 후보해가 될 수 없다면 백 트래킹(Back-tracking) 수행한다.  
**기준함수**
기준함수: 현재까지 만들어진 벡터가 해의 기준을 만족하는지 판단하는 함수  
( 기준함수를 만족하면 Stack에 PUSH, 아니면 버림 )  
**reference**  
백 트래킹에 관한 기이이이잎은 고찰: https://it00.tistory.com/26  
간단한 고찰: https://heekim0719.tistory.com/284  
N-Queen 풀이 그림으로보자: https://idea-sketch.tistory.com/29  
**백준 백트래킹 문제 모음**  
https://www.acmicpc.net/step/34