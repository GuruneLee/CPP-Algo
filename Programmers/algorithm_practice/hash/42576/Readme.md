# 완주하지 못한 선수
https://programmers.co.kr/learn/courses/30/lessons/42576

## Solution (C++)
1. map -> Red-Black Tree를 이용하므로, 탐색 속도 = 시간복잡도 O(logn)
2. unoredered_map -> Hash Table을 이용해 키의 순서 유지 x, 탐색속도 최소 O(1)
~~~
//map선언 방법
map<string, int> m;
unordered_map<string, int> um;
~~~
3. 정렬 후 비교 - 정렬 후 같은  index에 다른 수가 있으면 그 선수가 통과하지 못한 선수임 O(nlogn)