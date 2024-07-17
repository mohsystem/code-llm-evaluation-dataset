#include <iostream>
#include <unordered_map>
#include <string>
#include <openssl/sha.h>

void hashPassword(const std::string &password, std::string &hashedPassword) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    hashedPassword = oss.str();
}

class UserAuthenticationSystem {
public:
    void registerUser() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        std::string hashedPassword;
        hashPassword(password, hashedPassword);

        users[username] = hashedPassword;
        std::cout << "User registered successfully!" << std::endl;
    }

    void loginUser() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        std::string hashedPassword;
        hashPassword(password, hashedPassword);

        if (users.find(username) != users.end() && users[username] == hashedPassword) {
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Invalid credentials." << std::endl;
        }
    }

    void run() {
        while (true) {
            int choice;
            std::cout << "1. Register
2. Login
3. Exit
";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    loginUser();
                    break;
                case 3:
                    return;
            }
        }
    }

private:
    std::unordered_map<std::string, std::string> users;
};

int main() {
    UserAuthenticationSystem uas;
    uas.run();
    return 0;
}