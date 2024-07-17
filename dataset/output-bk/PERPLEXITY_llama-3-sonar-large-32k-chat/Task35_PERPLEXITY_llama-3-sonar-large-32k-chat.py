def people_on_bus(stops):
    people = 0
    for stop in stops:
        people += stop[0] - stop[1]
    return people

stops = [[10, 0], [3, 5], [5, 8]]
print(people_on_bus(stops))