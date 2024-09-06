// C++ code for merging k sorted linked lists
#include <iostream>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    for (ListNode* l : lists) {
        while (l) {
            heap.push(l->val);
            l = l->next;
        }
    }
    
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    while (!heap.empty()) {
        curr->next = new ListNode(heap.top());
        heap.pop();
        curr = curr->next;
    }
    
    return dummy->next;
}

void printList(ListNode* node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<ListNode*> lists;
    lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
    lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    lists.push_back(new ListNode(2, new ListNode(6)));
    
    ListNode* merged = mergeKLists(lists);
    printList(merged);
    return 0;
}