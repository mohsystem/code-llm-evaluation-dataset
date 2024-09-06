
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

const char* get_root_element(const char* xml_string) {
    xmlDocPtr doc = xmlReadMemory(xml_string, strlen(xml_string), "noname.xml", NULL, 0);
    if (doc == NULL) {
        return "Error parsing XML";
    }
    
    xmlNodePtr root = xmlDocGetRootElement(doc);
    if (root == NULL) {
        xmlFreeDoc(doc);
        return "Empty document";
    }
    
    const char* root_name = (const char*)root->name;
    xmlFreeDoc(doc);
    return root_name;
}

int main() {
    const char* xml_str = "<root><child1>Content</child1><child2 attr=\\"value\\"/></root>";
    printf("%s\\n", get_root_element(xml_str));
    return 0;
}
