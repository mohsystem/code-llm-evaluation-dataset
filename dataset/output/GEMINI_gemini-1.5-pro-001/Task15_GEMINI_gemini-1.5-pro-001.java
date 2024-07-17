class Kata {

  public static String[] towerBuilder(int nFloors) {
    String[] tower = new String[nFloors];
    
    for (int i = 0; i < nFloors; i++) {
      int stars = 2 * i + 1;
      int spaces = nFloors - i - 1;
      
      tower[i] = " ".repeat(spaces) + "*".repeat(stars) + " ".repeat(spaces);
    }

    return tower;
  }
}