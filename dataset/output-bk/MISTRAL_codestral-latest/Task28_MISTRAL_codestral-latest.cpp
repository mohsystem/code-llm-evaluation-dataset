#include <iostream>
#include <vector>
#include <string>

std::string likes(std::vector<std::string> names) {
    int n = names.size();
    if (n == 0) {
        return "no one likes this";
    } else if (n == 1) {
        return names[0] + " likes this";
    } else if (n == 2) {
        return names[0] + " and " + names[1] + " like this";
    } else if (n == 3) {
        return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    } else {
        return names[0] + ", " + names[1] + " and " + std::to_string(n-2) + " others like this";
    }
}