/**
 * Definition for singly-linked list.
 * public class Task186_GEMINI_gemini_1_5_pro_001 {
 *     int val;
 *     Task186_GEMINI_gemini_1_5_pro_001 next;
 *     Task186_GEMINI_gemini_1_5_pro_001() {}
 *     Task186_GEMINI_gemini_1_5_pro_001(int val) { this.val = val; }
 *     Task186_GEMINI_gemini_1_5_pro_001(int val, Task186_GEMINI_gemini_1_5_pro_001 next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public Task186_GEMINI_gemini_1_5_pro_001 mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (ListNode node : lists) {
            if (node != null) {
                minHeap.add(node);
            }
        }
        Task186_GEMINI_gemini_1_5_pro_001 dummy = new Task186_GEMINI_gemini_1_5_pro_001(-1);
        Task186_GEMINI_gemini_1_5_pro_001 cur = dummy;
        while (!minHeap.isEmpty()) {
            Task186_GEMINI_gemini_1_5_pro_001 node = minHeap.poll();
            cur.next = node;
            cur = cur.next;
            if (node.next != null) {
                minHeap.add(node.next);
            }
        }
        return dummy.next;
    }
}