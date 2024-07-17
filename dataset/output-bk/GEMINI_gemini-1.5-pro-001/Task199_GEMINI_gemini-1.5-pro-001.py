class Clock:
    def __init__(self, hour=0, minute=0):
        self.minute = (minute + hour * 60) % (24 * 60)

    def __repr__(self):
        return f"{self.__class__.__name__}({self.hour}, {self.minute % 60})"

    def __str__(self):
        return f"{self.hour:02d}:{self.minute % 60:02d}"

    def __eq__(self, other):
        if not isinstance(other, Clock):
            return NotImplemented
        return self.minute == other.minute

    @property
    def hour(self):
        return self.minute // 60

    def add(self, minutes):
        return Clock(minute=(self.minute + minutes) % (24 * 60))

    def subtract(self, minutes):
        return self.add(-minutes)