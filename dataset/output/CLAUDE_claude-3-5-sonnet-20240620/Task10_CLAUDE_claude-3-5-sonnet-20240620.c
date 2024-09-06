
int getSum(int a, int b) {
    if (a == b) {
        return a;
    }
    int start = (a < b) ? a : b;
    int end = (a > b) ? a : b;
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}
