
class Clock:
    def __init__(self, hours, minutes):
        self.minutes = (hours * 60 + minutes) % 1440

    def __repr__(self):
        hours, minutes = divmod(self.minutes, 60)
        return f"{hours:02d}:{minutes:02d}"

    def __eq__(self, other):
        return self.minutes == other.minutes

    def add(self, minutes):
        self.minutes = (self.minutes + minutes) % 1440
        return self

    def subtract(self, minutes):
        self.minutes = (self.minutes - minutes) % 1440
        return self

# Example usage
clock1 = Clock(10, 30)
clock2 = Clock(10, 30)
print(clock1)  # 10:30
print(clock1 == clock2)  # True
clock1.add(30)
print(clock1)  # 11:00
clock1.subtract(60)
print(clock1)  # 10:00
