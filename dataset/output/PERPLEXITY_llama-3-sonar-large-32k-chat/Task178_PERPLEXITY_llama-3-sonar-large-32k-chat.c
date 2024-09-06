// Note: C does not have a built-in deque data structure, so we can use a simple array to simulate a queue.
int shortestSubarray(int* nums, int numsSize, int k) {
    int n = numsSize;
    int prefixSum[n + 1];
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    int res = n + 1;
    int queue[n + 1];
    int front = 0, rear = 0;
    for (int i = 0; i <= n; i++) {
        while (front < rear && prefixSum[i] - prefixSum[queue[front]] >= k) {
            res = res < i - queue[front] ? res : i - queue[front];
            front++;
        }
        while (front < rear && prefixSum[i] <= prefixSum[queue[rear - 1]]) {
            rear--;
        }
        queue[rear++] = i;
    }
    return res <= n ? res : -1;
}