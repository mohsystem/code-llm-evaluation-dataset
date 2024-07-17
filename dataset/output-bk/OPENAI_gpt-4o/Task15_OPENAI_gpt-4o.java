class TowerGenerator {
    public static void main(String[] args) {
        buildTower(3);
        buildTower(6);
    }

    public static void buildTower(int nFloors) {
        for (int i = 0; i < nFloors; i++) {
            String floor = " ".repeat(nFloors - i - 1) +
                    "*".repeat(2 * i + 1) +
                    " ".repeat(nFloors - i - 1);
            System.out.println(floor);
        }
    }
}