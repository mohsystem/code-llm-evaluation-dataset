public class PasswordStrengthChecker {

    public static boolean isValidPassword(String password) {
        if (password.length() < 8) return false;
        boolean hasUpperCase = false, hasLowerCase = false, hasDigit = false;
        
        for(char c : password.toCharArray()) {
            if (Character.isUpperCase(c)) hasUpperCase = true;
            if (Character.isLowerCase(c)) hasLowerCase = true;
            if (Character.isDigit(c)) hasDigit = true;
        }
        
        return hasUpperCase && hasLowerCase && hasDigit;
    }
    
    public static void main(String[] args) {
        String password = args[0];
        if(isValidPassword(password)) {
            System.out.println("Password is strong");
        } else {
            System.out.println("Password is weak");
        }
    }
}