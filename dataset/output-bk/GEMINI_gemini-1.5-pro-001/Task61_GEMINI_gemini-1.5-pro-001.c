#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

char* getRootElement(const char *xmlString) {
    xmlDocPtr doc = xmlParseMemory(xmlString, strlen(xmlString));
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse XML
");
        return NULL;
    }

    xmlNodePtr root = xmlDocGetRootElement(doc);
    if (root == NULL) {
        fprintf(stderr, "Empty document
");
        xmlFreeDoc(doc);
        return NULL;
    }

    char *rootElement = strdup((char *)root->name);
    xmlFreeDoc(doc);
    return rootElement;
}

int main() {
    const char *xmlString = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    char *rootElement = getRootElement(xmlString);
    if (rootElement != NULL) {
        printf("%s
", rootElement);
        free(rootElement);
    }
    return 0;
}