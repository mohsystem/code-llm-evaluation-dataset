
#include <iostream>
#include <string>
#include <vector>
#include <pugixml.hpp>

std::vector<std::string> execute_xpath(const std::string& xml_file, const std::string& xpath) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xml_file.c_str());

    if (!result) {
        std::cerr << "XML parsing error: " << result.description() << std::endl;
        return {};
    }

    std::vector<std::string> results;
    pugi::xpath_node_set nodes = doc.select_nodes(xpath.c_str());

    for (const auto& node : nodes) {
        results.push_back(node.node().child_value());
    }

    return results;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <xml_file> <xpath>" << std::endl;
        return 1;
    }

    std::string xml_file = argv[1];
    std::string xpath = argv[2];

    std::vector<std::string> result = execute_xpath(xml_file, xpath);

    for (const auto& item : result) {
        std::cout << item << std::endl;
    }

    return 0;
}
