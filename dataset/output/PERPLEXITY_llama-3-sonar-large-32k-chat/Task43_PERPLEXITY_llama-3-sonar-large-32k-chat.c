// C code using CGI and cookies (not recommended for web development)
#include <stdio.h>
#include <string.h>
#include <cgi/cgi.h>

int main() {
    cgi_request_t *req;
    cgi_init_request(&req);
    cgi_parse_request(req);
    char *username, *password;
    if (req->request_method == CGI_METHOD_POST) {
        username = cgi_get_variable(req, "username");
        password = cgi_get_variable(req, "password");
        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
            cgi_set_cookie(req, "username", username);
            cgi_header_location(req, "home");
            return 0;
        }
    }
    char *path = cgi_get_path_info(req);
    if (strcmp(path, "/login") == 0) {
        printf("Content-type: text/html\r\n\r\n");
        printf("<form action=\"\" method=\"post\">");
        printf("Username: <input type=\"text\" name=\"username\"><br>");
        printf("Password: <input type=\"password\" name=\"password\"><br>");
        printf("<input type=\"submit\" value=\"Login\">");
        printf("</form>");
    } else if (strcmp(path, "/home") == 0) {
        cgi_cookie_t *cookies = cgi_get_cookies(req);
        for (int i = 0; i < cookies->count; i++) {
            if (strcmp(cookies->cookies[i].name, "username") == 0) {
                printf("Content-type: text/html\r\n\r\n");
                printf("Welcome, %s", cookies->cookies[i].value);
                break;
            }
        }
    } else if (strcmp(path, "/logout") == 0) {
        cgi_set_cookie(req, "username", "", 0);
        cgi_header_location(req, "login");
    }
    return 0;
}