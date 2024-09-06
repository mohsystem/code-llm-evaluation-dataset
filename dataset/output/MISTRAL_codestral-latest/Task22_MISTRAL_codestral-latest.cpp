#include <vector>
#include <typeinfo>

std::vector<int> filter_list(const std::vector<boost::variant<int, std::string>>& list) {
    std::vector<int> result;
    for (const auto& i : list) {
        if (i.type() == typeid(int)) {
            result.push_back(boost::get<int>(i));
        }
    }
    return result;
}