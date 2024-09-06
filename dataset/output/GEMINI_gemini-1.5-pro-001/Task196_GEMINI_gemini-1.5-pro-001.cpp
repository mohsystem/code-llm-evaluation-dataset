class ZeroEvenOdd {
    int n;
    bool zero_turn = true;
    bool even_turn = false;
    bool odd_turn = false;
public:
    ZeroEvenOdd(int n) : n(n) {}

    // printNumber is a function that prints the given number to the console.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            while (!zero_turn) {
                this_thread::yield();
            }
            printNumber(0);
            if (i % 2 == 0) {
                even_turn = true;
            } else {
                odd_turn = true;
            }
            zero_turn = false;
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            while (!even_turn) {
                this_thread::yield();
            }
            printNumber(i);
            zero_turn = true;
            even_turn = false;
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            while (!odd_turn) {
                this_thread::yield();
            }
            printNumber(i);
            odd_turn = false;
            zero_turn = true;
        }
    }
};