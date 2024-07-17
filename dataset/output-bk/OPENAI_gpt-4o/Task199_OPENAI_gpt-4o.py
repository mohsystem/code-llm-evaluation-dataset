class Clock:
    def __init__(self, hour, minute):
        total_minutes = (hour * 60 + minute) % (24 * 60)
        self.hour = total_minutes // 60
        self.minute = total_minutes % 60

    def __repr__(self):
        return f"{self.hour:02}:{self.minute:02}"

    def add_minutes(self, minutes):
        return Clock(self.hour, self.minute + minutes)

    def __eq__(self, other):
        return self.hour == other.hour and self.minute == other.minute

if __name__ == "__main__":
    clock1 = Clock(10, 30)
    clock2 = clock1.add_minutes(35)
    clock3 = Clock(11, 5)
    print(clock2)  # 11:05
    print(clock2 == clock3)  # True