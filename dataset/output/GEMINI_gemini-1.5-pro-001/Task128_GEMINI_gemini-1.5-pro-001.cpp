#include <iostream>
#include <random>

int main() {
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 generator(rd());

    // Generate a random integer between 1 and 10
    std::uniform_int_distribution<int> intDistribution(1, 10);
    int randomInteger = intDistribution(generator);
    std::cout << "Random Integer: " << randomInteger << std::endl;

    // Generate a random floating-point number between 0 and 1
    std::uniform_real_distribution<double> doubleDistribution(0.0, 1.0);
    double randomDouble = doubleDistribution(generator);
    std::cout << "Random Double: " << randomDouble << std::endl;

    // Generate a random element from an array
    std::string fruits[] = {"apple", "banana", "cherry"};
    std::uniform_int_distribution<int> indexDistribution(0, 2);
    int randomIndex = indexDistribution(generator);
    std::string randomFruit = fruits[randomIndex];
    std::cout << "Random Fruit: " << randomFruit << std::endl;

    return 0;
}