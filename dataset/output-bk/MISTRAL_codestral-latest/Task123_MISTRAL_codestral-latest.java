// Java
public class Session {
    private int userId;
    private boolean isActive;

    public Session(int userId) {
        this.userId = userId;
        this.isActive = true;
    }

    public void endSession() {
        this.isActive = false;
    }

    // Usage
    public static void main(String[] args) {
        Session userSession = new Session(123);
        System.out.println(userSession.isActive);  // true
        userSession.endSession();
        System.out.println(userSession.isActive);  // false
    }
}