# Longest Common Prefix
https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/

## Solution
https://leetcode.com/problems/longest-common-prefix/solution/
1. (내가 푼 방법) 모든 글자를 돌며, 맵에 모든 prefix의 개수를 저장. -> O(n*l)
-> '공통'prefix를 찾는 것이기 때문에, 하나만 잡고 그걸 중심으로 돌아도 상관 없음...
2. Divide and Conquer
: 스트링 배열을 분할해서 인접한 두 요소의 prefix를 찾는 것을 반복
![dvideConquer](./devideConquer.jpg)

## Source Code
1. map활용
~~~
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> m;
        for (auto s : strs) {
            string ck = "";
            for (auto c : s) {
                ck += c;
                m[ck] += 1;
            }
        }
        
        int ms = 0;
        string ans = "";
        for (auto e : m) {
            if (e.second == strs.size()) {
                if (e.first.size() > ms) {
                    ms = e.first.size();
                    ans = e.first;
                } 
            }
        }

        return ans;
    }
};
~~~