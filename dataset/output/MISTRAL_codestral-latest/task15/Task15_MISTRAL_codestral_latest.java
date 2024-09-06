import java.util.ArrayList;
import java.util.List;

public class Task15_MISTRAL_codestral_latest {
    public static List<String> buildTower(int nFloors) {
        List<String> tower = new ArrayList<>();
        for (int i = 0; i < nFloors; i++) {
            tower.add(" ".repeat(nFloors - i - 1) + "*".repeat(2 * i + 1) + " ".repeat(nFloors - i - 1));
        }
        return tower;
    }
}