// CPP

#include <iostream>
#include <vector>
#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password) : username(username), password(password) {}

    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }
};

class Authentication {
private:
    std::vector<User> users;

public:
    void registerUser(std::string username, std::string password) {
        User newUser(username, password);
        users.push_back(newUser);
        std::cout << "User registered successfully." << std::endl;
    }

    void login(std::string username, std::string password) {
        for (const User& user : users) {
            if (user.getUsername() == username && user.getPassword() == password) {
                std::cout << "Login successful." << std::endl;
                return;
            }
        }
        std::cout << "Invalid username or password." << std::endl;
    }
};

int main() {
    Authentication auth;
    auth.registerUser("user1", "password1");
    auth.login("user1", "password1");
    return 0;
}