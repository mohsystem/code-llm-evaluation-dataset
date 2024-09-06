
public class Task199_CLAUDE_claude_3_5_sonnet_20240620 {
    private int minutes;

    public Task199_CLAUDE_claude_3_5_sonnet_20240620(int hour, int minute) {
        this.minutes = (hour * 60 + minute) % 1440;
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
            Task199_CLAUDE_claude_3_5_sonnet_20240620 other = (Task199_CLAUDE_claude_3_5_sonnet_20240620) obj;
            return this.minutes == other.minutes;
        }
        return false;
    }

    public Task199_CLAUDE_claude_3_5_sonnet_20240620 add(int minutes) {
        this.minutes = (this.minutes + minutes) % 1440;
        return this;
    }

    public Task199_CLAUDE_claude_3_5_sonnet_20240620 subtract(int minutes) {
        this.minutes = (this.minutes - minutes + 1440) % 1440;
        return this;
    }

    public static void main(String[] args) {
        Task199_CLAUDE_claude_3_5_sonnet_20240620 clock = new Task199_CLAUDE_claude_3_5_sonnet_20240620(10, 30);
        System.out.println(clock);  // 10:30
        clock.add(60);
        System.out.println(clock);  // 11:30
        clock.subtract(90);
        System.out.println(clock);  // 10:00
        System.out.println(clock.equals(new Task199_CLAUDE_claude_3_5_sonnet_20240620(10, 0)));  // true
    }
}
