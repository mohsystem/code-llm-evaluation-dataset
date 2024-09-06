class Clock:
    def __init__(self, hours, minutes):
        self.hours = hours
        self.minutes = minutes

    def add_minutes(self, minutes):
        self.minutes += minutes
        self.hours += self.minutes // 60
        self.hours %= 24
        self.minutes %= 60

    def subtract_minutes(self, minutes):
        self.minutes -= minutes
        if self.minutes < 0:
            self.hours -= 1
            self.minutes += 60
        self.hours %= 24
        self.minutes %= 60

    def __eq__(self, other):
        return self.hours == other.hours and self.minutes == other.minutes

clock1 = Clock(10, 30)
clock2 = Clock(10, 30)
print(clock1 == clock2)  # True

clock1.add_minutes(30)
print(clock1.hours, clock1.minutes)  # 11 0

clock1.subtract_minutes(60)
print(clock1.hours, clock1.minutes)  # 10 0