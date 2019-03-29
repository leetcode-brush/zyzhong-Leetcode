/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;  // 链表为空直接返回，而H->next为空是递归基
        ListNode* rhead = reverseList(head->next);  // 一直循环到链尾 
        head->next->next = head;  // 翻转链表的指向
        head->next = nullptr;  // 记得赋值NULL，防止链表错乱
        return rhead;    // 新链表头永远指向的是原链表的链尾
    }
};

// 非递归
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;  // 暂存p下一个地址，防止变化指针指向后找不到后续的数
            cur->next = pre;
            pre = cur;
            cur = tmp;  // p指向原始链表p指向的下一个空间
        }
        return pre;
    }
};