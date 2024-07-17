class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def mergeKLists(lists):
    from queue import PriorityQueue
    pq = PriorityQueue()
    for l in lists:
        if l:
            pq.put((l.val, l))
    head = point = ListNode(0)
    while not pq.empty():
        val, node = pq.get()
        point.next = ListNode(val)
        point = point.next
        node = node.next
        if node:
            pq.put((node.val, node))
    return head.next

# Helper functions to convert between ListNode and Python lists for easier testing:
def to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

def to_nodes(lst):
    if not lst:
        return None
    head = ListNode(lst[0])
    current = head
    for i in range(1, len(lst)):
        current.next = ListNode(lst[i])
        current = current.next
    return head

lists = [[to_nodes([1,4,5]), to_nodes([1,3,4]), to_nodes([2,6])]]
merged = mergeKLists(lists)
print(to_list(merged))