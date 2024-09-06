#include <httplib.h>

int main() {
    httplib::Server svr;

    svr.set_mount_point("/", "./www");
    svr.set_header_value_adder("Access-Control-Allow-Origin", "http://example.com");

    svr.listen("0.0.0.0", 8080);
}