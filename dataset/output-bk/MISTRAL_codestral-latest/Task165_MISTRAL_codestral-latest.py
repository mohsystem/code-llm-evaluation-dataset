def checkFlush(table, hand):
    suits = [card[-1] for card in table + hand]
    for suit in 'SHDC':
        if suits.count(suit) >= 5:
            return True
    return False