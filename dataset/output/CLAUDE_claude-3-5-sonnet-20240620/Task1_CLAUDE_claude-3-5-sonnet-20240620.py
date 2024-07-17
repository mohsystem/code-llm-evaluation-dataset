
def count_passengers(bus_stops):
    return sum(on - off for on, off in bus_stops)

bus_stops = [(10, 0), (3, 5), (2, 5)]
print(count_passengers(bus_stops))  # Output: 5
