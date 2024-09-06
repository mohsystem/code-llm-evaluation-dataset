class Clock {
    private int minutes;

    public Clock(int hour, int minute) {
        this.minutes = (minute + hour * 60) % (24 * 60);
        if (this.minutes < 0) {
            this.minutes += 24 * 60;
        }
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d", minutes / 60, minutes % 60);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Clock clock = (Clock) obj;
        return minutes == clock.minutes;
    }

    public Clock add(int minutes) {
        return new Clock(0, this.minutes + minutes);
    }

    public Clock subtract(int minutes) {
        return new Clock(0, this.minutes - minutes);
    }
}