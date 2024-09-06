class Clock:
    def __init__(self, hour, minute):
        self.hour = hour
        self.minute = minute
        self.normalize()

    def normalize(self):
        if self.minute >= 60:
            self.hour += self.minute // 60
            self.minute = self.minute % 60
        while self.minute < 0:
            self.hour -= 1
            self.minute += 60
        self.hour = self.hour % 24

    def add_minutes(self, minutes):
        self.minute += minutes
        self.normalize()

    def subtract_minutes(self, minutes):
        self.minute -= minutes
        self.normalize()

    def __eq__(self, other):
        return self.hour == other.hour and self.minute == other.minute

    def __str__(self):
        return f"{self.hour:02}:{self.minute:02}"

# Example usage
clock1 = Clock(14, 30)
clock2 = Clock(14, 30)
clock3 = Clock(10, 45)

clock1.add_minutes(90)
clock2.subtract_minutes(70)

print(clock1)  # Should print 16:00
print(clock2)  # Should print 13:20
print(clock3)  # Should print 10:45
print(clock1 == clock2)  # Should print False
print(clock1 == Clock(16, 0))  # Should print True