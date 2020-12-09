# Two Sum
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/

## Solution


## Source Code
### 1. Brute Force O(n*n) O(1)
~~~
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> re;
        for (int i=0; i<nums.size()-1; i++) {
            int tv = target - nums[i];
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] == tv) {
                    re.push_back(i);
                    re.push_back(j);
                    return re;
                }
            }
        }
        return re;
    }
};
~~~

### 2. Hash Table