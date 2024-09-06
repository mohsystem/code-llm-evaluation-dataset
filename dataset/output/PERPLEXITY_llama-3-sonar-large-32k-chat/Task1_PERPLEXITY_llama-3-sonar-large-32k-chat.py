def number_of_people_still_on_bus(people):
    return sum([x[0] - x[1] for x in people])