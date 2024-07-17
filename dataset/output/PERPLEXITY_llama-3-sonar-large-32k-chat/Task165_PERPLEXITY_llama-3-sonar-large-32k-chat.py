def checkFlush(table, hand):
    suits = {'S': 0, 'H': 0, 'D': 0, 'C': 0}
    for card in table + hand:
        suit = card.split('_')[1]
        suits[suit] += 1
    return any(count >= 5 for count in suits.values())