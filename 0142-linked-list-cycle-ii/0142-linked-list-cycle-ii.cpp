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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        unordered_set<ListNode*> vis;
        ListNode* cur = head;
        while (1) {
            vis.insert(cur);
            if (cur->next == nullptr) return nullptr;
            if (vis.count(cur->next)) return cur->next;
            cur = cur->next;
        }
    }
};