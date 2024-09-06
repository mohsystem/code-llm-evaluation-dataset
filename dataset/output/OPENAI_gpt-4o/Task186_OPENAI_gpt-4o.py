# Python code for merging k sorted linked lists
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
def mergeKLists(lists):
    import heapq
    heap = []
    for l in lists:
        while l:
            heapq.heappush(heap, l.val)
            l = l.next
    
    dummy = ListNode()
    curr = dummy
    while heap:
        curr.next = ListNode(heapq.heappop(heap))
        curr = curr.next
    
    return dummy.next

def printList(node):
    while node:
        print(node.val, end=' ')
        node = node.next
    print()

# Example usage
lists = []
node1 = ListNode(1, ListNode(4, ListNode(5)))
node2 = ListNode(1, ListNode(3, ListNode(4)))
node3 = ListNode(2, ListNode(6))
lists.append(node1)
lists.append(node2)
lists.append(node3)

merged = mergeKLists(lists)
printList(merged)