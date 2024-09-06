public class Task15_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String[] towerBuilder(int nFloors) {
        String[] tower = new String[nFloors];
        for (int i = 0; i < nFloors; i++) {
            tower[i] = String.format("%" + (nFloors - i - 1) + "s%" + (2 * i + 1) + "s%" + (nFloors - i - 1) + "s", "", String.valueOf(new char[2 * i + 1]).replace("\0", "*"), "");
        }
        return tower;
    }
}