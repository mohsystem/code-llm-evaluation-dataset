import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.util.Random;

public class Task88_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        try {
            File temp = File.createTempFile("temp", ".txt");
            String randomString = getRandomString();
            String unicodeString = toUnicode(randomString);
            FileWriter writer = new FileWriter(temp, StandardCharsets.UTF_8);
            writer.write(unicodeString);
            writer.close();
            System.out.println(temp.getAbsolutePath());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String getRandomString() {
        String SALTCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        StringBuilder salt = new StringBuilder();
        Random rnd = new Random();
        while (salt.length() < 10) {
            int index = (int) (rnd.nextFloat() * SALTCHARS.length());
            salt.append(SALTCHARS.charAt(index));
        }
        return salt.toString();
    }

    private static String toUnicode(String str) throws UnsupportedEncodingException {
        byte[] utf8Bytes = str.getBytes("UTF-8");
        StringBuilder unicodeString = new StringBuilder();
        for (byte b : utf8Bytes) {
            unicodeString.append("\\u").append(String.format("%04x", 0x000000ff & b));
        }
        return unicodeString.toString();
    }
}