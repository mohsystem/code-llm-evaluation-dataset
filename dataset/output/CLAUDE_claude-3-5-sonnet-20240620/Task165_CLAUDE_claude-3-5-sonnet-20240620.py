
def checkFlush(table, hand):
    suits = {'S': 0, 'H': 0, 'D': 0, 'C': 0}
    for card in table + hand:
        suits[card[-1]] += 1
    return max(suits.values()) >= 5

# Example usage
print(checkFlush(["A_S", "J_H", "7_D", "8_D", "10_D"], ["J_D", "3_D"]))  # True
print(checkFlush(["10_S", "7_S", "9_H", "4_S", "3_S"], ["K_S", "Q_S"]))  # True
print(checkFlush(["3_S", "10_H", "10_D", "10_C", "10_S"], ["3_S", "4_D"]))  # False
