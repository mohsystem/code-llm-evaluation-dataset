#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> remove_smallest(std::vector<int> numbers) {
    if (numbers.empty()) return numbers;
    std::vector<int> result = numbers;
    auto min_iter = std::min_element(result.begin(), result.end());
    result.erase(min_iter);
    return result;
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {5, 3, 2, 1, 4};
    std::vector<int> vec3 = {2, 2, 1, 2, 1};
    
    auto res1 = remove_smallest(vec1);
    auto res2 = remove_smallest(vec2);
    auto res3 = remove_smallest(vec3);
    
    for (int n : res1) std::cout << n << " ";
    std::cout << std::endl;
    for (int n : res2) std::cout << n << " ";
    std::cout << std::endl;
    for (int n : res3) std::cout << n << " ";
    std::cout << std::endl;
    
    return 0;
}