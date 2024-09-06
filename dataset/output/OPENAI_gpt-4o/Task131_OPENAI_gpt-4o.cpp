#include <iostream>
#include <fstream>
#include <vector>

class UserData {
public:
    std::string data;
    friend std::ifstream& operator>>(std::ifstream& ifs, UserData& obj) {
        ifs >> obj.data;
        return ifs;
    }
    friend std::ostream& operator<<(std::ostream& os, const UserData& obj) {
        os << obj.data;
        return os;
    }
};

int main() {
    std::ifstream ifs("userData.dat");
    if (!ifs) {
        std::cerr << "Error opening file for reading\n";
        return 1;
    }
    UserData userData;
    ifs >> userData;
    ifs.close();
    std::cout << userData << std::endl;
    return 0;
}