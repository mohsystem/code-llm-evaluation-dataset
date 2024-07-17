public class Main {
    public static boolean checkFlush(String[] table, String[] hand) {
        int[] suits = new int[4];
        for (String card : table) {
            char suit = card.charAt(card.length() - 1);
            switch (suit) {
                case 'S':
                    suits[0]++;
                    break;
                case 'H':
                    suits[1]++;
                    break;
                case 'D':
                    suits[2]++;
                    break;
                case 'C':
                    suits[3]++;
                    break;
            }
        }
        for (String card : hand) {
            char suit = card.charAt(card.length() - 1);
            switch (suit) {
                case 'S':
                    suits[0]++;
                    break;
                case 'H':
                    suits[1]++;
                    break;
                case 'D':
                    suits[2]++;
                    break;
                case 'C':
                    suits[3]++;
                    break;
            }
        }
        for (int suit : suits) {
            if (suit >= 5) {
                return true;
            }
        }
        return false;
    }
}