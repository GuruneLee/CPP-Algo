# 전화번호 목록
https://programmers.co.kr/learn/courses/30/lessons/42577

## Solution
1. 각 스트링의 각 접두어가 배열안에 존재하는지 확인하기 -> C++은 각 스트링의 각 접두어를 뽑아내는것도 일일듯 ㅋ
2. Tree -> 이거 안될거 같음...

## Source Code (C++)
1. 각 스트링의 각 접두어가 배열안에 존재하는지 확인하기
~~~
bool solution(vector<string> phone_book) {
   bool answer = true;
    //sort(phone_book.begin(), phone_book.end(), sortFunc);
    map<string, int> m;
    for (auto s : phone_book) {
        m[s] = 1;
    }

    for (auto s : phone_book) {
        m[s] = 0;
        string ap = "";
        for (int i=0; i<s.size(); i++) {
            ""char ts = s[i];
            ap.append(1, ts); //문자를 추가할 때는 개수를 같이 기입해야 함
            if (m[ap] == 1) { //map을 사용하지 않으면 find()함수를 사용해야 함
                answer = false;
                return answer;
            }""
        }
        m[s] = 1;
    }
    return answer;
}
~~~