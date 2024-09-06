def posNegSort(lst):
  pos = sorted([x for x in lst if x > 0])
  res = []
  j = 0
  for i in range(len(lst)):
    if lst[i] > 0:
      res.append(pos[j])
      j+= 1
    else:
      res.append(lst[i])
  return res