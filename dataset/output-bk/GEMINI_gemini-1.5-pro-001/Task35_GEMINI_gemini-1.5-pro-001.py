def get_number_of_people_on_bus(bus_stops):
    people_on_bus = 0

    for stop in bus_stops:
        people_on_bus += stop[0] - stop[1]

    return people_on_bus


# Test cases
bus_stops1 = [[10, 0], [3, 5], [5, 8]]
bus_stops2 = [[3, 0], [9, 1], [4, 10], [12, 2], [6, 1], [7, 10]]
bus_stops3 = [[3, 0], [9, 1], [4, 8], [12, 2], [6, 1], [7, 8]]

print(get_number_of_people_on_bus(bus_stops1))  # 5
print(get_number_of_people_on_bus(bus_stops2))  # 17
print(get_number_of_people_on_bus(bus_stops3))  # 21