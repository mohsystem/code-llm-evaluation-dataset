/*
 * The C language does not have built-in support for XML parsing and XPath evaluation.
 * This code snippet is a simplified example and does not cover all possible errors and edge cases.
 * For a production-grade application, consider using a library such as libxml2 or TinyXML.
 */

#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <xpath_value> <xml_file>\n", argv[0]);
        return 1;
    }

    const char *xpath_value = argv[1];
    const char *xml_file = argv[2];

    xmlDocPtr doc = xmlReadFile(xml_file, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse %s\n", xml_file);
        return 1;
    }

    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    if (context == NULL) {
        fprintf(stderr, "Error: unable to create new XPath context\n");
        xmlFreeDoc(doc);
        return 1;
    }

    char expression[256];
    snprintf(expression, sizeof(expression), "/tag[@id='%s']", xpath_value);

    xmlXPathObjectPtr result = xmlXPathEvalExpression((xmlChar *)expression, context);
    if (result == NULL) {
        fprintf(stderr, "Error: unable to evaluate xpath expression\n");
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        return 1;
    }

    if (xmlXPathNodeSetIsEmpty(result->nodesetval)) {
        printf("No result\n");
    } else {
        xmlNodeSetPtr nodeset = result->nodesetval;
        for (int i = 0; i < nodeset->nodeNr; i++) {
            xmlChar *keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
            printf("%s\n", keyword);
            xmlFree(keyword);
        }
    }

    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}