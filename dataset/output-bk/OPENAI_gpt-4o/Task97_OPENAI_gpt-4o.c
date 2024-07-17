#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

void evaluate_xpath(const char* filename, const char* xpathExpr) {
    xmlDocPtr doc;
    xmlXPathContextPtr xpathCtx;
    xmlXPathObjectPtr xpathObj;

    doc = xmlParseFile(filename);
    if (doc == NULL) {
        printf("Unable to parse XML file %s
", filename);
        return;
    }

    xpathCtx = xmlXPathNewContext(doc);
    if(xpathCtx == NULL) {
        printf("Unable to create new XPath context
");
        xmlFreeDoc(doc);
        return;
    }

    xpathObj = xmlXPathEvalExpression((const xmlChar*) xpathExpr, xpathCtx);
    if(xpathObj == NULL) {
        printf("Unable to evaluate XPath expression %s
", xpathExpr);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return;
    }

    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    for (int i = 0; i < nodes->nodeNr; i++) {
        xmlChar *content = xmlNodeGetContent(nodes->nodeTab[i]);
        printf("%s
", content);
        xmlFree(content);
    }

    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <xpath> <xmlfile>
", argv[0]);
        return -1;
    }

    const char* xpathExpr = argv[1];
    const char* xmlFile = argv[2];

    evaluate_xpath(xmlFile, xpathExpr);

    return 0;
}