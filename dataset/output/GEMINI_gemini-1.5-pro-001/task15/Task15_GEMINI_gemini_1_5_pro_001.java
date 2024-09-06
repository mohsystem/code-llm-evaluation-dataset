public class Task15_GEMINI_gemini_1_5_pro_001 {
  public static String[] towerBuilder(int nFloors) {
    String[] tower = new String[nFloors];
    for (int i = 0; i < nFloors; i++) {
      String stars = "*".repeat(2 * i + 1);
      String spaces = " ".repeat(nFloors - i - 1);
      tower[i] = spaces + stars + spaces;
    }
    return tower;
  }
}