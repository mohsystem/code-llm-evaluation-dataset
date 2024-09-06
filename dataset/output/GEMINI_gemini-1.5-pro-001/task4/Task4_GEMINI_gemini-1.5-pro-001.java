class Solution {
    public boolean isIsogram(String str) {
        if (str.length() == 0){
          return true;
        }
        str = str.toLowerCase();
        Set<Character> seen = new HashSet<>();
        for (char c : str.toCharArray()) {
            if (seen.contains(c)) {
                return false;
            }
            seen.add(c);
        }
        return true;
    }
}