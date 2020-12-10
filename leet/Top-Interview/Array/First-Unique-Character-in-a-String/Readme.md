# First Unique Character in a String

## Solution
1. Hash map O(n)

## Source Code C++
class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c] += 1; //map에 각 '문자' - '포함된 횟수' 저장
        }

        //map의 value==1인 key중, 등장한 index가 가장 작은 key의 index찾기
        int min = -1;
        for (auto e : m) {
            if (e.second == 1) {
                if (min > s.find(e.first)){
                    min = s.find(e.first);
                }
            }
        }
        return min;
    }
};