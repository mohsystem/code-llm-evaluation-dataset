def build_tower(n_floors):
    tower = []
    for i in range(n_floors):
        floor = " " * (n_floors - i - 1) + "*" * (2 * i + 1) + " " * (n_floors - i - 1)
        tower.append(floor)
    return tower