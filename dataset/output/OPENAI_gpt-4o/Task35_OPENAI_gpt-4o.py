def number_of_people(bus_stops):
    total_people = 0
    for on, off in bus_stops:
        total_people += on
        total_people -= off
    return total_people

# Test case
bus_stops = [(10, 0), (3, 5), (5, 8)]
print(number_of_people(bus_stops))