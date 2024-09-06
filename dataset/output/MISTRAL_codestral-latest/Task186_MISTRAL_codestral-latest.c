// C
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) return NULL;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* curr = dummy;
    struct ListNode** heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    int heapSize = 0;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            heap[heapSize++] = lists[i];
        }
    }
    buildHeap(heap, heapSize);
    while (heapSize > 0) {
        curr->next = heap[0];
        curr = curr->next;
        if (curr->next != NULL) {
            heap[0] = curr->next;
            heapify(heap, 0, heapSize);
        } else {
            heap[0] = heap[--heapSize];
            heapify(heap, 0, heapSize);
        }
    }
    return dummy->next;
}

void buildHeap(struct ListNode** heap, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, i, heapSize);
    }
}

void heapify(struct ListNode** heap, int i, int heapSize) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heapSize && heap[left]->val < heap[smallest]->val) {
        smallest = left;
    }
    if (right < heapSize && heap[right]->val < heap[smallest]->val) {
        smallest = right;
    }
    if (smallest != i) {
        struct ListNode* temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, smallest, heapSize);
    }
}