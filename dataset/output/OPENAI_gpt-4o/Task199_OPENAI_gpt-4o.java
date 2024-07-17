import java.util.Objects;

public class Clock {
    private int hour;
    private int minute;

    public Clock(int hour, int minute) {
        int totalMinutes = (hour * 60 + minute) % (24 * 60);
        this.hour = totalMinutes / 60;
        this.minute = totalMinutes % 60;
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d", this.hour, this.minute);
    }

    public Clock addMinutes(int minutes) {
        return new Clock(this.hour, this.minute + minutes);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Clock clock = (Clock) o;
        return hour == clock.hour && minute == clock.minute;
    }

    @Override
    public int hashCode() {
        return Objects.hash(hour, minute);
    }

    public static void main(String[] args) {
        Clock clock1 = new Clock(10, 30);
        Clock clock2 = clock1.addMinutes(35);
        Clock clock3 = new Clock(11, 5);
        System.out.println(clock2);  // 11:05
        System.out.println(clock2.equals(clock3));  // True
    }
}