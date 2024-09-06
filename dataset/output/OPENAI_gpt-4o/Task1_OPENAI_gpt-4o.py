def number_of_people_on_bus(bus_stops):
    return sum([stop[0] - stop[1] for stop in bus_stops])

bus_stops = [(3, 0), (2, 1), (5, 2), (1, 4)]
print(number_of_people_on_bus(bus_stops))