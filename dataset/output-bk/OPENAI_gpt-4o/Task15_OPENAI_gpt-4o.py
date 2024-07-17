def build_tower(n_floors):
    for i in range(n_floors):
        floor = ' ' * (n_floors - i - 1) + '*' * (2 * i + 1) + ' ' * (n_floors - i - 1)
        print(floor)

build_tower(3)
build_tower(6)