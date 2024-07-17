#include <curl/curl.h>
#include <mysql.h>
#include <string.h>

int main() {
    CURL *curl;
    CURLcode res;
    char url[] = "https://www.example.com";
    char buffer[1024];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "cURL error: %s
", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "mydb";

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s
", mysql_error(conn));
    }

    char query[1024];
    sprintf(query, "INSERT INTO mytable (data) VALUES ('%s')", buffer);
    if (mysql_query(conn, query)) {
        fprintf(stderr, "%s
", mysql_error(conn));
    }

    mysql_close(conn);

    return 0;
}

static size_t write_memory(void *ptr, size_t size, size_t nmemb, void *data) {
    char *buffer = (char *)data;
    strncpy(buffer, ptr, size * nmemb);
    return size * nmemb;
}