// C code for merging k sorted linked lists
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int* heap = (int*)malloc(100000 * sizeof(int));
    int heapSize = 0;
    
    for (int i = 0; i < listsSize; ++i) {
        struct ListNode* l = lists[i];
        while (l) {
            heap[heapSize++] = l->val;
            l = l->next;
        }
    }
    
    qsort(heap, heapSize, sizeof(int), (int(*)(const void*, const void*)) strcmp);
    
    struct ListNode* dummy = createNode(0);
    struct ListNode* curr = dummy;
    for (int i = 0; i < heapSize; ++i) {
        curr->next = createNode(heap[i]);
        curr = curr->next;
    }
    
    return dummy->next;
}

void printList(struct ListNode* node) {
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* lists[3];
    lists[0] = createNode(1);
    lists[0]->next = createNode(4);
    lists[0]->next->next = createNode(5);
    
    lists[1] = createNode(1);
    lists[1]->next = createNode(3);
    lists[1]->next->next = createNode(4);
    
    lists[2] = createNode(2);
    lists[2]->next = createNode(6);
    
    struct ListNode* merged = mergeKLists(lists, 3);
    printList(merged);
    
    return 0;
}