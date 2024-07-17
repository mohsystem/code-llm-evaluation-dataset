// C
#include <microhttpd.h>
#include <sqlite3.h>

// Function to handle POST request
int answer_to_connection (void *cls, struct MHD_Connection *connection,
                          const char *url, const char *method,
                          const char *version, const char *upload_data,
                          size_t *upload_data_size, void **con_cls) {
    // Code to handle POST request and store data in SQLite database
}

int main () {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, 8888, NULL, NULL,
                               &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon)
        return 1;

    getchar ();

    MHD_stop_daemon (daemon);
    return 0;
}