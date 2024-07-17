import java.util.ArrayList;
import java.util.List;

public class TowerBuilder {
    public static List<String> buildTower(int nFloors) {
        List<String> tower = new ArrayList<>();
        for (int i = 0; i < nFloors; i++) {
            String floor = " ".repeat(nFloors - i - 1) + "*".repeat(2 * i + 1) + " ".repeat(nFloors - i - 1);
            tower.add(floor);
        }
        return tower;
    }
}