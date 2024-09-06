public class Task199_MISTRAL_codestral_latest {
    private int minutes;

    public Task199_MISTRAL_codestral_latest(int hours, int minutes) {
        this.minutes = (hours * 60 + minutes) % (24 * 60);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Task199_MISTRAL_codestral_latest clock = (Task199_MISTRAL_codestral_latest) obj;
        return minutes == clock.minutes;
    }

    public Task199_MISTRAL_codestral_latest add(int minutes) {
        return new Task199_MISTRAL_codestral_latest(0, this.minutes + minutes);
    }

    public Task199_MISTRAL_codestral_latest subtract(int minutes) {
        return new Task199_MISTRAL_codestral_latest(0, this.minutes - minutes);
    }

    @Override
    public String toString() {
        int hours = minutes / 60;
        minutes = minutes % 60;
        return String.format("%02d:%02d", hours, minutes);
    }
}