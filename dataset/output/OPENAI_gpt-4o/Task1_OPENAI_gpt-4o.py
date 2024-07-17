def people_on_the_bus(stops):
    people_on_bus = 0
    for stop in stops:
        people_on_bus += stop[0] - stop[1]
    return people_on_bus

stops = [(10, 0), (3, 5), (2, 5)]
print(people_on_the_bus(stops)) # Output should be 5