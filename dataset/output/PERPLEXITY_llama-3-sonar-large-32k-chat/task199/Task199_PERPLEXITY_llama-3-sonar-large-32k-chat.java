class Clock {
    int hours;
    int minutes;

    public Clock(int hours, int minutes) {
        this.hours = hours;
        this.minutes = minutes;
    }

    public void addMinutes(int minutes) {
        this.minutes += minutes;
        this.hours += this.minutes / 60;
        this.hours %= 24;
        this.minutes %= 60;
    }

    public void subtractMinutes(int minutes) {
        this.minutes -= minutes;
        if (this.minutes < 0) {
            this.hours -= 1;
            this.minutes += 60;
        }
        this.hours %= 24;
        this.minutes %= 60;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Clock clock = (Clock) obj;
        return hours == clock.hours && minutes == clock.minutes;
    }

    public static void main(String[] args) {
        Clock clock1 = new Clock(10, 30);
        Clock clock2 = new Clock(10, 30);
        System.out.println(clock1.equals(clock2));  // true

        clock1.addMinutes(30);
        System.out.println(clock1.hours + " " + clock1.minutes);  // 11 0

        clock1.subtractMinutes(60);
        System.out.println(clock1.hours + " " + clock1.minutes);  // 10 0
    }
}