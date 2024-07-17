#include <iostream>
#include <string>
#include <unistd.h>
#include <shadow.h>
#include <pwd.h>

using namespace std;

void drop_privileges(uid_t user_uid, gid_t user_gid) {
    if (setgid(user_gid) != 0) {
        perror("setgid");
        exit(1);
    }
    if (setuid(user_uid) != 0) {
        perror("setuid");
        exit(1);
    }
}

int main() {
    if (geteuid() != 0) {
        cerr << "This program requires root privileges. Please run with sudo." << endl;
        return 1;
    }

    string username, password;

    cout << "Enter the username: ";
    cin >> username;

    cout << "Enter the new password: ";
    cin >> password;

    spwd *sp = getspnam(username.c_str());
    if (sp == nullptr) {
        cerr << "User '" << username << "' not found." << endl;
        return 1;
    }

    string encrypted_password = crypt(password.c_str(), "$6$salt$");
    if (encrypted_password == "") {
        perror("crypt");
        return 1;
    }

    sp->sp_pwdp = const_cast<char*>(encrypted_password.c_str());

    if (putspent(sp, SHADOW_WRITE) == -1) {
        perror("putspent");
        return 1;
    }

    cout << "Password for user '" << username << "' changed successfully." << endl;

    passwd* user = getpwnam(username.c_str());
    if (user == nullptr) {
        cerr << "Error getting user details." << endl;
        return 1;
    }

    drop_privileges(user->pw_uid, user->pw_gid);

    cout << "Running as user: " << getlogin() << endl;

    return 0;
}