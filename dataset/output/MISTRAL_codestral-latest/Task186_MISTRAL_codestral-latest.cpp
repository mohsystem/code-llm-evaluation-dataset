// CPP
/*
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> queue(cmp);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (ListNode* node : lists) {
            if (node != nullptr) {
                queue.push(node);
            }
        }
        while (!queue.empty()) {
            curr->next = queue.top();
            queue.pop();
            curr = curr->next;
            if (curr->next != nullptr) {
                queue.push(curr->next);
            }
        }
        return dummy->next;
    }
};