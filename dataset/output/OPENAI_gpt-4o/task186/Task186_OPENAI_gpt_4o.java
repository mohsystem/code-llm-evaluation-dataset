// Java code for merging k sorted linked lists
import java.util.PriorityQueue;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Task186_OPENAI_gpt_4o {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (ListNode l : lists) {
            while (l != null) {
                heap.add(l.val);
                l = l.next;
            }
        }
        
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        while (!heap.isEmpty()) {
            curr.next = new ListNode(heap.poll());
            curr = curr.next;
        }
        
        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode[] lists = new ListNode[3];
        lists[0] = new ListNode(1, new ListNode(4, new ListNode(5)));
        lists[1] = new ListNode(1, new ListNode(3, new ListNode(4)));
        lists[2] = new ListNode(2, new ListNode(6));
        
        Task186_OPENAI_gpt_4o obj = new Task186_OPENAI_gpt_4o();
        ListNode merged = obj.mergeKLists(lists);
        printList(merged);
    }

    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
        System.out.println();
    }
}