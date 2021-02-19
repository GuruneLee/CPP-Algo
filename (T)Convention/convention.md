# Convention
## 끝이 정해지지 않은 입력 받기 (' '가 끼어있는 경우)
~~~cpp
//끝이 정해지지 않은 입력 받기
do {
    
    cin >> n;
    cout << n << endl;
    
} while (getc(stdin) == ' ');
~~~
- int getc ( FILE* stream )  
: 읽어들인 문자를 아스키코드값으로 리턴함