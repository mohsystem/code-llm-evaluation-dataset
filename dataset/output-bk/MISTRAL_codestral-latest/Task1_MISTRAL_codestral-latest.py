# Python
def count_passengers(stops):
    return sum(on - off for on, off in stops)