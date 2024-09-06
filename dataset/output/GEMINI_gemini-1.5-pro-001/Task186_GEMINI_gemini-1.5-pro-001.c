#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;
  if (l1->val < l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  } else {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}

struct ListNode *mergeKLists(struct ListNode **lists, int k) {
  if (k == 0) return NULL;
  int i;
  struct ListNode *result = lists[0];
  for (i = 1; i < k; i++) {
    result = mergeTwoLists(result, lists[i]);
  }
  return result;
}

int main() {
  int k = 3;
  struct ListNode *lists[3];
  lists[0] = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[0]->val = 1;
  lists[0]->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[0]->next->val = 4;
  lists[0]->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[0]->next->next->val = 5;
  lists[0]->next->next->next = NULL;

  lists[1] = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[1]->val = 1;
  lists[1]->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[1]->next->val = 3;
  lists[1]->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[1]->next->next->val = 4;
  lists[1]->next->next->next = NULL;

  lists[2] = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[2]->val = 2;
  lists[2]->next = (struct ListNode *)malloc(sizeof(struct ListNode));
  lists[2]->next->val = 6;
  lists[2]->next->next = NULL;

  struct ListNode *result = mergeKLists(lists, k);

  while (result != NULL) {
    printf("%d ", result->val);
    result = result->next;
  }

  return 0;
}