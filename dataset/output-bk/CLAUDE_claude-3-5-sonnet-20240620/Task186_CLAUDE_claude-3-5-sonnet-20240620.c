
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    
    curr->next = l1 ? l1 : l2;
    return dummy.next;
}

struct ListNode* mergeKListsHelper(struct ListNode** lists, int start, int end) {
    if (start == end) {
        return lists[start];
    }
    if (start + 1 == end) {
        return mergeTwoLists(lists[start], lists[end]);
    }
    
    int mid = start + (end - start) / 2;
    struct ListNode* left = mergeKListsHelper(lists, start, mid);
    struct ListNode* right = mergeKListsHelper(lists, mid + 1, end);
    return mergeTwoLists(left, right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }
    
    return mergeKListsHelper(lists, 0, listsSize - 1);
}
