
def tower_builder(n_floors):
    tower = []
    for i in range(n_floors):
        stars = "*" * (2*i + 1)
        spaces = " " * (n_floors - i - 1)
        tower.append(f"{spaces}{stars}{spaces}")
    return tower

if __name__ == "__main__":
    tower = tower_builder(6)
    for floor in tower:
        print(floor)
