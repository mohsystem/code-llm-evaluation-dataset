#include <iostream>
#include <cstdlib>

extern "C" {
    void add_char(char c);
    void print_buffer();
}

void add_char(char c);
void print_buffer();

int main() {
    const int buffer_size = 10;
    std::cout << "Enter characters to fill the buffer:" << std::endl;

    for (int i = 0; i < buffer_size; ++i) {
        std::cout << "Enter a character: ";
        char ch;
        std::cin >> ch;
        add_char(ch);
    }

    std::cout << "Buffer contents:" << std::endl;
    print_buffer();

    return 0;
}