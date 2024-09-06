def tower_builder(n_floors):
    tower = []
    for i in range(n_floors):
        tower.append(' ' * (n_floors - i - 1) + '*' * (2 * i + 1) + ' ' * (n_floors - i - 1))
    return tower