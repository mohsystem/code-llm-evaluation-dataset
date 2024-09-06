public class Task115_OPENAI_gpt_4o {
    int a : 1;
    int b : 2;
    int c : 3;

    public Task115_OPENAI_gpt_4o(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public void display() {
        System.out.println("a: " + a + ", b: " + b + ", c: " + c);
    }

    public static void main(String[] args) {
        Task115_OPENAI_gpt_4o bitFields = new Task115_OPENAI_gpt_4o(1, 2, 5);
        bitFields.display();
    }
}