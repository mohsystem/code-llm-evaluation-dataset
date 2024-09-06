
#include <math.h>

long long digPow(int n, int p) {
    long long sum = 0;
    int temp = n;
    int digits[10];
    int i = 0;
    
    while (temp > 0) {
        digits[i++] = temp % 10;
        temp /= 10;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        sum += pow(digits[j], p++);
    }
    
    return sum % n == 0 ? sum / n : -1;
}
