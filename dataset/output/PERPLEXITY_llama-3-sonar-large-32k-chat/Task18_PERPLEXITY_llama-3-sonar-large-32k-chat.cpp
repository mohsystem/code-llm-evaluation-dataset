#include <vector>
#include <string>

int binaryArrayToNumber(std::vector<int> arr) {
    std::string binaryString = "";
    for (int i : arr) {
        binaryString += std::to_string(i);
    }
    return std::stoi(binaryString, 0, 2);
}