import java.io.*;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.core.JsonProcessingException;

class Main {
    public static void main(String[] args) {
        String jsonString = "{\"name\":\"John\", \"age\":30}";
        ObjectMapper objectMapper = new ObjectMapper();
        try {
            User user = objectMapper.readValue(jsonString, User.class);
            System.out.println("Name: " + user.name);
            System.out.println("Age: " + user.age);
        } catch (JsonProcessingException e) {
            e.printStackTrace();
        }
    }
}

class User {
    public String name;
    public int age;
}