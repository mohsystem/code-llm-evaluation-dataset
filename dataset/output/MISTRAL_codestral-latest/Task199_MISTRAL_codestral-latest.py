class Clock:
    def __init__(self, hours, minutes):
        self.minutes = (hours * 60 + minutes) % (24 * 60)

    def __eq__(self, other):
        return self.minutes == other.minutes

    def __add__(self, minutes):
        return Clock(0, self.minutes + minutes)

    def __sub__(self, minutes):
        return Clock(0, self.minutes - minutes)

    def __str__(self):
        hours = self.minutes // 60
        minutes = self.minutes % 60
        return f'{hours:02d}:{minutes:02d}'