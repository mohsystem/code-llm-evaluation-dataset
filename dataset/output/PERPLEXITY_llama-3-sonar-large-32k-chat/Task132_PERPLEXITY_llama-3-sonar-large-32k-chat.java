import java.util.ArrayList;
import java.util.Date;

class SecurityEvent {
    String eventType;
    String description;
    Date timestamp;

    public SecurityEvent(String eventType, String description) {
        this.eventType = eventType;
        this.description = description;
        this.timestamp = new Date();
    }

    public void logEvent() {
        System.out.println(timestamp + " - " + eventType + ": " + description);
    }
}

class SecurityMonitor {
    ArrayList<SecurityEvent> eventLog;

    public SecurityMonitor() {
        this.eventLog = new ArrayList<>();
    }

    public void logEvent(SecurityEvent event) {
        eventLog.add(event);
        event.logEvent();
    }

    public void monitorEvents() {
        for (SecurityEvent event : eventLog) {
            System.out.println("Monitoring: " + event.eventType + " - " + event.description);
        }
    }

    public static void main(String[] args) {
        SecurityMonitor monitor = new SecurityMonitor();
        monitor.logEvent(new SecurityEvent("Login Attempt", "User attempted to login"));
        monitor.logEvent(new SecurityEvent("File Access", "User accessed confidential file"));
        monitor.monitorEvents();
    }
}