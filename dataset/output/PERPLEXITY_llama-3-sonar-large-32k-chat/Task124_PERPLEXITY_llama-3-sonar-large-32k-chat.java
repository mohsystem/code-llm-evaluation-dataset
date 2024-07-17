public class SensitiveData {
    private String data;

    public SensitiveData(String data) {
        this.data = data;
    }

    public String getData() {
        return data;
    }

    public static void main(String[] args) {
        SensitiveData data = new SensitiveData("1234-5678-9012-3456");
        System.out.println(data.getData());
    }
}