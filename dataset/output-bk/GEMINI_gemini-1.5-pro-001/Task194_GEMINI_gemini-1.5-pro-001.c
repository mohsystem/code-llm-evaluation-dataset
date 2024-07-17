/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * struct Master {
 *     int (*guess)(struct Master *, char *word);
 * };
 */
void findSecretWord(char ** words, int wordsSize, struct Master * master) {
    int **H = (int **)malloc(wordsSize * sizeof(int *));
    for (int i = 0; i < wordsSize; ++i) {
        H[i] = (int *)malloc(wordsSize * sizeof(int));
    }
    for (int i = 0; i < wordsSize; ++i) {
        for (int j = i; j < wordsSize; ++j) {
            H[i][j] = H[j][i] = match(words[i], words[j]);
        }
    }

    int *possible = (int *)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; ++i) {
        possible[i] = i;
    }
    int possibleSize = wordsSize;
    int matches = 0;
    while (possibleSize > 0 && master->guess(master, words[possible[0]]) != 6) {
        int guess = rand() % possibleSize;
        matches = master->guess(master, words[possible[guess]]);
        int nextPossibleSize = 0;
        for (int i = 0; i < possibleSize; ++i) {
            if (H[possible[guess]][possible[i]] == matches) {
                possible[nextPossibleSize++] = possible[i];
            }
        }
        possibleSize = nextPossibleSize;
    }

    for (int i = 0; i < wordsSize; ++i) {
        free(H[i]);
    }
    free(H);
    free(possible);
}

int match(char *a, char *b) {
    int matches = 0;
    for (int i = 0; i < strlen(a); ++i) {
        if (a[i] == b[i]) {
            ++matches;
        }
    }
    return matches;
}