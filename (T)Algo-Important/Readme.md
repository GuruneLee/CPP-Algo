# 중요한 개념들

## 가장 긴 증가하는 부분수열 찾기
1. O(n^2)  짜리 방법
- d[i] = i번째 원소를 마지막으로 하는 LIS의 길이
- d[i] = 1 ~ i-1까지의 원소 중, i번째 원소보다 값이 작은것들 중, 가장 큰 dp값 + 1

2. O(nlogn)짜리 방법  
- *lower bound : 정렬된 배열 arr에서 어떠한 값 val의 lower bound란, arr을 정렬된 상태로 유지하면서 val이 삽입될 수 있는 위치들 중 가장 작은 인덱스.
lower bound를 구하는 것은 O(logn)으로 구현 가능, C++엔 구현되어 있음

( http://ko.cppreference.com/w/cpp/algorithm/lower_bound )
~~~
std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
auto lower = std::lower_bound(data.begin(), data.end(), 4);
~~~

L[i]를 업데이트 하며 동작함
L[i] = 길이 i인 증가하는 부분 수열을 만들 수 있는 마지막 원소 중 가장 작은 값 -> L의 크기가 '현재까지 만들 수 있는 LIS의 길이'가 됨

(업데이트)
1. L이 비었거나, 현재 L의 마지막 원소보다 here이 클 경우  
    -> L의 뒤에 here추가
2. else  
    -> L배열에서 here의 lower bound를 찾아서, 그 자리를 here로 바꿈

~~~cpp

~~~