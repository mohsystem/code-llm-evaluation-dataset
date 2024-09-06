import java.util.ArrayList;
import java.util.List;

class Node {
    int data;
    List<Node> children;

    Node(int data) {
        this.data = data;
        this.children = new ArrayList<>();
    }

    void reparent(Node parent) {
        children.remove(parent);
        for (Node child : children) {
            child.reparent(this);
        }
    }

    void printTree(int level) {
        for (int i = 0; i < level; i++) {
            System.out.print(" ");
        }
        System.out.println(data);
        for (Node child : children) {
            child.printTree(level + 1);
        }
    }
}