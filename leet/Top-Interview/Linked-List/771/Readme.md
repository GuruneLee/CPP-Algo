# Merge Two Sorted Lists
https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/

## Solution
merge sort랑 똑같이 하면 됨

## Source Code
~~~
class Solution {
public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* merged = new ListNode(0);
        ListNode* cur = merged;
        do {
            if (l1->val <= l2->val) {
                cur->next=l1;
                l1 = l1->next;
                cur = cur->next;
            } else if (l1->val > l2->val) {
                cur->next=l2;
                l2 = l2->next;
                cur = cur->next;
            }
        } while (l1!=nullptr && l2!=nullptr);

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