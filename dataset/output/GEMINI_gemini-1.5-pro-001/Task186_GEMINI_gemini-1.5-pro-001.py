def mergeKLists(lists):
  if not lists or len(lists) == 0:
    return None

  while len(lists) > 1:
    mergedLists = []
    for i in range(0, len(lists), 2):
      l1 = lists[i]
      l2 = lists[i + 1] if (i + 1) < len(lists) else None
      mergedLists.append(mergeTwoLists(l1, l2))
    lists = mergedLists

  return lists[0]

def mergeTwoLists(l1, l2):
  if not l1:
    return l2
  if not l2:
    return l1

  if l1.val < l2.val:
    l1.next = mergeTwoLists(l1.next, l2)
    return l1
  else:
    l2.next = mergeTwoLists(l1, l2.next)
    return l2