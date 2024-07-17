#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <xml_file> <xpath_query> <id_value>
", argv[0]);
        return 1;
    }

    char *xmlFile = argv[1];
    char *xpathQuery = argv[2];
    char *idValue = argv[3];
    char formattedQuery[256];
    snprintf(formattedQuery, sizeof(formattedQuery), xpathQuery, idValue);

    xmlDocPtr doc = xmlParseFile(xmlFile);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse XML file.
");
        return 1;
    }

    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    if (context == NULL) {
        fprintf(stderr, "Failed to create XPath context.
");
        xmlFreeDoc(doc);
        return 1;
    }

    xmlXPathObjectPtr result = xmlXPathEvalExpression((const xmlChar *)formattedQuery, context);
    if (result == NULL) {
        fprintf(stderr, "Failed to evaluate XPath expression.
");
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        return 1;
    }

    if (result->type == XPATH_STRING) {
        printf("%s
", (char *)result->nodesetval->nodeTab[0]->children->content);
    } else {
        fprintf(stderr, "XPath result is not a string.
");
    }

    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);

    return 0;
}