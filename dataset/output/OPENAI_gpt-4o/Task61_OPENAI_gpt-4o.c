#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main() {
    const char *xmlString = "<?xml version=\"1.0\"?><root><child1>Content1</child1><child2><subchild1>Content2</subchild1></child2></root>";
    xmlDoc *document = xmlReadMemory(xmlString, strlen(xmlString), "noname.xml", NULL, 0);
    if (document == NULL) {
        printf("Failed to parse XML\n");
        return 1;
    }

    xmlNode *root = xmlDocGetRootElement(document);
    if (root == NULL) {
        printf("Empty document\n");
        xmlFreeDoc(document);
        return 1;
    }

    printf("%s\n", root->name);
    xmlFreeDoc(document);
    return 0;
}