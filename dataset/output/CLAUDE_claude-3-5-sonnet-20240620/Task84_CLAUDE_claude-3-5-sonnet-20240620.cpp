
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

std::string generate_session_id() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');

    for (int i = 0; i < 32; ++i) {
        ss << std::setw(1) << dis(gen);
        if (i == 7 || i == 11 || i == 15 || i == 19) {
            ss << "-";
        }
    }

    return ss.str();
}

int main() {
    std::string session_id = generate_session_id();
    std::cout << session_id << std::endl;
    return 0;
}
