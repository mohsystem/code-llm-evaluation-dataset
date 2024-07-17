class Solution {
    public static void main(String[] args) {
        System.out.println(validatePin("1234"));
        System.out.println(validatePin("12345"));
        System.out.println(validatePin("a234"));
    }
    public static boolean validatePin(String pin) {
        if(pin.length() != 4 && pin.length() != 6){
            return false;
        }
        for(int i = 0; i < pin.length(); i++){
            if(!Character.isDigit(pin.charAt(i))){
                return false;
            }
        }
        return true;
    }
}