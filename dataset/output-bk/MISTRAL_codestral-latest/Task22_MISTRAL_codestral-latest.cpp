#include <vector>
#include <typeinfo>

std::vector<int> filterList(const std::vector<std::variant<int, std::string>>& list) {
    std::vector<int> result;
    for (const auto& item : list) {
        if (std::holds_alternative<int>(item)) {
            result.push_back(std::get<int>(item));
        }
    }
    return result;
}