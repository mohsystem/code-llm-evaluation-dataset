#include <libxml/parser.h>
#include <stdio.h>

int main() {
    xmlInitParser();
    xmlDoc *doc = htmlReadMemory("<root><person><name>John</name><age>30</age></person></root>", 44, NULL);
    if (doc == NULL) {
        fprintf(stderr, "Could not parse document
");
        return 1;
    }
    xmlNode *root_element = xmlDocGetRootElement(doc);
    if (root_element == NULL) {
        fprintf(stderr, "empty document
");
        xmlFreeDoc(doc);
        return 1;
    }
    printf("Root Element: %s
", root_element->name);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}