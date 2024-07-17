floors = 6
tower = []
for i in range(floors):
    floor = " " * (floors - i - 1) + "*" * (2 * i + 1) + " " * (floors - i - 1)
    tower.append(floor)
for floor in tower:
    print(floor)