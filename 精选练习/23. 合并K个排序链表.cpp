/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, cmp> pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        for (auto list : lists)
            if (list != nullptr)
                pq.push(list);
        while (!pq.empty()) {
            ListNode* minimal = pq.top();
            pq.pop();
            ListNode* tmp  = new ListNode (minimal->val);
            cur->next = tmp;
            cur = cur->next;
            if  (minimal->next)
                pq.push(minimal->next);
        }
        ListNode* res;
        res = dummy->next;
        delete dummy;
        return res;
    }
};