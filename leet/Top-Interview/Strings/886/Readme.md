# Count and Say
https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/

## Solution
1. Sliding Window
~~~
**Intuition**
Now that the problem has been clarified, the solution should be intuitive.

Following the rule as we described above, in order to generate the next sequence, we could scan the current sequence with a sort of sliding window which would hold the identical and adjacent digits. With the sliding window, we would divide the original sequence into a list of sub-sequences. We then count the number of digits within each sub-sequence and output the summary as pairs of |\text{count}, \text{digit}|∣count,digit∣.

**Algorithm**
Here we define a function nextSequence() to generate a following sequence from a previous sequence, and we recursively call this function to get the desired sequence that is located at a specific index.

Within the function, we scan the sequence with two contextual variables: prevDigit and digitCnt which refers to respectively the digit that we are expecting in the sub-sequence and the number of occurrence of the digit in the sub-sequence.
At the end of each sub-sequence, we append the summary to the result and then we reset the above two contextual variables for the next sub-sequence.
Note that, we use an artificial delimiter in the sequence to facilitate the iteration.
~~~

## Source Code
~~~
class Solution {
private:
    vector<string> v;
public:
    string countAndSay(int n) {
        v.push_back("a");
        v.push_back("1");
        v.push_back("11");
        v.push_back("21");
        v.push_back("1211");
        v.push_back("111221");
        v.push_back("312211");
        v.push_back("13112221");
        v.push_back("1113213211");
        v.push_back("31131211131221");
        v.push_back("13211311123113112211");

        for (int i=11; i<=n; i++) {
            v.push_back(func(v[i-1]));
        }
        
        return v[n];
    }
    
    
    string func(string s) {
        string ans = "";
        int cnt = 0;
        int i = 0;
        int j = 0;

        do {
            //for (int j = i; j<s.size(); j++) {
            j = i;
            while (j<s.size()+1) {

                if (s[j] == s[i]) {
                    cnt ++;
                    j++;
                } else if (s[j] != s[i]) {
                    ans += to_string(cnt);
                    ans += s[i];
                    cnt = 0;
                    i = j;
                    break;
                }
            }
        } while (j != s.size()); 



      //  ans += to_string(cnt);
      //  ans += s[i];
        return ans;        
    }
};
~~~