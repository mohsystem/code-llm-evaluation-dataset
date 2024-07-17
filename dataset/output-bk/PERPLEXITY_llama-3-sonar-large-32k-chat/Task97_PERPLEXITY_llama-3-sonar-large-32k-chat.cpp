#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <xpath> <xml_file>" << std::endl;
        return 1;
    }
    xmlInitParser();
    xmlDoc *doc = xmlReadFile(argv[2], NULL, 0);
    if (doc == NULL) {
        std::cout << "Failed to parse XML file" << std::endl;
        return 1;
    }
    xmlXPathContext *ctx = xmlXPathNewContext(doc);
    if (ctx == NULL) {
        std::cout << "Failed to create XPath context" << std::endl;
        xmlFreeDoc(doc);
        return 1;
    }
    std::string xpath = "//tag[@id='" + std::string(argv[1]) + "']";
    xmlXPathObject *obj = xmlXPathEvalExpression((xmlChar *) xpath.c_str(), ctx);
    if (obj == NULL) {
        std::cout << "Failed to evaluate XPath expression" << std::endl;
        xmlXPathFreeContext(ctx);
        xmlFreeDoc(doc);
        return 1;
    }
    xmlNodeSet *nodes = obj->nodesetval;
    for (int i = 0; i < nodes->nodeNr; i++) {
        xmlNode *node = nodes->nodeTab[i];
        xmlChar *content = xmlNodeGetContent(node);
        std::cout << content << std::endl;
        xmlFree(content);
    }
    xmlXPathFreeObject(obj);
    xmlXPathFreeContext(ctx);
    xmlFreeDoc(doc);
    return 0;
}