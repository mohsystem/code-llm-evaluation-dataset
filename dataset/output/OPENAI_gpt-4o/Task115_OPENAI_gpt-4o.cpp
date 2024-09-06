#include <iostream>
using namespace std;

class BitFields {
public:
    unsigned int a : 1;
    unsigned int b : 2;
    unsigned int c : 3;

    BitFields(unsigned int a, unsigned int b, unsigned int c) : a(a), b(b), c(c) {}

    void display() {
        cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    }
};

int main() {
    BitFields bitFields(1, 2, 5);
    bitFields.display();
    return 0;
}