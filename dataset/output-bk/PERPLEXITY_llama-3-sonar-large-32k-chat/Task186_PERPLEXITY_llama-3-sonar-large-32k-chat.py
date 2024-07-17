import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeKLists(lists):
    class Wrapper:
        def __init__(self, node):
            self.node = node
        def __lt__(self, other):
            return self.node.val < other.node.val

    heap = []
    for node in lists:
        if node:
            heapq.heappush(heap, Wrapper(node))

    dummy = ListNode()
    curr = dummy

    while heap:
        node = heapq.heappop(heap).node
        curr.next = node
        curr = curr.next
        if node.next:
            heapq.heappush(heap, Wrapper(node.next))

    return dummy.next