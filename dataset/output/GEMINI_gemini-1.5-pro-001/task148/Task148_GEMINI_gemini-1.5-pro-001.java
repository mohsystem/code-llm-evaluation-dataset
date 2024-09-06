import java.util.ArrayList;
import java.util.List;

class Stack {
    private List<Object> items;

    public Stack() {
        this.items = new ArrayList<>();
    }

    public void push(Object item) {
        this.items.add(item);
    }

    public Object pop() {
        if (!this.is_empty()) {
            return this.items.remove(this.items.size() - 1);
        } else {
            return "Stack is empty";
        }
    }

    public Object peek() {
        if (!this.is_empty()) {
            return this.items.get(this.items.size() - 1);
        } else {
            return "Stack is empty";
        }
    }

    public boolean is_empty() {
        return this.items.size() == 0;
    }

    
}