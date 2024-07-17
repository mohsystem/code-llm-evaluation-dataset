#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <mysql/mysql.h>

using namespace std;

string hashPassword(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    string hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashedPassword += to_string(static_cast<int>(hash[i]));
    }
    return hashedPassword;
}

int main() {
    string username, newPassword;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> newPassword;

    string hashedPassword = hashPassword(newPassword);

    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        cerr << mysql_error(con) << endl;
        return 1;
    }

    if (mysql_real_connect(con, "localhost", "your_database_user", "your_database_password", "your_database_name", 0, NULL, 0) == NULL) {
        cerr << mysql_error(con) << endl;
        mysql_close(con);
        return 1;
    }

    string query = "UPDATE users SET password = '" + hashedPassword + "' WHERE username = '" + username + "'";

    if (mysql_query(con, query.c_str())) {
        cerr << mysql_error(con) << endl;
        mysql_close(con);
        return 1;
    }

    cout << "Password updated successfully." << endl;

    mysql_close(con);
    return 0;
}