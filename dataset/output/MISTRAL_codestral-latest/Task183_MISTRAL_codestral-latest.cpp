#include <string>
#include <algorithm>
using namespace std;

int maxProduct(string input, int span) {
    int maxProd = 0;
    for (int i = 0; i <= input.length() - span; i++) {
        int prod = 1;
        for (int j = i; j < i + span; j++) {
            prod *= input[j] - '0';
        }
        maxProd = max(maxProd, prod);
    }
    return maxProd;
}