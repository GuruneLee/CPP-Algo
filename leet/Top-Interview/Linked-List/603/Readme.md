# Remove Nth Node From End of List
https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

## Solution
1. 제거해야 할 node가 tail일 때와, 아닐때 나눠서 구현  
2. prev->next = head를 만족하는 prev node를 만들어서, 언제나 제거하고자 하는 node의 이전 node에 접근할 수 있도록 구현

## Source Code
1. 제거해야 할 node가 tail일 때와, 아닐때 나눠서 구현  
~~~
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cn = head;
        int sz = 1;
        while (cn->next != nullptr) {
            cn = cn->next;
            sz += 1;
        }
        
        if (sz == 1) {
            return nullptr;
        }
        
        n = sz-n;
        cn = head;
        
        
        if (n == sz-1) { //tail
            while (cn->next->next != nullptr) {
                cn = cn->next;
            }
            cn->next = nullptr;
        } else {
            while (n--) {
                cn = cn->next;
            }
            cn->val = cn->next->val;
            cn->next = cn->next->next;
        }
        
        return head;
    }
};
~~~

2. prev->next = head를 만족하는 prev node를 만들어서, 언제나 제거하고자 하는 node의 이전 node에 접근할 수 있도록 구현
~~~
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = new ListNode(0, head);
        ListNode* k = head;
        int sz = 0;
        while (k) {
            k = k->next;
            sz++;
        }
        
        n = sz-n;
        k = prev;
        while(n--) {
            prev = prev->next;
        }
        
        prev->next = prev->next->next;
        
        return k->next;
    }
};
~~~