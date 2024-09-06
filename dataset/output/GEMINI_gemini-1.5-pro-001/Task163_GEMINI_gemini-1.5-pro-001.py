def longestRun(lst):
  if len(lst) <= 1:
    return len(lst)

  maxRun = 1
  currentRun = 1

  for i in range(1, len(lst)):
    if (lst[i] == lst[i - 1] + 1) or (lst[i] == lst[i - 1] - 1):
      currentRun += 1
    else:
      currentRun = 1

    maxRun = max(maxRun, currentRun)

  return maxRun