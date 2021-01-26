# STRING
- **string의 마지막 문자는 null임. index는 s.size()... ㅋ**
- character의 범위 (ASCII)
    - 'a'~'z': 97~122
    - 'A'~'Z': 65~90
    - '0'~'9': 48~57
## &#60;string&#62; 함수들
http://www.tcpschool.com/cpp/cpp_string_stringMethod

### append()
1. **문자열.append(추가할문자열);**               
: 추가할 문자열을 맨 끝에 추가함.
2. **문자열.append(추가할문자열, 시작위치, 개수);** 
: 추가할 문자열의 시작 위치부터 개수만큼만 맨 끝에 추가함.
3. **문자열.append(개수, 추가할문자);**             
: 추가할 문자를 개수만큼 맨 끝에 추가함

### find()
1. **문자열.find(찾을문자열);**           
: 인덱스 0부터 찾을 문자열을 찾아, 그 시작 위치를 반환함.
2. **문자열.find(찾을문자);**             
: 인덱스 0부터 찾을 문자를 찾아, 그 시작 위치를 반환함.
3. **문자열.find(찾을문자열, 시작위치);** 
: 시작 위치부터 찾을 문자열을 찾아, 그 시작 위치를 반환함.
4. **찾지 못할 시, `string::npos`를 반환** 

### compare()
1. **str1.compare(str_02) == 0** 
: str1과 str2이 같을 경우
2. **str1.compare(str_02) < 0**  
: str1이 str2보다 사전 편찬순으로 앞에 있을 경우
3. **str1.compare(str_02) > 0**  
: str1이 str2보다 사전 편찬순으로 뒤에 있을 경우

### replace()
**문자열.replace(대체할문자열의시작위치, 대체할문자열의길이, 새로운문자열);** 
: 전달된 시작 위치부터 문자열의 길이만큼을 제거한 후에, 새로운 문자열을 삽입함

### substr()
1. s.substr(int pos);
: pos부터 끝 까지 string으로 반환
2. s.substr(int pos, int count);
: [pos, pos+count) string으로 반환

### 문자열 <-> 숫자 함수들
1. **string to_string(int val);**
2. **int stoi(string& s)**
3. **long long stoll(string& s)**
4. **flout stof(string& s)**

## &#60;algorithm&#62; 함수들
### std::reverse()
**std::reverse(BidirectionalIterator first, BidirectionalIterator last);**
~~~
string str = "abcd"
reverse(str.begin(), str.end());
~~~


## 관련 문제
1. **프로그래머스 > 전화번호 목록**
https://programmers.co.kr/learn/courses/30/lessons/42577
- 접두어 추출하는 방법 `append()`
- hash-map 사용한 빠른 search
2. **leetcode > First-Unique-Char**
https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
- 해당 문자가 가장 처음 등장하는 위치 `find()`
- hash-map 사용한 글자 수 세기