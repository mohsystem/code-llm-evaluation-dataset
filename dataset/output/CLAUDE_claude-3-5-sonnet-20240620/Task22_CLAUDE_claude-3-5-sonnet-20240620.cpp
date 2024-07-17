
#include <iostream>
#include <vector>
#include <variant>
#include <string>

std::vector<int> filterList(const std::vector<std::variant<int, std::string>>& list) {
    std::vector<int> result;
    for (const auto& item : list) {
        if (std::holds_alternative<int>(item)) {
            result.push_back(std::get<int>(item));
        }
    }
    return result;
}

int main() {
    std::vector<std::variant<int, std::string>> list1 = {1, 2, "a", "b"};
    std::vector<std::variant<int, std::string>> list2 = {1, "a", "b", 0, 15};
    std::vector<std::variant<int, std::string>> list3 = {1, 2, "a", "b", "aasf", "1", "123", 123};

    auto printList = [](const std::vector<int>& list) {
        for (int item : list) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    };

    std::cout << "Filtered list 1: ";
    printList(filterList(list1));

    std::cout << "Filtered list 2: ";
    printList(filterList(list2));

    std::cout << "Filtered list 3: ";
    printList(filterList(list3));

    return 0;
}
