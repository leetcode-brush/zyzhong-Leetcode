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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carried = 0;
        while (p1 || p2) {
            int a = p1 ? p1->val : 0;
            int b = p2 ? p2->val : 0;
            cur->next = new ListNode((a + b + carried) % 10);
            carried = (a + b + carried) / 10;
            cur = cur->next;
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
        }
        if (carried) cur->next = new ListNode(1);
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};