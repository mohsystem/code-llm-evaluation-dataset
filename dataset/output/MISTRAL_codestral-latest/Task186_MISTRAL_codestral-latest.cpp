// C++ solution using priority_queue for merging k sorted lists
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> q;
    for (auto node : lists)
        if (node)
            q.push(node);
    if (q.empty())
        return nullptr;
    ListNode* head = q.top();
    q.pop();
    ListNode* tail = head;
    if (head->next)
        q.push(head->next);
    while (!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if (tail->next)
            q.push(tail->next);
    }
    return head;
}