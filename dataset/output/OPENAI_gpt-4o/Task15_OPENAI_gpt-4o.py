def build_tower(n_floors):
    tower = []
    for i in range(1, n_floors + 1):
        padding = ' ' * (n_floors - i)
        stars = '*' * (2 * i - 1)
        tower.append(padding + stars + padding)
    return tower

print(build_tower(6))