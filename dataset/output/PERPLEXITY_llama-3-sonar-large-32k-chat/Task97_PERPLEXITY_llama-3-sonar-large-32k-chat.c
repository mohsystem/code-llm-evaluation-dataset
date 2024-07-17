#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <xpath> <xml_file>
", argv[0]);
        return 1;
    }
    xmlInitParser();
    xmlDoc *doc = xmlReadFile(argv[2], NULL, 0);
    if (doc == NULL) {
        printf("Failed to parse XML file
");
        return 1;
    }
    xmlXPathContext *ctx = xmlXPathNewContext(doc);
    if (ctx == NULL) {
        printf("Failed to create XPath context
");
        xmlFreeDoc(doc);
        return 1;
    }
    xmlXPathObject *obj = xmlXPathEvalExpression((xmlChar *) ("//tag[@id='" + argv[1] + "']"), ctx);
    if (obj == NULL) {
        printf("Failed to evaluate XPath expression
");
        xmlXPathFreeContext(ctx);
        xmlFreeDoc(doc);
        return 1;
    }
    xmlNodeSet *nodes = obj->nodesetval;
    for (int i = 0; i < nodes->nodeNr; i++) {
        xmlNode *node = nodes->nodeTab[i];
        xmlChar *content = xmlNodeGetContent(node);
        printf("%s
", content);
        xmlFree(content);
    }
    xmlXPathFreeObject(obj);
    xmlXPathFreeContext(ctx);
    xmlFreeDoc(doc);
    return 0;
}