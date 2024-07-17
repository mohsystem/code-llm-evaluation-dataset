#include <queue>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> queue(cmp);
        for (ListNode* node : lists) {
            if (node != nullptr) {
                queue.push(node);
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!queue.empty()) {
            ListNode* node = queue.top();
            queue.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next != nullptr) {
                queue.push(node->next);
            }
        }

        return dummy->next;
    }
};