
public class Clock {
    private int minutes;

    public Clock(int hours, int minutes) {
        this.minutes = (hours * 60 + minutes) % 1440;
    }

    @Override
    public String toString() {
        int hours = minutes / 60;
        int mins = minutes % 60;
        return String.format("%02d:%02d", hours, mins);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Clock) {
            Clock other = (Clock) obj;
            return this.minutes == other.minutes;
        }
        return false;
    }

    public Clock add(int minutes) {
        this.minutes = (this.minutes + minutes) % 1440;
        return this;
    }

    public Clock subtract(int minutes) {
        this.minutes = (this.minutes - minutes + 1440) % 1440;
        return this;
    }

    public static void main(String[] args) {
        Clock clock1 = new Clock(10, 30);
        Clock clock2 = new Clock(10, 30);
        System.out.println(clock1);  // 10:30
        System.out.println(clock1.equals(clock2));  // true
        clock1.add(30);
        System.out.println(clock1);  // 11:00
        clock1.subtract(60);
        System.out.println(clock1);  // 10:00
    }
}
