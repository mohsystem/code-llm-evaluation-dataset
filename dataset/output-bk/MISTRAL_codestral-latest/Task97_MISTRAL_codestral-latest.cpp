#include <libxml/parser.h>
#include <libxml/xpath.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <xpath> <xmlfile>
", argv[0]);
        return 1;
    }

    char *xpath = argv[1];
    char *xmlFile = argv[2];

    xmlDocPtr doc;
    xmlXPathContextPtr context;
    xmlXPathObjectPtr result;

    doc = xmlParseFile(xmlFile);
    if (doc == NULL) {
        fprintf(stderr, "Document not parsed successfully. 
");
        return 1;
    }

    context = xmlXPathNewContext(doc);
    if (context == NULL) {
        fprintf(stderr, "Error in xmlXPathNewContext
");
        xmlFreeDoc(doc);
        return 1;
    }

    char expression[100];
    sprintf(expression, "/tag[@id=%s]", xpath);

    result = xmlXPathEvalExpression(BAD_CAST expression, context);
    if (result == NULL) {
        fprintf(stderr, "Error in xmlXPathEvalExpression
");
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        return 1;
    }

    if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
        xmlXPathFreeObject(result);
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        fprintf(stderr, "No result
");
        return 1;
    }

    xmlNodeSetPtr nodeset = result->nodesetval;
    xmlNodePtr cur = nodeset->nodeTab[0];
    xmlChar *key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
    printf("Result: %s
", key);
    xmlFree(key);

    xmlXPathFreeObject(result);
    xmlXPathFreeContext(context);
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}