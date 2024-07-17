#include <curl/curl.h>
#include <mysql/mysql.h>
#include <string>
#include <iostream>

size_t write_memory(void *ptr, size_t size, size_t nmemb, void *data) {
    std::string *buffer = (std::string *)data;
    buffer->append((char *)ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string url = "https://www.example.com";
    std::string buffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "cURL error: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }

    mysql_init(NULL);
    MYSQL *conn;
    conn = mysql_real_connect(NULL, "localhost", "root", "password", "mydb", 0, NULL, 0);
    if (!conn) {
        std::cerr << mysql_error(conn) << std::endl;
    }

    std::string query = "INSERT INTO mytable (data) VALUES ('" + buffer + "')";
    if (mysql_query(conn, query.c_str())) {
        std::cerr << mysql_error(conn) << std::endl;
    }

    mysql_close(conn);

    return 0;
}