# include <algorithm>

## sort
### sort (첫 주소, 마지막주소+1, 비교함수)
- 비교 함수
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
- 연산자 오버로딩 (클래스를 이용한 비교)
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
- pair를 이용한 다중 비교
    - pair를 이용하면 **첫번째 인자가 같을 때, 두 번째 인자를 기준으로 정렬함**


## Bound
- 해당 배열에서 **원하는 값이 있는 [가장 큰 index+1]와 [가장 작은 index]를 찾는 함수**
    - 원하는 값이 없는 경우, vector라면 v.end()를 리턴함
- 이분탐색에서 파생
    - 시간복잡도: O(logN)
### 용례
~~~cpp
int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
~~~

### 원리
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
### reference
- upper_bound()의 정의 ([cplusplus](http://www.cplusplus.com/reference/algorithm/upper_bound/))
~~~cpp
template <class ForwardIterator, class T>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = std::distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; std::advance (it,step);
    if (!(val<*it)) // or: if (!comp(val,*it)), for version (2)
      { first=++it; count-=step+1;  }
    else count=step;
  }
  return first;
}
~~~

- lower_bound()의 정의 ([cplusplus](http://www.cplusplus.com/reference/algorithm/lower_bound/))
~~~cpp
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; advance (it,step);
    if (*it<val) { // or: if (comp(*it,val)), for version (2)
      first=++it;
      count-=step+1;
    }
    else count=step;
  }
  return first;
}
~~~