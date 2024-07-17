#include <iostream>
using namespace std;

struct BitFields {
    unsigned int field1 : 1;
    unsigned int field2 : 2;
    unsigned int field3 : 3;
};

int main() {
    BitFields bf = {1, 2, 5};
    cout << "Field1: " << bf.field1 << endl;
    cout << "Field2: " << bf.field2 << endl;
    cout << "Field3: " << bf.field3 << endl;
    return 0;
}