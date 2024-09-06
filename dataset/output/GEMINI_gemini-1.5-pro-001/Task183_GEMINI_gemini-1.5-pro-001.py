def largest_product(digits, span):
  if len(digits) < span or span < 1:
    return 0
  max_product = 0
  for i in range(len(digits) - span + 1):
    product = 1
    for j in range(i, i + span):
      product *= int(digits[j])
    max_product = max(max_product, product)
  return max_product