
class Clock:
    def __init__(self, hour, minute):
        self.minutes = (hour * 60 + minute) % 1440

    def __repr__(self):
        hours, minutes = divmod(self.minutes, 60)
        return f"{hours:02d}:{minutes:02d}"

    def __eq__(self, other):
        return self.minutes == other.minutes

    def __add__(self, minutes):
        self.minutes = (self.minutes + minutes) % 1440
        return self

    def __sub__(self, minutes):
        self.minutes = (self.minutes - minutes) % 1440
        return self

# Example usage
clock = Clock(10, 30)
print(clock)  # 10:30
clock.add(60)
print(clock)  # 11:30
clock.sub(90)
print(clock)  # 10:00
print(clock == Clock(10, 0))  # True
