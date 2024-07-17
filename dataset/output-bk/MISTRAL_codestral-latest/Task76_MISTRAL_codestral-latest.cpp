#include <iostream>
#include <string>
#include <curl/curl.h>
#include <libxml/HTMLparser.h>

size_t write_data(void *ptr, size_t size, size_t nmeb, void *stream) {
    size_t written = fwrite(ptr, size, nmeb, (FILE*)stream);
    return written;
}

std::string get_page_title(const std::string& url) {
    CURL *curl;
    FILE *fp;
    char *data_buffer;
    long data_size;
    std::string title;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        fp = fopen("page.html", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        fclose(fp);

        fp = fopen("page.html", "rb");
        fseek(fp, 0, SEEK_END);
        data_size = ftell(fp);
        rewind(fp);

        data_buffer = new char[data_size + 1];
        data_buffer[data_size] = '\0';
        fread(data_buffer, sizeof(char), data_size, fp);
        fclose(fp);

        htmlDocPtr doc = htmlReadMemory(data_buffer, data_size, NULL, NULL, HTML_PARSE_NOBLANKS | HTML_PARSE_NOERROR | HTML_PARSE_RECOVER);
        if(doc) {
            xmlNodePtr cur = xmlDocGetRootElement(doc);
            for(cur = cur->children; cur != NULL; cur = cur->next) {
                if(cur->type == XML_ELEMENT_NODE && !xmlStrcmp(cur->name, (const xmlChar*)"title")) {
                    xmlChar *key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
                    title = std::string((char*)key);
                    xmlFree(key);
                    break;
                }
            }
            xmlFreeDoc(doc);
        }
        delete[] data_buffer;
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return title;
}

int main(int argc, char *argv[]) {
    if(argc > 1) {
        std::string title = get_page_title(argv[1]);
        std::cout << "Page title: " << title << std::endl;
    } else {
        std::cout << "Please provide an URL as a command line argument." << std::endl;
    }
    return 0;
}