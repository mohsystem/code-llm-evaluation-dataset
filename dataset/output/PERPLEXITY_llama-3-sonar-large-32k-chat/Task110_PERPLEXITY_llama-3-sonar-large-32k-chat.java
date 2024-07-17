import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

public class URLValidator {
    private static final String URL_REGEX = 
            "^((https?|ftp|file)://)?(-\\w+\\.){1,}(com|org|net|gov|mil|biz|info|mobi|name|aero|jobs|edu|co\\.uk|ac\\.uk|gov\\.uk|mil\\.uk|nhs\\.uk|police\\.uk|mod\\.uk|travel|local|me\\.uk|ltd\\.uk|plc\\.uk|net\\.uk|sch\\.uk)(:\\d+)?(/([\\w\\-\\.\\?\\,\\\\\\+&%*#=]*)?)?$";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a URL:");
        String url = scanner.nextLine();
        Pattern pattern = Pattern.compile(URL_REGEX);
        Matcher matcher = pattern.matcher(url);
        if (matcher.matches()) {
            System.out.println("URL is valid");
        } else {
            System.out.println("URL is not valid");
        }
    }
}