# 코테 노트

# C++
## C++ STL Container
- 일단 머릿속에 다 있으므로, 향후 정리할 것
- 1)라이브러리 2)선언 3)초기화 4)함수 5)시간복잡도 6)사용하는알고리즘
### vector
### pair
### stack
### queue
### priority_queue
### set
### map
### unordered_map
### dequeue
### list

## C++ STL Algorithm
### sort
- sort (첫 주소, 마지막주소+1, 비교함수)
#### 비교 함수
- 기본 비교함수 - greater<>() : 내림차순 / less<>() : 오름차순
    ~~~cpp
    sort(arr, arr+arr_size, greater<>());
    sort(arr, arr+arr_size, less<>());
    ~~~
- custom함수  
    ~~~cpp
    bool compare(int i, int j) { 
        //sort의 대상 원소가, 비교함수의 인자로 오게 된다
        return j<i;
    }

    sort (_, _, compare);
    ~~~
#### 연산자 오버로딩 (클래스를 이용한 비교)
- value와 name을 갖는 A-class에서, value를 기준으로 나열하고 싶을 때,
    ~~~cpp
    class A {
        public:
            int value;
            string name;

            //operator '<' overloading
            //A-class에 대해서만 '<'가 다르게 작용한다
            bool operator < (A &a) {
                return this->x < a.x; //오름차순
            }
    }
    ~~~
#### pair를 이용한 다중 비교
- pair를 이용하면 **첫번째 인자가 같을 때, 두 번째 인자를 기준으로 정렬함**


### lower_bound
원하는 값이 있는 [가장 작은 pos]를 찾는 함수
~~~cpp
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';

  return 0;
}
~~~
#### my_lower_bound
- **lower_bound**: target이상의 값이 처음 나오는 위치를 찾는 것
~~~cpp
int myLowerBound(int arr[], int target, int size) {
    int start = 0; 
    int end = size-1;
    while (start < end) {
        mid = (start+end)/2;
        //중간값이 원하는 값보다 크거나 같을 경우, 끝값을 중간값으로 함
        //같은 값을 찾았을 경우엔 end만 슬금슬금 start쪽으로 오는거임
        if (arr[mid] >= target) {
            end = mid;
        //중간값이 원하는 값 보다 작거나 같을 경우, 시작값을 mid+1로 설정
        } else {
            start = mid+1;
        }
    }
}
~~~

### upper_bound
원하는 값이 있는 [가장 큰 pos+1]을 찾는 함수
~~~cpp
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator up;
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
~~~
#### my_upper_bound
- **upper_bound**: target을 초과한 값이 처음 나오는 위치를 찾는 것
~~~cpp
int myUpperBound(int arr[], int target, int size) {
    int start = 0; 
    int end = size-1;
    while (start < end) {
        mid = (start+end)/2;
        //중간값이 원하는 값보다 클 경우, 끝값을 중간값으로 함
        if (arr[mid] > target) {
            end = mid;
        //중간값이 원하는 값 보다 작거나 같을 경우, 시작값을 mid+1로 설정
        //같은값을 찾았을 경우엔 end는 고정이고, start만 슬금슬금 앞으로 오는거임
        } else {
            start = mid+1;
        }
    }
}
~~~

### binary_search   
- #include \<algorithm\>
- bool binary_search(start, end, value);
- 있는지 없는지만 알려줌 ㅋ
~~~cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[10] = {17, 25, 67, 84, 90, 30, 55, 6, 9, 28};
    sort(a, a + 10);
    cout << "값 55: ";

    if(binary_search(a, a+10, 55)) cout << "찾았습니다." << endl;
    else cout << "찾지 못했습니다." << endl;

    cout << "값 80: ";
    if(binary_search(a, a+10, 80)) cout << "찾았습니다." << endl;
    else cout << "찾지 못했습니다." << endl;
    return 0;
}
~~~


## C++ STD String
- string의 마지막 문자는 null
- string.size()의 경우, null앞까지의 개수를 새줌
### ASCII
- 값을 몰라도 되지만, 혹시 모르니깐
    - 'a'\~'z': 97\~122
    - 'A'\~'Z': 65\~90
    - '0'\~'9': 48\~57
### isdigit, isalpha
- #include \<cctype\>
- bool isdigit(int c)
: c가 '0'~'9'면 true, 아니면 false
### toupper, tolower
- #include \<cctype\>
- int toupper(int c)
    - 소문자만 대문자로 변경해줌. 다른 문자는 그대로 반환
- int tolower(int c)
    - 대문자만 소문자로 변경해줌. 다른 문자는 그대로 반환


### split
- 내장 함수가 없어 직접 구현함
~~~cpp
#include <vector>
#include <sstream>

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
~~~
### append
1. **문자열.append(추가할문자열);**               
: 추가할 문자열을 맨 끝에 추가함.
2. **문자열.append(추가할문자열, 시작위치, 개수);** 
: 추가할 문자열의 시작 위치부터 개수만큼만 맨 끝에 추가함.
3. **문자열.append(개수, 추가할문자);**             
: 추가할 문자를 개수만큼 맨 끝에 추가함
### find
1. **문자열.find(찾을문자열);**           
: 인덱스 0부터 찾을 문자열을 찾아, 그 시작 위치를 반환함.
2. **문자열.find(찾을문자);**             
: 인덱스 0부터 찾을 문자를 찾아, 그 시작 위치를 반환함.
3. **문자열.find(찾을문자열, 시작위치);** 
: 시작 위치부터 찾을 문자열을 찾아, 그 시작 위치를 반환함.
4. **찾지 못할 시, `string::npos`를 반환** 
### compare
1. **str1.compare(str_02) == 0** 
: str1과 str2이 같을 경우
2. **str1.compare(str_02) < 0**  
: str1이 str2보다 사전 편찬순으로 앞에 있을 경우
3. **str1.compare(str_02) > 0**  
: str1이 str2보다 사전 편찬순으로 뒤에 있을 경우
### replace
**문자열.replace(대체할문자열의시작위치, 대체할문자열의길이, 새로운문자열);**   
: 전달된 시작 위치부터 문자열의 길이만큼을 제거한 후에, 새로운 문자열을 삽입함
### substr
1. s.substr(int pos);
: pos부터 끝 까지 string으로 반환
2. s.substr(int pos, int count);
: [pos, pos+count) string으로 반환
### string<->num
1. string to_string(int val);
2. int stoi(string& s)
3. long long stoll(string& s)
4. flout stof(string& s)
### reverse
- 이건 \<algorithm\>에 있는 함수
- string뿐 아니라 대부분의 container에도 쓸 수 있음  
**std::reverse(BidirectionalIterator first, BidirectionalIterator last);**
~~~
string str = "abcd"
reverse(str.begin(), str.end());
~~~

# 알고리즘 Categories
## BF (Brute Force)
## Greedy
## Implementation
## DFS/BFS
### DFS - 깊이우선, stack
- 동작 방식
    1. 탐색 시작 노드를 스택에 삽입하고 방문처리
    2. 스택의 최상단 노드에 방문하지 않은 인접노드 있으면 해당 노드를 스택에 넣고 방문처리, 그렇지 않다면 스택에서 최상단 노드를 삭제
    3. `2`번의 과정을 반복
- **재귀함수**로 구현 (cpp)
    ~~~cpp
    // 연결 리스트
    void dfs(Node v, Graph g) {
        visit[v] = true;
        cout << v;
        for (auto n : g[v]) {
            if (!visit[v]) {
                dfs(n, g);
            }
        }
    }
    ~~~
- **스택**으로 구현 (cpp)
    ~~~cpp
    // 연결 리스트
    void dfs(Node v, Graph g) {
        stack s;
        s.push(v);
        cout << v;
        visit[v] = true;
        while (!s.isEmpty()) {
            int c_node = s.top();
            s.pop();
            for (int i=0; i<g[v].size(); i++) {
                int n_node = g[v][i];
                if (!visit[n_node]) {
                    cout << n_node;
                    visit[n_node] = true;
                    s.push(c_node);
                    s.push(n_node);
                }
            }
        }
    }
    ~~~
### BFS - 너비우선, queue
- 동작 방식
    1. 탐색 시작 노드를 큐에 삽입, 방문 처리
    2. 큐에서 노드를 꺼내, 해당 노드의 인접 노드 중 방문하지 않는 노드를 모두 큐에 삽입하고 방문처리
    3. `2`를 더 이상 수행할 수 없을 때까지 반복
- **큐**로 구현 (cpp)
    ~~~cpp
    // 연결 리스트
    void dfs(Node v, Graph g) {
        queue q;
        q.push(v);
        cout << v;
        visit[v] = true;
        while (!q.isEmpty()) {
            int c_node = q.front();
            s.pop();
            for (int i=0; i<g[v].size(); i++) {
                int n_node = g[v][i];
                if (!visit[n_node]) {
                    cout << n_node;
                    visit[n_node] = true;
                    q.push(v);
                }
            }
        }
    }
    ~~~
## Sort
### 선택 정렬 
정렬이 안 된 숫자 중, 가장 작은 숫자를 선택해 앞으로 보내는 방식
- source code
    ~~~cpp
    // 오름차순
    for (int i=0; i<arr.size(); i++) {
        int min_index = i; //0부터 i-1까지는 다 정렬이 되어 있는 상태
                            //최소값은 index 'i'부터 찾아가면 된다
        for (int j=i+1; j<arr.size(); j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
            swap(arr[min_index], arr[j]);
        }
    }
    ~~~
- 시간 복잡도
    O(n*n)

### 삽입 정렬
정렬이 안 된 숫자중 하나를, 정렬이 된 숫자에 삽입하는 방식
- source code
    ~~~cpp
        // 오름차순
    for (int i=0; i<arr.size(); i++) {
            for (int j=i; j>0; j--) {
                if (arr[j] < arr[j-1]) {
                    swap(arr[j], arr[j-1]);
                }else{
                    break;
                }
            }
        }
    ~~~
- 시간 복잡도
    O(n*n)  
    대신, 기존 정렬 상태에 따라서 선택 정렬보다 빠르게 동작한다  

### 퀵 정렬
- 분할정복
- 기준 데이터를 설정하고, 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾼다
- source code
    ~~~cpp
    void quick_sort (int start, int end) {
        if (start >= end) { //원소가 한 개 인 경우
            return;
        }
        int pivot = start; //피벗을 첫 번째 원소로 함
        left = start + 1;
        right = end;
        
        while (left <= right) {
            //피벗보다 큰 값 찾기
            while (left <= end && arr[left] <= arr[pivot]) {
                left += 1;
            }
            //피벗보다 작은 값 찾기
            while (right > start && arr[right] >= arr[pivot]) {
                right -= 1;
            }
            if (left > right) { //엇갈렸으면, 피벗과 작은 값 swap
                swap(arr[right], arr[pivot]); 
            } else {
                swap(arr[right], arr[left]); 
            }
        }
        // 피벗에 대해 분류를 끝낸 다음, 재귀함수로 왼쪽, 오른쪽 분류 시작
        // 마지막에 right자리에 있던게 pivot임 ㅇㅇ
        quick_sort(start, right-1);
        quick_sort(right+1, end);
    }
    ~~~
- 시간 복잡도
    O(nlogn)

### 계수 정렬
(특정 조건에 부합할 대만 사용할 수 있지만, 조건만 맞으면 굉장히 빠른 알고리즘)  
최소부터 최대까지 그 사이의 모든 수가 등장한 개수를 세고, 순차적으로 출력하면 됨
- 조건
    모든 데이터가 양의 정수, 데이터의 최대값과 최소값의 크기 차이가 많이 나지 않을때
- 시간 복잡도
    O(n + k) //k는 데이터의 최대 값
- source code

## Search
### Binary Search
- 배열 내부의 데이터가 정렬되어 있어야만 사용할 수 있는 알고리즘.  
    탐색 범위를 절반씩 좁혀가며 데이터를 탐색한다.  
  
- 탐색과정에서 '시작점' '끝점' '중간점' 세 변수를 사용하는데,
**찾으려는 데이터**와 **중간점**위치의 데이터를 반복적으로 비교하는것이 주 과정이다.  
0. 오름차순 정렬
1. 중간점 = (시작점 + 끝점)/2
2. 중간점과 찾으려는 데이터 비교
    if 중간점 < 찾으려는 데이터, 시작점 = 중간점+1  
    if 중간점 > 찾으려는 데이터, 끝점 = 중간점-1
3. 중간점 == 찾으려는 데이터 일 때 까지 `1`,`2` 반복
- 시간복잡도
    - O(logn)
#### 구현
1. 재귀함수
    ~~~cpp
    //Recursive
    //해당 index 반환 or -1반환
    int binary_search(int start, int end) {
        if (start > end) { //start랑 end가 엇갈리면 없는거임
            return -1;
        }
        int mid = (start+end)/2;
        if (arr[mid] < target) {
            return binary_search(mid+1, end);
        }
        if (arr[mid] > target) {
            return binary_search(start, mid-1);
        }
        return mid;
    }
    ~~~
2. 반복문
    ~~~cpp
    //Iterative
    //index반환
    int binary_search () {
        while (start <= end) {
            mid = (start + end) / 2;
            if (arr[mid] == target) {
                return mid;
            }
            if (arr[mid] < target) {
                start = mid + 1;
            }
            if (arr[mid] > target) {
                end = mid - 1;
            }
        }
        return -1;
    }
    ~~~


#### 트리 자료구조
데이터베이스 시스템, 파일 시스템 등에서 대용량 데이터를 보관할때 주로 사용되는 구조  
- 특징
    - 트리는 부모노드와 자식노드의 관계로 표현된다
    - 최상단 노드를 루트 노드라고 한다
    - 최하단 노드를 단말 노드라고 한다
    - 트리에서 일부를 떼어내도 트리이며, 이를 서브 트리라고 한다
    - 트리는 파일 시스템과 같이 **계층적이고 정렬된 데이터**를 다루기 적합하다
#### 이진 탐색 트리
이진 탐색이 동작할 수 있도록 고안된 트리 자료 구조.  
- 특징
    - 부모노드보다 왼쪽 자식노드가 작다
    - 부모노드보다 오른쪽 자식 노드가 크다
- 이진 탐색 트리에서 데이터를 조회하는 과정
    1. 루트노드와 target을 비교
        - 루트노드 < target 이면, 오른쪽 자식 노드 방문
        - 루트노드 > target 이면, 왼쪽 자식 노드 방문
        - 루트노드 == target이면, 탐색을 마침
    2. 방문한 노드를 루트 노드로 하는 서브트리에서 `1`반복



## DP (Dynamic Programming)
: 큰 문제를 작게 나누고, 같은 문제라면 한 번씩만 푸는 방식
- 분할정복 문제(ex. 퀵 정렬)와 차이점
    : 다이나믹 프로그래밍은 문제들이 서로 영향을 미침
### 탑 다운 (Top Down)
- 메모제이션 (Memozation)
- 한 번 구한 결과를 메모리 공간에 메모해두고, 같은 식을 다시 호출하면 메모한 결과를 그대로 가져오는 방식
    ~~~cpp
    //피보나치
    int fibo(int x) {
        if (x==1 or x==2) {
            return 1;
        }
        if (dp[x] != 0) {
            return dp[x];
        }
        dp[x] = fibo(x-1) + fibo(x-2);
        return dp[x];
    }
    ~~~
### 바텀 업 (Bottom Up)
- DP테이블
- DP테이블을 순차적으로 채워나가는 방식
    ~~~cpp
    //피보나치
    dp[1] = 1;
    dp[2] = 1;
    for (int i=3; i<n+1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    ~~~



## Shortest Path
### 종류
- 다익스트라 최단 경로 알고리즘
- 플로이드 워셜 
- 벨만 포드

### 문제 상황
- 한 지점에서 다른 특정 지점까지 최단 경로 -> 다익스트라
- 모든 지점에서 다른 모든 지점까지 최단 경로 -> 플로이드 워셜

### 다익스트라 최단 경로 알고리즘 (Dijkstra)
: 한 지점에서 다른 특정 지점까지의 최단경로
- 간선이 모두 0이상
- **그리디**
- 1차원 배열
- 기본 프로세스
    1. 출발노드 설정
    2. '최단 거리 테이블' 초기화
    3. 방문하지 않은 노드 중, 최단 거리가 가장 짧은 노드 선택
    4. 해당 노드를 거쳐갈을 시, 다른 노드로 가는 비용 계산. '최단 거리 테이블' 갱신
    5. `3` `4` 반복
- heap을 이용한 프로세스 (priority_queue)
    1. 출발노드와 비용을 pq에 삽입
    2. visit배열 초기화 (출발노드=0, 나머지=INF)
    3. pq.top의 원소(cv, ccost)에 연결된 노드를 순회
        1. e = 지나온 간선 비용
        2. ncost = min(visit[nv], ccost+e)
        3. not visit이면 방문 후 visit업데이트, pq에 push (노드, ncost)
    4. pq가 빌 때까지 `2`,`3`반복
- 시간복잡도
    heap을 이용하면 O(ElogV)

### 플로이드 워셜 알고리즘 (Floyd-Warshall)
: 모든 지점에서 다른 모든 지점까지의 최단경로
- **DP**
- 2차원 배열
- 다익스트라와 비슷하게 '거쳐가는 노드'를 기준으로 알고리즘 수행
- But, 매번 최단 거리를 갖는 노드를 찾을 필요 없음

- 시간 복잡도
    노드 개수가 N개일 때, N번의 단계를 수행하며  
    단계마다 O(N*N)의 연산을 통해 현재 노드를 거쳐가는 모든 경로를 고려함  
    -> O(N^3)  

- 프로세스
     : 현재 방문 중인 노드를 제외한 N-1개의 노드 중, 서로 다른 노드 (A,B)쌍을 선택하여, 이후에 [A -> 방문중인 노드 -> B]의 비용을 확인해서, 최단 거리를 갱신함  
     - 점화식: **`D(a,b) = min(D(a,b), D(a,k)+D(k,b))`**

- source code (cpp)
    ~~~cpp
    //Floyd-Warshall
    #define INF 987654321

    int v; //노드 개수
    int e; //간선 개수
    int dp[n+1][n+1] = INF; //인접 행렬꼴의 dp테이블 초기화

    //대각성분 0으로 초기화
    for (int i=1; i<n+1; i++) {
        dp[i][i] = 0;
    }

    //노드와 간선 정보 받아서 dp초기화
    while(m--) {
        cin >> tmpV1 >> tmpV2; //노드 정보
        cin >> tmpE; //해당 노드 사이의 간선 정보
        dp[tmpV1][tmpV2] = tmpE;
    }

    //점화식에 따라 Floyd-Warshall알고리즘 수행
    for (int i=1; i<n+1; i++) { //i번째 노드 방문
        for (int a=1; a<n+1; a++) { 
            for (int b=1; b<n+1; b++) { 
                //a,b 쌍에 대한 점화식
                dp[a][b] = min(dp[a][b], dp[a][i]+dp[i][b]);
            } 
        }
    }
    ~~~



## Graph Theory
### 서로소 집합 자료구조
: 서로소 부분 집합들로 나누어진 원소들의 데이터 처리를 위한 자료구조
- 필요성
1. 사이클 존재 여부 판별
2. 신장트리 만들기 (크루스칼 알고리즘)
3. 위상 정렬 알고리즘 (방향그래프의 모든 노드를 방향성에 거스르지 않도록 순서대로 나열하는 것)
- **union-find자료구조** 라고도 불림
    - Tree자료구조
    - union: 두 개의 원소가 포함된 집합을 하나로 합치기
    - find: 특정 원소를 포함하는 집합 찾기
#### 부모 테이블
- 집합 = 루트노드가 같은 놈들의 모임
- 부모테이블 = union-find자료구조에서 각 원소의 부모를 표기한 표
- 루트노드 = 부모의 부모의 부모의 부모의 부모의 부모의... 내가 나의 부모라고 표기된놈
#### find
~~~cpp
//특정 원소가 속한 집합 찾기 (find)
//경로 압축을 통해 특정 원소가 속한 집합 찾기 (find)
int find_parent(int x) {
    if (parent[x] != x) {
        //부모노드가 루트노드가 아니라면, 루트노드를 찾을 때까지 재귀적 호출
        //찾으면 바로바로 갱신해벌이기
        parent[x] = find_parent(parent[x]); 
    }
    return parent[x];
}
~~~

#### union
~~~cpp
//두 원소가 속한 집합을 합치기 (union)
void uion_parent(int a, int b) {
    int A = find_parent(a);
    int B = find_parent(b);
    if (A<B) {
        parent[b] = A;
    } else {
        parent[a] = B;
    }
}
~~~

### 사이클 판별
- undirected그래프에서 사이클 판별을 위해 사용가능
- directed에서는 DFS를 이용해야함 (다음 기회에)
- 프로세스
    : 그래프의 각 간선을 확인하며, 두 노드의 루트노드가 다르다면 union연산을 수행 (부모테이블 갱신) / 만약 루트 노드가 같다면 사이클(cycle)이 발생한 것  
    -> 그래프의 모든 간선에 대하여 반복
- source code
    ~~~cpp
    // 노드와 간선의 개수
    int V,E;
    // 부모테이블 초기화 (부모 = 자기자신)
    int parent[] = {1,2,3,...,V};
    
    //판별 함수
    bool isCycle(int[] parent) {
        // 그래프의 간선 a,b
        for (int i=0; i<E; i++) {
            int a = i;
            for (auto e : graph[a]) {
                int b = e;
                //a,b의 루트 노드가 같으면 cycle이 존재하는 것
                if (find_parent(a) == find_parent(b)) {
                    return true;
                //같지 않다면 union연산 수행
                } else {
                    union_parent(a,b);
                }
            } 
        }
        return false;
    }
    ~~~

### 크루스칼 알고리즘 (Kruskal Algorithm)  
**최소 신장 트리(minimum spanning tree)**를 만드는 방법.
- 시간 복잡도
    - O(ElogE)
- 프로세스
    1. 간선 데이터를 비용에 따라 오름차순으로 정렬
    2. 간선을 하나씩 확인하며 현재의 간선이 사이클을 발생시키는지 확인
        - 사이클 발생 -> 신장 트리에 포함시키지 않음
        - 사이클 발생x -> 신장 트리에 포함시킴
    3. 모든 간선에 대해 `2`를 반복
- source code
    ~~~cpp
    // 노드와 간선의 개수
    int V,E;
    vector<int cost, int a, int b> edges;//cost로 오름차순 정렬된 간선 리스트
    // 부모테이블 초기화 (부모 = 자기자신)
    int parent[] = {1,2,3,...,V};
    
    // 신장 트리의 최소 비용을 반환하는 함수
    // parent를 따라가면 신장트리도 출력 가능
    int min_spanning(int[] parent) {
        for (int i=0; i<E; i++) {
            // 그래프의 간선 a,b
            int a = edges[i].a;
            int b = edges[i].b;
            int cost = edges[i].cost;
            //cycle이 발생하지 않으면 집합에 포함시킴
            if (find_parent(a) != find_parent(b)) {
                union_parent(a,b);
                result += cost;
        }
        return false;
    }
    ~~~

### 위상정렬 (Topology Sort)
: 방향그래프의 모든 노드를 '방향성에 거스르지 않도록 나열'하는 알고리즘  
ex. 선수과목을 고려한 학습 순서 결정
- 시간 복잡도  
    - O(V+E)
- 프로세스
    - 진입차수(indegree)테이블 사용
    1. 진입차수(indegree)가 0인 노드를 큐에 넣는다
    2. 큐가 빌 때까지 다음 과정을 반복한다
        1. 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거한다
        2. 새롭게 진입차수(indegree)가 0이 된 노드를 큐에 넣는다
    - 만약 모든 원소를 방문하기 전에 큐가 비면, 사이클이 존재하는 것
    - 답이 여러가지가 될 수 있음
- source code
    ~~~cpp
    // 노드와 간선의 개수
    int V,E;
    // 진입차수 테이블 초기화
    int indegree[V];
    while(E--) {
        //간선 정보 입력받음
        int a,b = input();
        graph[a].push_back(b);
        //진입차수 1증가
        indgree[b] += 1;
    }
    
    // result배열에 위상정렬 결과를 담는 함수
    vector<int> result;
    void min_spanning(int[] parent) {
        queue<int> q;
        //시작시 진입차수가 0인 노드 담기
        for (int i=1; i<=V; i++) {
            if (indgree[i] == 0)
                q.push(i);
        }

        //큐가 빌 때까지 반복
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);
            //current와 연결된 노드들의 진입차수 빼기
            for (auto e : graph[current]) {
                indgree[e] -= 1;
                if (indgree[e] == 0) {
                    q.push(e);
                }
            }
        }
    }
    ~~~

## 기타 중요 알고리즘
### 아라토스테네스의 체
- 소수 판별하기
1. 2부터 N까지의 모든 자연수를 나열한다
2. 남은 수 중에서 아직 처리하지 않은 가장 작은 수 i를 찾는다
3. 남은 수 중에서 i를 제외한 i의 배수를 제거한다
4. `2`, `3`을 반복한다
~~~cpp
bool isPrime[1000001];
int solution(int n) {
    int cnt = 0;
    
    for (int i=0; i<n+1; i++) {
        isPrime[i] = true; //다 소수라고 초기화하기
    }
    
    for (int i=2; i*i<n+1; i++) {
        if (isPrime[i]) {//제외되지 않은 가장 작은 수
            int j = 2; //i의 배수들을 모두 소수에서 제외하기
            while (i*j <= n) {
                isPrime[i*j] = false;
                j++;
            }
        }
    }

    for (int i=2; i<n+1; i++) {
        if (isPrime[i]) cnt++;
    }
    
    //개수 출력하기
    return cnt;
}
~~~

### LIS (Longest Increased Subsequence)
#### LIS길이 구하기
1. O(n^2)  짜리 방법
- **DP**
- dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
- dp[i] = 1 ~ i-1까지의 원소 중, i번째 원소보다 값이 작은것들 중, 가장 큰 dp값 + 1
~~~cpp
#include <iostream>
#include <algorithm>
using namespace std;

//arr에서 LIS의 길이 찾기
int arr[1001], dp[1001], len, N;

int main() {
    cin >> N;
    for (int i=1; i<N+1; i++) {
        cin >> arr[i];
        int tmp = 0;
        for (int j=1; j<i; j++) {
            //tmp
            //dp의 1 ~ i-1까지의 원소 중
            //i번째 원소보다 값이 작은것들 중, 가장 큰 값
            if (arr[i] > arr[j]) {
                tmp = max(tmp, dp[j]);
            }
        }
        //tmp + 1
        dp[i] = tmp + 1;
        len = max(len, dp[i]);
    }
    cout << len;
    return 0;
}
~~~

2. O(nlogn)짜리 방법  
- L[i]를 업데이트 하며 동작함
    - L[i] = 길이 i인 증가하는 부분 수열을 만들 수 있는 마지막 원소 중 가장 작은 값  
        -> L의 크기가 '현재까지 만들 수 있는 LIS의 길이'가 됨

- 업데이트 프로세스
1. L이 비었거나, 현재 L의 마지막 원소보다 here이 클 경우  
    -> L의 뒤에 here추가
2. else  
    -> L배열에서 here의 lower bound를 찾아서, 그 자리를 here로 바꿈

~~~cpp
#include <iostream>
#include <algorithm>
using namespace std;

//arr에서 LIS의 길이 찾기
//근데, arr는 필요가 없음
//값을 받아서 L을 바로 업데이트함
int L[1001], len, N;

int main() {
    cin >> N;
    for (int i=1; i<N+1; i++) {
        int here;
        cin >> here;
        auto pos = lower_bound(L+1, L+len+1, here);
        *pos = here; //if 찾음->pos자리에 here넣음
                     //if 못찾음(pos는 끝자리+1)->끝자리에 here넣음
        if (pos == L+len+1) { //끝자리에 붙인거면 len늘려주기
            len ++;
        }
    }
    cout << len;
    return 0;
}
~~~

#### LIS 원소 구하기
- P[i] = arr의 i번째 원소가 L의 뒤에서 가장 처음 위치하는 인덱스 저장 
- 단, L의 최종 결과물이 아닌 과정중에 가장 처음 위치하는 인덱스를 저장
    - 그럼 결국 최종 L의 값으로 저장된 P[i]만 원소찾기에 의미있는 값이 됨 ㅇㅇ
~~~cpp
#include <iostream>
#include <algorithm>
using namespace std;

//이번에는 arr를 저장해야댐
int arr[1001];
//값을 받아서 L을 바로 업데이트함
int L[1001], len, N;
//P배열 선언
int P[1001];

//P배열을 이용해 원소를 출력하는 함수
void backtrace(int idx, int num);

int main() {
    cin >> N;
    for (int i=1; i<N+1; i++) {
        int here;
        cin >> here;
        arr[i] = here;
        auto pos = lower_bound(L+1, L+len+1, here);
        *pos = here; //if 찾음->pos자리에 here넣음
                     //if 못찾음(pos는 끝자리+1)->끝자리에 here넣음
        P[i] = distance(L, pos);
        if (pos == L+len+1) { //끝자리에 붙인거면 len늘려주기
            len ++;
        }
    }
    cout << len;
    backtrace(N, len);
    return 0;
}

//L의 길이 len = LIS의 길이 = L의 index
void backtrace(int idx, int len){
    if (idx == 0) return;
    if (P[idx] == len) { //P의 오른쪽에서 가장 처음 len이 나타나는 곳 찾기
        backtrace(idx-1, len-1);
        cout << arr[idx] << ' ';
    } else {
        backtrace(idx-1, len);
    }
}
~~~



# Code Convention
## 끝이 정해지지 않은 입력 받기 (' '로 구분되어 있는 경우)
~~~cpp
//끝이 정해지지 않은 입력 받기
do {
    
    cin >> n;
    cout << n << endl;
    
} while (getc(stdin) == ' ');
~~~
- int getc ( FILE* stream )  
: 읽어들인 문자를 아스키코드값으로 리턴함