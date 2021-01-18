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