# 위장
https://programmers.co.kr/learn/courses/30/lessons/42578

## Solution (C++)
1. map[종류] = 갯수 ( string, int ) 로 넣고 다 곱해벌이기


## Source Code
1. unordered_map<string, int>
~~~
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for (vector<string> v : clothes) {
        m[v[1]] += 1;
    }
  
    for (auto e : m) {
        answer *= (e.second)+1;
    }
    
    return answer-1;
}
~~~