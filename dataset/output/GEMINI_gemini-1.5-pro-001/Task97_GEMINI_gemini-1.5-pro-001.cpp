#include <iostream>
#include <fstream>
#include <string>

#include <pugixml.cpp>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <xpath> <xml_file> <id_value>" << endl;
        return 1;
    }

    const char* xpath_expression = argv[1];
    const char* xml_file_path = argv[2];
    const char* id_value = argv[3];

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xml_file_path);

    if (!result) {
        cerr << "Error parsing XML: " << result.description() << endl;
        return 1;
    }

    string full_xpath = string(xpath_expression) + "[@id='" + id_value + "']";
    pugi::xpath_query query(full_xpath.c_str());
    pugi::xpath_node_set nodes = query.evaluate_node_set(doc);

    for (pugi::xpath_node_set::const_iterator it = nodes.begin(); it != nodes.end(); ++it) {
        pugi::xml_node node = it->node();
        cout << node.name() << " ";

        for (pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute()) {
            cout << attr.name() << "=\"" << attr.value() << "\" ";
        }
        cout << endl;
    }

    return 0;
}