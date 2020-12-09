# Best Time to Buy and Sell Stock 2
https://leetcode.com/problems/rotate-array/

## Solution
https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions
1. Using Extra Array O(n) / O(n)
2. Brute Force O(n*k) / O(1)
3. Cyclic Replacements O(n) / O(1)
4. Reverse O(n) / O(1)

## Source Code
### 1. Using Extra Array
"""
class Solution {
    public void rotate(vector<int>& nums, int k) {
            vector<int> n(nums.size());
            for (int i=0; i<nums.size(); i++) {
                n[(i+k)%nums.size()] = nums[i];
            }
            nums = n;
    }
}

"""
### 2. Brute Force (Time Exceeded)
"""
class Solution {
  public void rotate(int[] nums, int k) {
    // speed up the rotation
    k %= nums.length;
    int temp, previous;
    for (int i = 0; i < k; i++) {
      previous = nums[nums.length - 1];
      for (int j = 0; j < nums.length; j++) {
        temp = nums[j];
        nums[j] = previous;
        previous = temp;
      }
    }
  }
}

"""
### 3. Cyclic Replacements (미완성 33/35)
"""
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        
        if (k == 0) {
            return;
        }
        
        if (len % k != 0) {
            //one cycle
            int i = 0;
            int pre = nums[i];
            int tmp = 0;
            for(int j=0; j<len; j++) {
                tmp = nums[(i+k)%len];
                nums[(i+k)%len] = pre;
                pre = tmp;
                i = (i+k)%len;
            }
        } else {
            for(int i=0; i<k; i++) {
                //one cycle
                int pre = nums[i];
                int tmp = 0;
                for(int l=0; l<len/k; l++) {
                    tmp = nums[(i+k)%len];
                    nums[(i+k)%len] = pre;
                    pre = tmp;
                    i = (i+k)%len;
                }
            }
        }
        
    }
};
"""