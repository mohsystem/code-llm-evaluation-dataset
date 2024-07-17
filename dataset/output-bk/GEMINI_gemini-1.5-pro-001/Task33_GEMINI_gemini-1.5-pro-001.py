def solve_super_market_queue(customers, n):
  if len(customers) == 0:
    return 0
  if len(customers) <= n:
    return max(customers)
  tills = [0 for _ in range(n)]
  customer_index = 0
  for i in range(n):
    tills[i] = customers[customer_index]
    customer_index += 1
  while customer_index < len(customers):
    next_till = tills.index(min(tills))
    tills[next_till] += customers[customer_index]
    customer_index += 1
  return max(tills)