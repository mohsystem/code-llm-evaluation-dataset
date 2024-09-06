import java.util.EmptyStackException;
import java.util.Stack;

public class Task148_MISTRAL_codestral_latest {
    private Stack<Integer> stack;

    public Task148_MISTRAL_codestral_latest() {
        stack = new Stack<>();
    }

    public void push(int item) {
        stack.push(item);
    }

    public int pop() {
        if (stack.isEmpty()) {
            throw new EmptyStackException();
        }
        return stack.pop();
    }

    public int peek() {
        if (stack.isEmpty()) {
            throw new EmptyStackException();
        }
        return stack.peek();
    }
}