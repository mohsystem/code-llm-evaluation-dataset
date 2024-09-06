public class Task199_OPENAI_gpt_4o {
    private int hour;
    private int minute;

    public Task199_OPENAI_gpt_4o(int hour, int minute) {
        this.hour = hour;
        this.minute = minute;
        normalize();
    }

    private void normalize() {
        if (minute >= 60) {
            hour += minute / 60;
            minute = minute % 60;
        }
        while (minute < 0) {
            hour -= 1;
            minute += 60;
        }
        hour = hour % 24;
    }

    public void addMinutes(int minutes) {
        minute += minutes;
        normalize();
    }

    public void subtractMinutes(int minutes) {
        minute -= minutes;
        normalize();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Task199_OPENAI_gpt_4o clock = (Task199_OPENAI_gpt_4o) obj;
        return hour == clock.hour && minute == clock.minute;
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d", hour, minute);
    }

    public static void main(String[] args) {
        Task199_OPENAI_gpt_4o clock1 = new Task199_OPENAI_gpt_4o(14, 30);
        Task199_OPENAI_gpt_4o clock2 = new Task199_OPENAI_gpt_4o(14, 30);
        Task199_OPENAI_gpt_4o clock3 = new Task199_OPENAI_gpt_4o(10, 45);

        clock1.addMinutes(90);
        clock2.subtractMinutes(70);

        System.out.println(clock1);  // Should print 16:00
        System.out.println(clock2);  // Should print 13:20
        System.out.println(clock3);  // Should print 10:45
        System.out.println(clock1.equals(clock2));  // Should print false
        System.out.println(clock1.equals(new Task199_OPENAI_gpt_4o(16, 0)));  // Should print true
    }
}