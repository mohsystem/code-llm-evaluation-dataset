class NarcissisticNumber {
    public static boolean isNarcissistic(int value) {
        String strValue = String.valueOf(value);
        int numDigits = strValue.length();
        int total = 0;
        for (int i = 0; i < numDigits; i++) {
            int digit = Integer.parseInt(String.valueOf(strValue.charAt(i)));
            total += Math.pow(digit, numDigits);
        }
        return total == value;
    }
}