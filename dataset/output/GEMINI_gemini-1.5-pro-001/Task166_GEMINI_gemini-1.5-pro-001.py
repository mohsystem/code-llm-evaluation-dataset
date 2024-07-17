def posNegSort(lst):
  pos = sorted([x for x in lst if x > 0])
  j = 0
  res = []
  for i in range(len(lst)):
    if lst[i] > 0:
      res.append(pos[j])
      j += 1
    else:
      res.append(lst[i])
  return res