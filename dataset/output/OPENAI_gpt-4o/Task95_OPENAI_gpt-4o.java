import java.lang.management.ManagementFactory;
import java.lang.management.OperatingSystemMXBean;

public class ProcessorTimeExample {
    public static void main(String[] args) {
        OperatingSystemMXBean osBean = ManagementFactory.getOperatingSystemMXBean();
        long cpuTime = ((com.sun.management.OperatingSystemMXBean) osBean).getProcessCpuTime();
        double cpuTimeInSeconds = cpuTime / 1_000_000_000.0;
        System.out.println("CPU time in seconds (Java): " + cpuTimeInSeconds);
    }
}