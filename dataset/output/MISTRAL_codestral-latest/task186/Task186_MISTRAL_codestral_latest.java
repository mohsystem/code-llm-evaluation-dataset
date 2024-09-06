// Java
/*
 * Definition for singly-linked list.
 * public class Task186_MISTRAL_codestral_latest {
 *     int val;
 *     Task186_MISTRAL_codestral_latest next;
 *     Task186_MISTRAL_codestral_latest() {}
 *     Task186_MISTRAL_codestral_latest(int val) { this.val = val; }
 *     Task186_MISTRAL_codestral_latest(int val, Task186_MISTRAL_codestral_latest next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public Task186_MISTRAL_codestral_latest mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;
        PriorityQueue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt(a -> a.val));
        Task186_MISTRAL_codestral_latest dummy = new Task186_MISTRAL_codestral_latest(0);
        Task186_MISTRAL_codestral_latest curr = dummy;
        for (ListNode node : lists) {
            if (node != null) {
                queue.add(node);
            }
        }
        while (!queue.isEmpty()) {
            curr.next = queue.poll();
            curr = curr.next;
            if (curr.next != null) {
                queue.add(curr.next);
            }
        }
        return dummy.next;
    }
}