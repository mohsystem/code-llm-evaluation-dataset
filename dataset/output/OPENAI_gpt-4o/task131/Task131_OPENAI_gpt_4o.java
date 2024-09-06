import java.io.*;
import java.util.*;

public class Task131_OPENAI_gpt_4o {
    public static void main(String[] args) {
        try {
            FileInputStream fileInputStream = new FileInputStream("userData.ser");
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
            Object userData = objectInputStream.readObject();
            objectInputStream.close();
            fileInputStream.close();
            System.out.println(userData);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}