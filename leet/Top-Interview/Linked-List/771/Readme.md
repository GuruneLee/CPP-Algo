# Merge Two Sorted Lists
https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/ 

## Solution
merge sort랑 똑같이 하면 됨

## Source Code
~~~
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1) {
            return nullptr;
        }
        if (l2) {
            return nullptr;
        }
        ListNode* merged = new ListNode(0);
        ListNode* cur = merged;
        ListNode* tmp = nullptr;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp = l1;
                l1 = l1->next;
                cur->next=tmp;
                cur = cur->next;
            }
            if (l1->val > l2->val) {
                tmp = l2;
                l2 = l2->next;
                cur->next=tmp;
                cur = cur->next;
            }
        }

        if (!l1) {
            while(l2) {
                tmp = l2;
                l2 = l2->next;
                cur->next=tmp;
                cur = cur->next;
            }
        }
        if (!l2) {
            while(l1) {
                tmp = l1;
                l1 = l1->next;
                cur->next=tmp;
                cur = cur->next;
            }
        }

        return merged->next;
    }
};
~~~