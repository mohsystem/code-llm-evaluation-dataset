import java.util.Scanner;

public class Task104_OPENAI_gpt_4o {
    static {
        System.loadLibrary("buffer_program");
    }

    private native void addChar(char c);
    private native void printBuffer();
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Task104_OPENAI_gpt_4o bp = new Task104_OPENAI_gpt_4o();
        int bufferSize = 10;

        System.out.println("Enter characters to fill the buffer:");
        for (int i = 0; i < bufferSize; ++i) {
            System.out.print("Enter a character: ");
            char ch = sc.next().charAt(0);
            bp.addChar(ch);
        }

        System.out.println("Buffer contents:");
        bp.printBuffer();
    }
}