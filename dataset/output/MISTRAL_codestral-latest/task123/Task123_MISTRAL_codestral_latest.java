// Java
public class Task123_MISTRAL_codestral_latest {
    private int userId;
    private boolean isActive;

    public Task123_MISTRAL_codestral_latest(int userId) {
        this.userId = userId;
        this.isActive = true;
    }

    public void endSession() {
        this.isActive = false;
    }
}

// Example usage:
Session userSession = new Task123_MISTRAL_codestral_latest(123);
// ... user interacts with the system ...
userSession.endSession();