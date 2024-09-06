#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <sqlite3.h>

using namespace std;

string hash_password(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (unsigned char i : hash) {
        ss << hex << setw(2) << setfill('0') << (int)i;
    }
    return ss.str();
}

int update_password(const string& username, const string& new_password) {
    string hashed_password = hash_password(new_password);
    sqlite3* db;
    char* err_msg = 0;
    int rc = sqlite3_open("users.db", &db);
    if (rc != SQLITE_OK) {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }
    string sql = "UPDATE user SET password = '" + hashed_password + "' WHERE username = '" + username + "';";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << err_msg << endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    sqlite3_close(db);
    cout << "Password updated successfully!" << endl;
    return 0;
}

int main() {
    string username, new_password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> new_password;
    update_password(username, new_password);
    return 0;
}