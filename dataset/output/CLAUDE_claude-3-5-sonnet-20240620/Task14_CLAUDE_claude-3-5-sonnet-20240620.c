
int findEvenIndex(const int *arr, int length) {
    int leftSum = 0;
    int rightSum = 0;
    int i;

    for (i = 0; i < length; i++) {
        rightSum += arr[i];
    }

    for (i = 0; i < length; i++) {
        rightSum -= arr[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += arr[i];
    }

    return -1;
}
