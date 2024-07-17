
#include <iostream>
#include <string>
#include <random>
#include <chrono>

class RandomStringGenerator {
private:
    static const std::string ALPHABET;
    static std::mt19937 rng;

public:
    static std::string generateRandomString(int length) {
        std::uniform_int_distribution<int> dist(0, ALPHABET.length() - 1);
        std::string result;
        result.reserve(length);

        for (int i = 0; i < length; ++i) {
            result += ALPHABET[dist(rng)];
        }

        return result;
    }
};

const std::string RandomStringGenerator::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
std::mt19937 RandomStringGenerator::rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int length = 10;
    std::string randomString = RandomStringGenerator::generateRandomString(length);
    std::cout << "Random string: " << randomString << std::endl;
    return 0;
}
