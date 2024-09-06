// Note: This code uses the libxml2 library, which needs to be installed and linked.
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <xpath_value> <xml_file_name>\n", argv[0]);
        return 1;
    }

    char *xpathValue = argv[1];
    char *xmlFileName = argv[2];

    xmlDoc *doc = xmlReadFile(xmlFileName, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse XML file\n");
        return 1;
    }

    xmlXPathContext *context = xmlXPathNewContext(doc);
    if (context == NULL) {
        fprintf(stderr, "Failed to create XPath context\n");
        xmlFreeDoc(doc);
        return 1;
    }

    char xpathExpr[256];
    sprintf(xpathExpr, "/tag[@id='%s']", xpathValue);
    xmlXPathObject *result = xmlXPathEvalExpression((xmlChar *)xpathExpr, context);
    if (result == NULL) {
        fprintf(stderr, "Failed to evaluate XPath expression\n");
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        return 1;
    }

    xmlNodeSet *nodeset = result->nodesetval;
    for (int i = 0; i < nodeset->nodeNr; i++) {
        xmlNode *node = nodeset->nodeTab[i];
        printf("%s\n", node->content);
    }

    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);
    return 0;
}