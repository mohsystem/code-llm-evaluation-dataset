public class Task75_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task75_MISTRAL_codestral_latest <PID>");
            System.exit(1);
        }

        int pid = Integer.parseInt(args[0]);
        Process process = null;
        try {
            process = Runtime.getRuntime().exec("kill -9 " + pid);
            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}