# Valid Palindrome
https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

## Solution
1. ASCII alphanumeric characters
**'A' - 'Z' / 'a' - 'z'**
- 65 ~ 90(upper case), 97 ~ 122(lowwer case)
- 'A' + 0~25 (upper case), 'a' + 0~25 (lower case)
**'0' ~ '9'**
- 48 ~ 57

## Source Code
~~~
class Solution {
public:
    
    bool isAlph(char n) {
        return (65<=n && n<=90) || (97<=n && n<=122) || (48<=n&&n<=57);
    }
    
    bool isSame(char a, char b) {
        if (((65<=a && a<=90) || (97<=a && a<=122)) && ((65<=b && b<=90) || (97<=b && b<=122)))
            return (a==b)||(a+32==b)||(a-32==b);
        if ((48<=a&&a<=57) && (48<=b&&b<=57))
            return a==b;
        return false;
    }
    
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        
        int i = 0;
        int j = s.size()-1;
        while (true) {
            if (i>=j) break;
            if (!isAlph(s[i])) {
                i ++;
                continue;
            }
            if (!isAlph(s[j])) {
                j --;
                continue;
            }

            if (!isSame(s[i], s[j])) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};
~~~