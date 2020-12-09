# Move Zeroes
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/

## Solution


## Source Code
### 1. 0개수 세고, index늘리면서 갖다 붙이기
| 바뀔 숫자의 위치는 언제나 뒤의 숫자들에 절대 영향을 미치지 않는다.
~~~
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        int ind = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==0) {
                cnt ++;
            } else {
                nums[ind] = nums[i];
                ind ++;
            }
        }
        for (int i=cnt; i>0; --i) {
            nums[nums.size()-i] = 0;
        }
        
    }
};
~~~