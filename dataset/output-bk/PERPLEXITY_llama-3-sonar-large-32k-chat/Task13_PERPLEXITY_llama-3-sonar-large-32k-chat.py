def isValidWalk(walk):
    x, y = 0, 0
    for dir in walk:
        if dir == "n": y += 1
        if dir == "s": y -= 1
        if dir == "e": x += 1
        if dir == "w": x -= 1
    return x == 0 and y == 0 and len(walk) == 10

walk = ["n", "s", "e", "w", "n", "s", "e", "w", "n", "s"]
print(isValidWalk(walk))