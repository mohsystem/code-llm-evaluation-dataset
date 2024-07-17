#include <vector>
#include <iostream>

std::vector<int> filterList(std::vector<void*> list) {
    std::vector<int> newList;
    for (void* obj : list) {
        if (dynamic_cast<int*>(obj)) {
            newList.push_back(*(int*)obj);
        }
    }
    return newList;
}