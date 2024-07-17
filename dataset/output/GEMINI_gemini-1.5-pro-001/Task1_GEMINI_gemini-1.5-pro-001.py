def peopleOnBus(busStops):
    peopleOnBus = 0
    for i in range(len(busStops)):
        peopleOnBus += busStops[i][0] - busStops[i][1]
    return peopleOnBus


if __name__ == "__main__":
    busStops = [[10, 0], [3, 5], [5, 8]]
    print(peopleOnBus(busStops))