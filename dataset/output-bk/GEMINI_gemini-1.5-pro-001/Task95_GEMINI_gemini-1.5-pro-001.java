import java.lang.management.ManagementFactory;
import java.lang.management.OperatingSystemMXBean;

public class GetCpuTime {
    public static void main(String[] args) {
        OperatingSystemMXBean osBean = ManagementFactory.getOperatingSystemMXBean();
        long nanoseconds = osBean.getProcessCpuTime();
        double seconds = nanoseconds / 1_000_000_000.0;
        System.out.println(seconds);
    }
}