#include <vector>
#include <iostream>

std::vector<int> filterList(std::vector<Object> list) {
    std::vector<int> result;
    for (auto obj : list) {
        if (typeid(obj) == typeid(int)) {
            result.push_back(obj);
        }
    }
    return result;
}