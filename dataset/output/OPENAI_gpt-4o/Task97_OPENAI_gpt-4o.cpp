#include <iostream>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

void printNode(xmlNode *node) {
    xmlBufferPtr buffer = xmlBufferCreate();
    xmlNodeDump(buffer, node->doc, node, 0, 1);
    std::cout << buffer->content;
    xmlBufferFree(buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: <xpath> <xmlfile>" << std::endl;
        return -1;
    }

    char* xpathExpression = argv[1];
    char* xmlFileName = argv[2];

    xmlDocPtr doc = xmlParseFile(xmlFileName);
    if (doc == nullptr) {
        std::cerr << "Error: unable to parse file " << xmlFileName << std::endl;
        return -1;
    }

    xmlXPathContextPtr xpathCtx = xmlXPathNewContext(doc);
    if (xpathCtx == nullptr) {
        std::cerr << "Error: unable to create new XPath context" << std::endl;
        xmlFreeDoc(doc);
        return -1;
    }

    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression(reinterpret_cast<const xmlChar*>(xpathExpression), xpathCtx);
    if (xpathObj == nullptr) {
        std::cerr << "Error: unable to evaluate xpath expression " << xpathExpression << std::endl;
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return -1;
    }
    
    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    if (xmlXPathNodeSetIsEmpty(nodes)) {
        std::cout << "No result found for the XPath query." << std::endl;
    } else {
        for (int i = 0; i < nodes->nodeNr; ++i) {
            printNode(nodes->nodeTab[i]);
        }
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);

    return 0;
}