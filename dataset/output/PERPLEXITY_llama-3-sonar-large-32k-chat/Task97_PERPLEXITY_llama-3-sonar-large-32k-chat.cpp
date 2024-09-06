// Note: This code uses the libxml2 library, which needs to be installed and linked.
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <xpath_value> <xml_file_name>" << std::endl;
        return 1;
    }

    std::string xpathValue = argv[1];
    std::string xmlFileName = argv[2];

    xmlDoc *doc = xmlReadFile(xmlFileName.c_str(), NULL, 0);
    if (doc == NULL) {
        std::cerr << "Failed to parse XML file" << std::endl;
        return 1;
    }

    xmlXPathContext *context = xmlXPathNewContext(doc);
    if (context == NULL) {
        std::cerr << "Failed to create XPath context" << std::endl;
        xmlFreeDoc(doc);
        return 1;
    }

    std::string xpathExpr = "/tag[@id='" + xpathValue + "']";
    xmlXPathObject *result = xmlXPathEvalExpression((xmlChar *)xpathExpr.c_str(), context);
    if (result == NULL) {
        std::cerr << "Failed to evaluate XPath expression" << std::endl;
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        return 1;
    }

    xmlNodeSet *nodeset = result->nodesetval;
    for (int i = 0; i < nodeset->nodeNr; i++) {
        xmlNode *node = nodeset->nodeTab[i];
        std::cout << node->content << std::endl;
    }

    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);
    return 0;
}