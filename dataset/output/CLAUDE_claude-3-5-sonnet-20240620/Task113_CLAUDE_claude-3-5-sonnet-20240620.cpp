
#include <iostream>
#include <string>

int main() {
    std::string result;
    std::string input;
    
    std::cout << "Enter strings to concatenate (type \'done\' to finish):" << std::endl;
    
    while (true) {
        std::getline(std::cin, input);
        
        if (input == "done") {
            break;
        }
        
        result += input;
    }
    
    std::cout << "Concatenated string: " << result << std::endl;
    
    return 0;
}
