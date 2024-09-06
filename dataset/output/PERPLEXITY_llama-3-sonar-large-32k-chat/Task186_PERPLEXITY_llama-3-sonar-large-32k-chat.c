// Note: C does not have a built-in priority queue, so we can use a simple array to simulate it.
// This implementation is not efficient, but it works for the given constraints.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

void swap(ListNode** a, ListNode** b) {
    ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(ListNode** arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->val < arr[smallest]->val) {
        smallest = left;
    }

    if (right < n && arr[right]->val < arr[smallest]->val) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildHeap(ListNode** arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

ListNode* mergeKLists(ListNode** lists, int k) {
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    ListNode* curr = dummy;

    ListNode** arr = (ListNode**)malloc(k * sizeof(ListNode*));
    for (int i = 0; i < k; i++) {
        arr[i] = lists[i];
    }

    buildHeap(arr, k);

    while (arr[0] != NULL) {
        curr->next = arr[0];
        curr = curr->next;

        if (arr[0]->next != NULL) {
            arr[0] = arr[0]->next;
        } else {
            arr[0] = NULL;
            for (int i = 0; i < k - 1; i++) {
                arr[i] = arr[i + 1];
            }
            k--;
        }

        buildHeap(arr, k);
    }

    return dummy->next;
}