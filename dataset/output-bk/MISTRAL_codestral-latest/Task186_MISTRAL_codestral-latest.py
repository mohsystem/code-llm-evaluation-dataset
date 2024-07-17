# Python solution using heapq for merging k sorted lists
import heapq

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def mergeKLists(lists):
    heap = [(l.val, idx) for idx, l in enumerate(lists) if l]
    heapq.heapify(heap)
    head = cur = ListNode(0)
    while heap:
        val, idx = heapq.heappop(heap)
        cur.next = ListNode(val)
        cur = cur.next
        node = lists[idx] = lists[idx].next
        if node:
            heapq.heappush(heap, (node.val, idx))
    return head.next