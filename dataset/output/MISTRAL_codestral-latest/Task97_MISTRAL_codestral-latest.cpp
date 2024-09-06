#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <iostream>

int main(int argc, char** argv) {
    const char* xpathValue = argv[1];
    const char* xmlFile = argv[2];

    xmlDocPtr doc = xmlReadFile(xmlFile, NULL, 0);
    if (doc == NULL) {
        std::cerr << "Failed to parse " << xmlFile << std::endl;
        return 1;
    }

    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    if (context == NULL) {
        std::cerr << "Error: unable to create new XPath context" << std::endl;
        xmlFreeDoc(doc);
        return 1;
    }

    std::string expression = "/tag[@id='" + std::string(xpathValue) + "']";
    xmlXPathObjectPtr result = xmlXPathEvalExpression((xmlChar*)expression.c_str(), context);
    if (result == NULL) {
        std::cerr << "Error: unable to evaluate xpath expression" << std::endl;
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        return 1;
    }

    if (xmlXPathNodeSetIsEmpty(result->nodesetval)) {
        std::cout << "No result" << std::endl;
    } else {
        xmlNodeSetPtr nodeset = result->nodesetval;
        for (int i = 0; i < nodeset->nodeNr; i++) {
            xmlChar* keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
            std::cout << keyword << std::endl;
            xmlFree(keyword);
        }
    }

    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}