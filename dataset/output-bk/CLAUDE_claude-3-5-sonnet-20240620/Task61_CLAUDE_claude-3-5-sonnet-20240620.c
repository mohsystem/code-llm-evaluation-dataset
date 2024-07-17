
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

xmlNodePtr parseXMLString(const char* xmlString) {
    xmlDocPtr doc = xmlReadMemory(xmlString, strlen(xmlString), "noname.xml", NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse XML\
");
        return NULL;
    }
    xmlNodePtr root = xmlDocGetRootElement(doc);
    xmlFreeDoc(doc);
    return root;
}

int main() {
    const char* xmlString = "<root><child1>Value1</child1><child2>Value2</child2></root>";
    xmlInitParser();
    xmlNodePtr rootElement = parseXMLString(xmlString);
    if (rootElement != NULL) {
        printf("Root element: %s\
", rootElement->name);
    }
    xmlCleanupParser();
    return 0;
}
