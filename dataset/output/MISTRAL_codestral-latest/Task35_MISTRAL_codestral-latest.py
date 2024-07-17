def bus_stops(stops):
    return sum(on - off for on, off in stops)