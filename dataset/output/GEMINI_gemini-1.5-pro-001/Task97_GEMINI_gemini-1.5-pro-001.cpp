#include <iostream>
#include <string>
#include <stdexcept>
#include <pugixml.hpp>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <xml_file> <xpath_query> <id_value>" << std::endl;
        return 1;
    }

    std::string xmlFile = argv[1];
    std::string xpathQuery = argv[2];
    std::string idValue = argv[3];

    try {
        // Construct and parse the XML file
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(xmlFile.c_str());
        if (!result) {
            throw std::runtime_error("Failed to parse XML file: " + xmlFile);
        }

        // Execute the XPath query
        std::string query = xpathQuery + "=\"" + idValue + "\"]";
        pugi::xpath_node node = doc.select_node(query.c_str());
        if (!node) {
            throw std::runtime_error("XPath query returned no results: " + query);
        }

        // Return the result
        std::cout << node.node().text().get() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}