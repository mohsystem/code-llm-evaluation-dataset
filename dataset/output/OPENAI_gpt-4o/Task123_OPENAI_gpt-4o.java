public class UserSession {
    private int userId;
    private boolean active;

    public UserSession(int userId) {
        this.userId = userId;
        this.active = true;
    }

    public void endSession() {
        this.active = false;
    }

    public int getUserId() {
        return userId;
    }

    public boolean isActive() {
        return active;
    }

    public static void main(String[] args) {
        UserSession session = new UserSession(1);
        System.out.println(session.getUserId());
        System.out.println(session.isActive());
        session.endSession();
        System.out.println(session.isActive());
    }
}