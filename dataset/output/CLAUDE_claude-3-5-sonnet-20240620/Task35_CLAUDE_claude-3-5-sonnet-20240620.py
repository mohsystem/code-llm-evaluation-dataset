
def count_passengers(bus_stops):
    return sum(on - off for on, off in bus_stops)

if __name__ == "__main__":
    bus_stops = [[10,0], [3,5], [5,8]]
    print(count_passengers(bus_stops))
