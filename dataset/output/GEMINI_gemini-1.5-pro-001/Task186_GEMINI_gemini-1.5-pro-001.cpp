#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    if (lists.empty()) return nullptr;
    auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
    for (ListNode* head : lists) {
      if (head) pq.push(head);
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (!pq.empty()) {
      ListNode* top = pq.top();
      pq.pop();
      cur->next = top;
      cur = cur->next;
      if (top->next) pq.push(top->next);
    }
    return dummy->next;
  }
};