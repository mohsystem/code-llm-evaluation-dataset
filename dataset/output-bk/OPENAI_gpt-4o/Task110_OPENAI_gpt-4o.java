import java.util.regex.*;

public class URLValidator {
    public static void main(String[] args) {
        String[] urls = {
            "http://example.com",
            "https://www.example.com",
            "ftp://example.com",
            "invalidurl.com"
        };

        for (String url : urls) {
            System.out.println(url + " is " + (isValidURL(url) ? "valid" : "invalid"));
        }
    }

    public static boolean isValidURL(String url) {
        String regex = "^(http|https|ftp)://[^\\s/$.?#].[^\\s]*$";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(url);
        return matcher.matches();
    }
}

class CValidator {
    public static void main(String[] args) {
        String[] urls = {
            "http://example.com",
            "https://www.example.com",
            "ftp://example.com",
            "invalidurl.com"
        };

        for (String url : urls) {
            boolean isValid = CValidator.isValidURL(url);
            System.out.println(url + " is " + (isValid ? "valid" : "invalid"));
        }
    }

    public static boolean isValidURL(String url) {
        return Pattern.matches("^(http|https|ftp)://[^\\s/$.?#].[^\\s]*$", url);
    }
}

class CPPValidator {
    public static void main(String[] args) {
        String[] urls = {
            "http://example.com",
            "https://www.example.com",
            "ftp://example.com",
            "invalidurl.com"
        };

        for (String url : urls) {
            boolean isValid = CPPValidator.isValidURL(url);
            System.out.println(url + " is " + (isValid ? "valid" : "invalid"));
        }
    }

    public static boolean isValidURL(String url) {
        return Pattern.matches("^(http|https|ftp)://[^\\s/$.?#].[^\\s]*$", url);
    }
}

class PythonValidator {
    public static void main(String[] args) {
        String[] urls = {
            "http://example.com",
            "https://www.example.com",
            "ftp://example.com",
            "invalidurl.com"
        };

        for (String url : urls) {
            boolean isValid = PythonValidator.isValidURL(url);
            System.out.println(url + " is " + (isValid ? "valid" : "invalid"));
        }
    }

    public static boolean isValidURL(String url) {
        String urlRegex = "^(http|https|ftp)://[^\\s/$.?#].[^\\s]*$";
        return url.matches(urlRegex);
    }
}