import java.util.Random;
public class Main {
    public static void main(String[] args) {
        System.out.println("Java Session ID: " + generateSessionId());
        
        // C Code
        String cCode = "
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSessionIdC(char *sessionID, int length) {
    const char charset[] = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        sessionID[i] = charset[key];
    }
    sessionID[length] = '\\0';
}

int main() {
    char sessionID[17];
    srand(time(0));
    generateSessionIdC(sessionID, 16);
    printf(\"C Session ID: %s\
\", sessionID);
    return 0;
}
";
        System.out.println(cCode);

        // C++ Code
        String cppCode = "
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string generateSessionIdCPP(int length) {
    const char charset[] = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\";
    std::string result;
    result.resize(length);
    for (int i = 0; i < length; i++) {
        int key = rand() % (sizeof(charset) - 1);
        result[i] = charset[key];
    }
    return result;
}

int main() {
    srand(time(0));
    std::cout << \"C++ Session ID: \" << generateSessionIdCPP(16) << std::endl;
    return 0;
}
";
        System.out.println(cppCode);

        // Python Code
        String pythonCode = "
import random
import string

 def generate_session_id(length=16):
     characters = string.ascii_letters + string.digits
     return ''.join(random.choice(characters) for i in range(length))

if __name__ == \"__main__\":
     print(f\"Python Session ID: {generate_session_id()}\")
";
        System.out.println(pythonCode);
    }

    public static String generateSessionId() {
        String charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        StringBuilder sessionId = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < 16; i++) {
            int index = random.nextInt(charset.length());
            sessionId.append(charset.charAt(index));
        }
        return sessionId.toString();
    }
}