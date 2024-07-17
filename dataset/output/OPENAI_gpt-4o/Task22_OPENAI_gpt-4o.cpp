#include <iostream>
#include <vector>
#include <variant>
#include <string>

class Kata {
public:
    using Element = std::variant<int, std::string>;
    static std::vector<int> filterList(const std::vector<Element>& list) {
        std::vector<int> result;
        for (const auto& item : list) {
            if (std::holds_alternative<int>(item)) {
                result.push_back(std::get<int>(item));
            }
        }
        return result;
    }
};

int main() {
    using E = Kata::Element;
    
    auto printList = [](const std::vector<int>& list) {
        std::cout << "[";
        for (size_t i = 0; i < list.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << list[i];
        }
        std::cout << "]
";
    };
     
    printList(Kata::filterList({E(1), E(2), "a", "b"})); // [1, 2]
    printList(Kata::filterList({E(1), "a", "b", E(0), E(15)})); // [1, 0, 15]
    printList(Kata::filterList({E(1), E(2), "a", "b", "aasf", "1", "123", E(123)})); // [1, 2, 123]
    
    return 0;
}