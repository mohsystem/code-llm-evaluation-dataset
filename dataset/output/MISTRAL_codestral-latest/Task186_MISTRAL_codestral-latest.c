// C solution using a min heap for merging k sorted lists
struct ListNode {
    int val;
    struct ListNode *next;
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    priority_queue<ListNode*, vector<ListNode*>, compare> q;
    for (int i = 0; i < listsSize; i++)
        if (lists[i])
            q.push(lists[i]);
    if (q.empty())
        return NULL;
    struct ListNode* head = q.top();
    q.pop();
    struct ListNode* tail = head;
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