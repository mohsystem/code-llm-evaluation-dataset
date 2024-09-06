#include <string>
#include <algorithm>
using namespace std;

int maxProduct(string input, int span) {
    int maxProd = 0;
    for (int i = 0; i <= input.length() - span; i++) {
        string series = input.substr(i, span);
        int product = 1;
        for (char digit : series) {
            product *= digit - '0';
        }
        maxProd = max(maxProd, product);
    }
    return maxProd;
}