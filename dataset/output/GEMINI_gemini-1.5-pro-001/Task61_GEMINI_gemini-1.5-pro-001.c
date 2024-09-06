// This code requires a library like libxml2
// #include <libxml/parser.h>
// #include <libxml/tree.h>

// /*
//  *To compile this file using gcc you can type
//  *gcc `xml2-config --cflags --libs` -o cexample cexample.c
//  */
// char* getRootElement(const char* xmlString) {
//     xmlDocPtr doc = xmlParseMemory(xmlString, strlen(xmlString));
//     if (doc == NULL) {
//         fprintf(stderr, "XML parsing error\n");
//         return NULL;
//     }

//     xmlNodePtr root = xmlDocGetRootElement(doc);
//     if (root == NULL) {
//         fprintf(stderr, "No root element found\n");
//         xmlFreeDoc(doc);
//         return NULL;
//     }

//     char* rootName = (char*)xmlStrdup(root->name);
//     xmlFreeDoc(doc);
//     return rootName;
// }

// int main() {
//     const char* xmlString = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
//     char* rootElement = getRootElement(xmlString);

//     if (rootElement != NULL) {
//         printf("Root element: %s\n", rootElement);
//         xmlFree(rootElement);
//     }

//     return 0;
// }