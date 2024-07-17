
#include <iostream>
#include <string>
#include <libxml/parser.h>
#include <libxml/xpath.h>

void executeXPathQuery(const std::string& filename, const std::string& xpathExpr) {
    xmlDocPtr doc;
    xmlXPathContextPtr xpathCtx;
    xmlXPathObjectPtr xpathObj;

    doc = xmlParseFile(filename.c_str());
    if (doc == nullptr) {
        std::cerr << "Error: unable to parse file \\"" << filename << "\\"" << std::endl;
        return;
    }

    xpathCtx = xmlXPathNewContext(doc);
    if(xpathCtx == nullptr) {
        std::cerr << "Error: unable to create new XPath context" << std::endl;
        xmlFreeDoc(doc);
        return;
    }

    xpathObj = xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xpathExpr.c_str()), xpathCtx);
    if(xpathObj == nullptr) {
        std::cerr << "Error: unable to evaluate xpath expression \\"" << xpathExpr << "\\"" << std::endl;
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return;
    }

    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    if (nodes) {
        for (int i = 0; i < nodes->nodeNr; i++) {
            xmlNodePtr cur = nodes->nodeTab[i];
            xmlChar* content = xmlNodeGetContent(cur);
            std::cout << content << std::endl;
            xmlFree(content);
        }
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);
    xmlCleanupParser();
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <xpath> <xml_file>" << std::endl;
        return 1;
    }

    std::string xpathExpr = argv[1];
    std::string filename = argv[2];

    executeXPathQuery(filename, xpathExpr);

    return 0;
}
