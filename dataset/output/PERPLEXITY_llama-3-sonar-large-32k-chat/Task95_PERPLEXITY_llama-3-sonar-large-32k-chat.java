import java.lang.management.ManagementFactory;
import java.lang.management.RuntimeMXBean;

public class Main {
    public static void main(String[] args) {
        RuntimeMXBean bean = ManagementFactory.getRuntimeMXBean();
        long uptime = bean.getUptime();
        System.out.println("Current processor time in seconds: " + uptime / 1000);
    }
}