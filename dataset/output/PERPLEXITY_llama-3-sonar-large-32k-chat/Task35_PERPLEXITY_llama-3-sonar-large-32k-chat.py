def number_of_people_still_on_bus(lst):
    people_on_bus = 0
    for get_on, get_off in lst:
        people_on_bus += get_on - get_off
    return people_on_bus