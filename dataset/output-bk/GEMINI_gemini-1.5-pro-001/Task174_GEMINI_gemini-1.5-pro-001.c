char * shortestPalindrome(char * s){
    int n = strlen(s);
    long long base = 26, mod = 1e9 + 7;
    long long hashVal = 0, powBase = 1;
    int best = 0;
    for (int i = n - 1; i >= 0; --i) {
        hashVal = (hashVal * base + (s[i] - 'a')) % mod;
        if (hashVal == ((s[i] - 'a') * powBase) % mod) {
            best = i;
        }
        powBase = (powBase * base) % mod;
    }
    char *add = (char *)malloc((n - best) * sizeof(char));
    for (int i = best + 1, j = 0; i < n; ++i, ++j) {
        add[j] = s[i];
    }
    add[n - best - 1] = '\0';
    for (int i = 0, j = n - best - 2; i < j; ++i, --j) {
        char temp = add[i];
        add[i] = add[j];
        add[j] = temp;
    }
    char *res = (char *)malloc((2 * n - best) * sizeof(char));
    strcpy(res, add);
    strcat(res, s);
    return res;
}