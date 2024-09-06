def is_valid_walk(walk):
    if len(walk) != 10:
        return False
    position = [0, 0]
    for direction in walk:
        if direction == 'n':
            position[1] += 1
        elif direction == 's':
            position[1] -= 1
        elif direction == 'e':
            position[0] += 1
        elif direction == 'w':
            position[0] -= 1
    return position == [0, 0]