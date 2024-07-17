#include <iostream>
#include <string>

class SensitiveData {
private:
    std::string data;

public:
    SensitiveData(std::string data) {
        this->data = data;
    }

    std::string getData() {
        return data;
    }
};

int main() {
    SensitiveData data("1234-5678-9012-3456");
    std::cout << data.getData() << std::endl;
    return 0;
}