#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

void printNode(xmlNode *node) {
    xmlBufferPtr buffer = xmlBufferCreate();
    xmlNodeDump(buffer, node->doc, node, 0, 1);
    printf("%s\n", (const char*)buffer->content);
    xmlBufferFree(buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: <xpath> <xmlfile>\n");
        return -1;
    }

    char* xpathExpression = argv[1];
    char* xmlFileName = argv[2];

    xmlDocPtr doc = xmlParseFile(xmlFileName);
    if (doc == NULL) {
        fprintf(stderr, "Error: unable to parse file %s\n", xmlFileName);
        return -1;
    }

    xmlXPathContextPtr xpathCtx = xmlXPathNewContext(doc);
    if (xpathCtx == NULL) {
        fprintf(stderr, "Error: unable to create new XPath context\n");
        xmlFreeDoc(doc);
        return -1;
    }

    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((const xmlChar*) xpathExpression, xpathCtx);
    if (xpathObj == NULL) {
        fprintf(stderr, "Error: unable to evaluate xpath expression %s\n", xpathExpression);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return -1;
    }
    
    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    if (xmlXPathNodeSetIsEmpty(nodes)){
        printf("No result found for the XPath query.\n");
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