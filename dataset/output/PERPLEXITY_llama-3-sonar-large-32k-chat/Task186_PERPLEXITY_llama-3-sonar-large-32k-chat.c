#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode **array;
    int size;
} PriorityQueue;

void PriorityQueue_init(PriorityQueue *queue, int size) {
    queue->array = (ListNode **)malloc(size * sizeof(ListNode *));
    queue->size = 0;
}

void PriorityQueue_push(PriorityQueue *queue, ListNode *node) {
    queue->array[queue->size++] = node;
    int i = queue->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (queue->array[parent]->val <= queue->array[i]->val) break;
        ListNode *temp = queue->array[parent];
        queue->array[parent] = queue->array[i];
        queue->array[i] = temp;
        i = parent;
    }
}

ListNode *PriorityQueue_pop(PriorityQueue *queue) {
    ListNode *node = queue->array[0];
    queue->array[0] = queue->array[--queue->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < queue->size && queue->array[left]->val < queue->array[smallest]->val) smallest = left;
        if (right < queue->size && queue->array[right]->val < queue->array[smallest]->val) smallest = right;
        if (smallest == i) break;
        ListNode *temp = queue->array[i];
        queue->array[i] = queue->array[smallest];
        queue->array[smallest] = temp;
        i = smallest;
    }
    return node;
}

ListNode *mergeKLists(ListNode **lists, int listsSize) {
    PriorityQueue queue;
    PriorityQueue_init(&queue, listsSize);
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            PriorityQueue_push(&queue, lists[i]);
        }
    }

    ListNode *dummy = (ListNode *)malloc(sizeof(ListNode));
    ListNode *curr = dummy;

    while (queue.size > 0) {
        ListNode *node = PriorityQueue_pop(&queue);
        curr->next = node;
        curr = curr->next;
        if (node->next != NULL) {
            PriorityQueue_push(&queue, node->next);
        }
    }

    return dummy->next;
}