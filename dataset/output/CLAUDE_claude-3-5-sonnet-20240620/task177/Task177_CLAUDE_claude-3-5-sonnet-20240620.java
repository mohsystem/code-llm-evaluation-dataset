
class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>();
        for (int i = 0; i < nums.length; i++) {
            if (!dq.isEmpty()) {
                nums[i] += dq.peekFirst();
            }
            while (!dq.isEmpty() && dq.peekLast() < nums[i]) {
                dq.pollLast();
            }
            if (nums[i] > 0) {
                dq.offerLast(nums[i]);
            }
            if (i >= k && !dq.isEmpty() && dq.peekFirst() == nums[i - k]) {
                dq.pollFirst();
            }
        }
        return Arrays.stream(nums).max().getAsInt();
    }
}
