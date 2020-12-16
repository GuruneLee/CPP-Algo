# Delete Node in a Linked List
https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/

## Solution
[ node1 (val = 1) -> node2 (val = 2) -> node3 (val = 3) -> ... ]에서 node2삭제  
=> node2의 값에 node3값을 대입 + node2.next에 node3.next를 대입  
=> 결과적으로 node3의 정보를 node2로 옮기고, node3를 버리는거임  

## Source Code
~~~
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
~~~