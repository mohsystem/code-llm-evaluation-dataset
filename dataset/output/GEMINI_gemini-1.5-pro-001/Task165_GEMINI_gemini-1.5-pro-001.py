def checkFlush(table, hand):
  suits = {"S":0, "H":0, "D":0, "C":0}
  for card in table:
    suits[card[-1]] += 1
  for card in hand:
    suits[card[-1]] += 1
  for val in suits.values():
    if val >= 5:
      return True
  return False