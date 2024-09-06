import java.util.LinkedList;
import java.util.Queue;

public class Task151_GEMINI_gemini_1_5_pro_001 {

  private Node root;

  public void insert(int data) {
    Node newNode = new Node(data);
    if (root == null) {
      root = newNode;
      return;
    }
    Node current = root;
    while (true) {
      if (data < current.data) {
        if (current.left == null) {
          current.left = newNode;
          return;
        }
        current = current.left;
      } else {
        if (current.right == null) {
          current.right = newNode;
          return;
        }
        current = current.right;
      }
    }
  }

  public boolean search(int data) {
    Node current = root;
    while (current != null) {
      if (data == current.data) {
        return true;
      } else if (data < current.data) {
        current = current.left;
      } else {
        current = current.right;
      }
    }
    return false;
  }

  public void delete(int data) {
    root = deleteNode(root, data);
  }

  private Node deleteNode(Node node, int data) {
    if (node == null) {
      return null;
    }
    if (data < node.data) {
      node.left = deleteNode(node.left, data);
    } else if (data > node.data) {
      node.right = deleteNode(node.right, data);
    } else {
      if (node.left == null) {
        return node.right;
      } else if (node.right == null) {
        return node.left;
      }
      node.data = findMin(node.right).data;
      node.right = deleteNode(node.right, node.data);
    }
    return node;
  }

  private Node findMin(Node node) {
    if (node == null) {
      return null;
    }
    while (node.left != null) {
      node = node.left;
    }
    return node;
  }

  public void printLevelOrder() {
    if (root == null) {
      return;
    }
    Queue<Node> queue = new LinkedList<>();
    queue.add(root);
    while (!queue.isEmpty()) {
      Node current = queue.poll();
      System.out.print(current.data + " ");
      if (current.left != null) {
        queue.add(current.left);
      }
      if (current.right != null) {
        queue.add(current.right);
      }
    }
  }

  private static class Node {
    int data;
    Node left;
    Node right;

    public Node(int data) {
      this.data = data;
      this.left = null;
      this.right = null;
    }
  }

  public static void main(String[] args) {
    Task151_GEMINI_gemini_1_5_pro_001 bst = new Task151_GEMINI_gemini_1_5_pro_001();
    int[] arr = {10, 5, 15, 2, 7, 12, 20};
    for (int i : arr) {
      bst.insert(i);
    }
    bst.printLevelOrder();
    System.out.println();
    System.out.println("Searching for 15: " + bst.search(15));
    System.out.println("Deleting 15:");
    bst.delete(15);
    bst.printLevelOrder();
  }
}