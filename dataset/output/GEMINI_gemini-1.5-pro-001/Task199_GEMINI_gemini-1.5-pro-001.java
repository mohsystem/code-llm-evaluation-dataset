class Clock {
    private int minutes;

    public Clock(int hour, int minute) {
        this.minutes = ((minute + hour * 60) % (24 * 60) + (24 * 60)) % (24 * 60);
    }

    public int getHour() {
        return minutes / 60;
    }

    public int getMinute() {
        return minutes % 60;
    }

    public Clock add(int minutes) {
        return new Clock(0, (this.minutes + minutes) % (24 * 60));
    }

    public Clock subtract(int minutes) {
        return add(-minutes);
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d", getHour(), getMinute());
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Clock clock = (Clock) obj;
        return minutes == clock.minutes;
    }
}