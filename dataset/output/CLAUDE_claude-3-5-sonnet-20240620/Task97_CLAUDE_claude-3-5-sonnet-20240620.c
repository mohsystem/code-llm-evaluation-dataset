
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

void execute_xpath(const char* filename, const char* xpathExpr) {
    xmlDocPtr doc;
    xmlXPathContextPtr xpathCtx;
    xmlXPathObjectPtr xpathObj;

    doc = xmlParseFile(filename);
    if (doc == NULL) {
        fprintf(stderr, "Error: unable to parse file \\"%s\\"\\n", filename);
        return;
    }

    xpathCtx = xmlXPathNewContext(doc);
    if(xpathCtx == NULL) {
        fprintf(stderr,"Error: unable to create new XPath context\\n");
        xmlFreeDoc(doc);
        return;
    }

    xpathObj = xmlXPathEvalExpression((xmlChar*)xpathExpr, xpathCtx);
    if(xpathObj == NULL) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \\"%s\\"\\n", xpathExpr);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return;
    }

    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    if (nodes) {
        for (int i = 0; i < nodes->nodeNr; i++) {
            xmlNodePtr cur = nodes->nodeTab[i];
            if (cur->type == XML_ELEMENT_NODE) {
                xmlChar* content = xmlNodeGetContent(cur);
                printf("%s\\n", content);
                xmlFree(content);
            }
        }
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);
    xmlCleanupParser();
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <xml_file> <xpath>\\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    const char* xpathExpr = argv[2];

    execute_xpath(filename, xpathExpr);

    return 0;
}
