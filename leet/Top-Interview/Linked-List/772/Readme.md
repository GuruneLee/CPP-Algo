# Palindrome Linked List
https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/

## Solution
1.  
1단계, 가운데 부터 시작하는 node구하기(m)->O(n)  
2단계, m부터 end까지 reverse->O(n)  
3단계, head,m 비교->O(n)  

## Source Code
~~~ (미완성)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //1단계
        if (!head || !(head->next)) return true;
        ListNode* first = head;
        ListNode* second = head;
        while (second!=null && second->next!=nullptr) {
            first = first->next;
            second = second->next->next;
        }
        if (second == nullptr) {
            first = first->next;
        } 

        //2단계
        ListNode* prev = nullptr;
        while(tmp!=nullptr) {
            ListNode* tmp = first->next;
            first->next=prev;
            prev = first;
            first = tmp;
        }
        first = prev;

        //3단계
        while(!first) {
            if (first->val != head->val) {
                return false;
            }
            first = first->next;
            head = head->next;
        }

        return true;
    }
};
~~~