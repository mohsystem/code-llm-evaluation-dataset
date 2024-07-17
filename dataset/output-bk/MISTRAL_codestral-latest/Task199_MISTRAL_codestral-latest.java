public class Clock {
    private int minutes;

    public Clock(int hours, int minutes) {
        this.minutes = (hours * 60 + minutes) % (24 * 60);
    }

    public boolean equals(Clock other) {
        return this.minutes == other.minutes;
    }

    public Clock add(int minutes) {
        return new Clock(0, this.minutes + minutes);
    }

    public Clock subtract(int minutes) {
        return new Clock(0, this.minutes - minutes);
    }

    @Override
    public String toString() {
        int hours = this.minutes / 60;
        int minutes = this.minutes % 60;
        return String.format("%02d:%02d", hours, minutes);
    }
}