#include <iostream>
#include <string>
#include <tinyxml2.h>

using namespace tinyxml2;

int main() {
    const char* xml = R"(<root><child1>Content1</child1><child2><subchild1>Content2</subchild1></child2></root>)";

    XMLDocument doc;
    if (doc.Parse(xml) == XML_SUCCESS) {
        XMLElement* root = doc.RootElement();
        if (root) {
            std::cout << root->Name() << std::endl;
        }
    } else {
        std::cerr << "Failed to parse XML" << std::endl;
    }
    return 0;
}