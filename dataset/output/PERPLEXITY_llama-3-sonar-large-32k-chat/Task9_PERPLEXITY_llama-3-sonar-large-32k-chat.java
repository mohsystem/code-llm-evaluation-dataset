class Main {
    public static void main(String[] args) {
        int[] arr = {0, 1, 4};
        System.out.println(sumType(arr));
    }

    public static String sumType(int[] arr) {
        if (arr.length == 0) arr = new int[]{0};
        int sum = 0;
        for (int i : arr) sum += i;
        return sum % 2 == 0 ? "even" : "odd";
    }
}