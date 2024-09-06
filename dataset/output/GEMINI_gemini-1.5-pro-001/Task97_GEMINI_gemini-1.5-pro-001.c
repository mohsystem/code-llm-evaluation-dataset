#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

void print_node_info(xmlNodePtr node) {
    if (node) {
        printf("Node Name: %s\n", node->name);
        xmlAttrPtr attr = node->properties;
        while (attr) {
            printf("  Attribute: %s, Value: %s\n", attr->name, attr->children->content);
            attr = attr->next;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <xpath> <xml_file> <id_value>\n", argv[0]);
        return 1;
    }

    char *xpath_expression = argv[1];
    char *xml_file_path = argv[2];
    char *id_value = argv[3];

    xmlDocPtr doc = xmlParseFile(xml_file_path);
    if (doc == NULL) {
        fprintf(stderr, "Error parsing XML file.\n");
        return 1;
    }

    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    if (context == NULL) {
        fprintf(stderr, "Error creating XPath context.\n");
        xmlFreeDoc(doc);
        return 1;
    }

    // Constructing XPath with ID
    char full_xpath[256]; 
    snprintf(full_xpath, sizeof(full_xpath), "%s[@id='%s']", xpath_expression, id_value);

    xmlXPathObjectPtr result = xmlXPathEvalExpression((const xmlChar *)full_xpath, context);
    if (result == NULL) {
        fprintf(stderr, "Error evaluating XPath expression.\n");
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        return 1;
    }

    if (result->nodesetval) {
        for (int i = 0; i < result->nodesetval->nodesetvalsize; ++i) {
            print_node_info(result->nodesetval->nodeTab[i]);
        }
    }

    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);
    return 0;
}