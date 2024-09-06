// C does not have a built-in XML parsing library, so we'll use the libxml2 library
// This code assumes you have the libxml2 library installed and linked

#include <libxml/parser.h>
#include <libxml/tree.h>

#include <stdio.h>

int main() {
    xmlInitParser();
    xmlDoc *doc = xmlReadMemory("<root><person><name>John</name><age>30</age></person></root>", 44, NULL);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse XML\n");
        return 1;
    }
    xmlNode *root = xmlDocGetRootElement(doc);
    if (root == NULL) {
        fprintf(stderr, "Failed to get root element\n");
        xmlFreeDoc(doc);
        return 1;
    }
    printf("%s\n", root->name);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}