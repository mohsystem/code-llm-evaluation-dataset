import java.util.Arrays;

class TowerBuilder {
    public static String[] buildTower(int nFloors) {
        String[] tower = new String[nFloors];
        for (int i = 1; i <= nFloors; i++) {
            String padding = " ".repeat(nFloors - i);
            String stars = "*".repeat(2 * i - 1);
            tower[i - 1] = padding + stars + padding;
        }
        return tower;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(buildTower(6)));
    }
}