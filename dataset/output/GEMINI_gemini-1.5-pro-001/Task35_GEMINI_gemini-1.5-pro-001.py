def number(bus_stops):
    people_in_bus = 0
    for stop in bus_stops:
        people_in_bus += stop[0] - stop[1]
    return people_in_bus