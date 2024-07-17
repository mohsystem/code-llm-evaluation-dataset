#include <iostream>
#include <fstream>
#include <string>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

void evaluate_xpath(const std::string& filename, const std::string& xpathExpr) {
    xmlDocPtr doc = xmlParseFile(filename.c_str());
    if (doc == NULL) {
        std::cerr << "Unable to parse XML file " << filename << std::endl;
        return;
    }

    xmlXPathContextPtr xpathCtx = xmlXPathNewContext(doc);
    if(xpathCtx == NULL) {
        std::cerr << "Unable to create new XPath context" << std::endl;
        xmlFreeDoc(doc);
        return;
    }

    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xpathExpr.c_str()), xpathCtx);
    if(xpathObj == NULL) {
        std::cerr << "Unable to evaluate XPath expression " << xpathExpr << std::endl;
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return;
    }

    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    for (int i = 0; i < nodes->nodeNr; i++) {
        xmlChar *content = xmlNodeGetContent(nodes->nodeTab[i]);
        std::cout << content << std::endl;
        xmlFree(content);
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <xpath> <xmlfile>" << std::endl;
        return -1;
    }

    std::string xpathExpr = argv[1];
    std::string xmlFile = argv[2];

    evaluate_xpath(xmlFile, xpathExpr);

    return 0;
}