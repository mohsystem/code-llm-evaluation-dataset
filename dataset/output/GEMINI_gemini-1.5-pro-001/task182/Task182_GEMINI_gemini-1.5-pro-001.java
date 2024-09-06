import java.util.regex.Pattern;

class PhoneNumberCleaner {
    public static String cleanPhoneNumber(String phoneNumber) {
        String cleanedNumber = phoneNumber.replaceAll("[^0-9]", "");
        if (cleanedNumber.length() == 11 && cleanedNumber.startsWith("1")) {
            return cleanedNumber.substring(1);
        }
        return (cleanedNumber.length() == 10) ? cleanedNumber : null;
    }

    public static void main(String[] args) {
        String[] phoneNumbers = {
                "+1 (613)-995-0253",
                "613-995-0253",
                "1 613 995 0253",
                "613.995.0253",
                "123456789012"  // Invalid phone number
        };

        for (String number : phoneNumbers) {
            String cleanedNumber = cleanPhoneNumber(number);
            if (cleanedNumber != null) {
                System.out.println("Original: " + number + " -> Cleaned: " + cleanedNumber);
            } else {
                System.out.println("Invalid phone number: " + number);
            }
        }
    }
}