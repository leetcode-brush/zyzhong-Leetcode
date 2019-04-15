// 本质上是将尾部向前数第K个元素作为头，原来的头接到原来的尾上
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
     int GetLen(ListNode* head) {
        int res = 0;
        while(head) {
            res++;
            head = head->next;
        }
        return res;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int len = GetLen(head);
        k %= len;
        ListNode* end = head;
        for(int i = 0 ; i < k ; i++)
            end = end->next;
        ListNode* start = head;
        while(end->next != nullptr) {
            start = start->next;
            end = end->next;
        }
        end->next = head;
        head = start->next;
        start->next = nullptr;
        return head;
    }
};