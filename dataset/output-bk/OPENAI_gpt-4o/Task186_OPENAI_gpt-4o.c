#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head = NULL;
    struct ListNode** tail = &head;
    
    while (1) {
        int minIndex = -1;
        for (int i = 0; i < listsSize; i++) {
            if (lists[i] && (minIndex == -1 || lists[i]->val < lists[minIndex]->val)) {
                minIndex = i;
            }
        }
        if (minIndex == -1) break;
        *tail = lists[minIndex];
        tail = &((*tail)->next);
        lists[minIndex] = lists[minIndex]->next;
    }
    
    return head;
}

struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
    }
    current->next = NULL;
    return head;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main() {
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};
    
    struct ListNode* lists[] = {
        createList(arr1, 3),
        createList(arr2, 3),
        createList(arr3, 2)
    };
    
    struct ListNode* result = mergeKLists(lists, 3);
    printList(result);
    
    return 0;
}