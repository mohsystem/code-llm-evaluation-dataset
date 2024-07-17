def people_on_bus(bus_stops):
    people = 0
    for stop in bus_stops:
        people += stop[0]
        people -= stop[1]
    return people

if __name__ == "__main__":
    bus_stops = [(3, 0), (2, 1), (5, 3), (2, 2)]
    print(people_on_bus(bus_stops))