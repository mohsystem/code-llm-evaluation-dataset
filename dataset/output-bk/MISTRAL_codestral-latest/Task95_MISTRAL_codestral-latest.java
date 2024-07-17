// Java
import java.lang.management.ManagementFactory;
import java.lang.management.ThreadMXBean;

public class Main {
    public static void main(String[] args) {
        ThreadMXBean bean = ManagementFactory.getThreadMXBean();
        long time = bean.getCurrentThreadCpuTime() / 1000000000;
        System.out.println("Current processor time: " + time + " seconds");
    }
}