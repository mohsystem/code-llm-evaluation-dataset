// C++
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <openssl/sha.h>

std::string hashPassword(const std::string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.length());
    SHA256_Final(hash, &sha256);

    std::string hashedPassword;
    char buffer[3];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(buffer, "%02x", hash[i]);
        hashedPassword.append(buffer);
    }
    return hashedPassword;
}

void updatePasswordInDatabase(MYSQL *conn, const std::string &username, const std::string &hashedPassword) {
    std::string query = "UPDATE users SET password = '" + hashedPassword + "' WHERE username = '" + username + "'";
    mysql_query(conn, query.c_str());
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "mydatabase", 0, NULL, 0)) {
        std::cerr << mysql_error(conn) << std::endl;
        exit(1);
    }

    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter new password: ";
    std::cin >> password;

    std::string hashedPassword = hashPassword(password);

    updatePasswordInDatabase(conn, username, hashedPassword);

    mysql_close(conn);
    return 0;
}