#include <queue>
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;
        for (auto l : lists) {
            if (l) pq.push(l);
        }
        ListNode head(0);
        ListNode* point = &head;
        while (!pq.empty()) {
            point->next = pq.top();
            pq.pop();
            point = point->next;
            if (point->next) pq.push(point->next);
        }
        return head.next;
    }
};

int main() {
    std::vector<ListNode*> lists = {
        new ListNode(1, new ListNode(4, new ListNode(5))),
        new ListNode(1, new ListNode(3, new ListNode(4))),
        new ListNode(2, new ListNode(6))
    };
    
    Solution s;
    ListNode* result = s.mergeKLists(lists);
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}