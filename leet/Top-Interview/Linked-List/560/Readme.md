# Reverse Linked List
https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

## Solution
https://leetcode.com/problems/reverse-linked-list/solution/
1. iterative : 근데.. 내가 한건 너무 메모리가 많이들어....왜지?
2. recursive

## Source Code
1-1. 내가 한거
~~~
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = new ListNode(0, head);
        ListNode* cur = head;
        if (head == nullptr) {
            return nullptr;
        }
        while (cur->next != nullptr && cur != nullptr) {
            cur = cur->next;
            ListNode* arg = new ListNode(cur->val, prev->next);
            prev->next = arg;
        }   
        head -> next = nullptr;
        return prev->next;   
    }
};
~~~
1-2. 남이 한거
~~~
public ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
~~~