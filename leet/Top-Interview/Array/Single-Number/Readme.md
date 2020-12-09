# Single-Number
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/

## Solution


## Source Code
### 1. Using sort() func. O(nlogn) O(1)
~~~
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        //O(nlogn) O(1)
        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size()-1; i++) {
            if (nums[i] != nums[i-1] && nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        if (nums[0] != nums[1])                         
            return nums[0];
        return nums[nums.size()-1];
    }
};
~~~ 

### 2. Linear runtime without extra memory - XOR
~~~
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int i=0; i<nums.size(); i++) {
            a = (a ^ nums[i]);
        }
        return a;
    }
};
~~~