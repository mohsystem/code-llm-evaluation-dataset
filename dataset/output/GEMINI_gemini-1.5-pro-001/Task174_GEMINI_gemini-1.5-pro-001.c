char * shortestPalindrome(char * s){
    int n = strlen(s);
    long long base = 26, mod = 1e9 + 7;
    long long hashVal = 0, powBase = 1;
    int best = 0;
    for (int i = n - 1; i >= 0; --i) {
        hashVal = (hashVal * base + (s[i] - 'a')) % mod;
        if (i == 0 || isPalindrome(s, 0, i)) {
            best = i + 1;
        }
    }
    char *res = (char *)malloc(sizeof(char) * (n + n - best + 1));
    int idx = 0;
    for (int i = n - best - 1; i >= 0; --i) {
        res[idx++] = s[i];
    }
    for (int i = 0; i < n; ++i) {
        res[idx++] = s[i];
    }
    res[idx] = '\0';
    return res;
}

bool isPalindrome(char *s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}