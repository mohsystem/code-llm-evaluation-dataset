#include <iostream>
#include <unordered_map>
#include <vector>

double findUniq(const std::vector<double>& arr) {
    std::unordered_map<double, int> freq;
    for(double num : arr) freq[num]++;
    for(const auto& p : freq) if(p.second == 1) return p.first;
    return arr[0];
}

int main() {
    std::cout << findUniq({ 1, 1, 1, 2, 1, 1 }) << std::endl; // => 2
    std::cout << findUniq({ 0, 0, 0.55, 0, 0 }) << std::endl; // => 0.55
    return 0;
}