
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include <cstring>

const int MAX_TOKEN_LENGTH = 33;
const int MAX_INPUT_LENGTH = 256;

std::string csrf_token;

std::string generate_csrf_token() {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charset.length() - 1);

    std::string token;
    for (int i = 0; i < MAX_TOKEN_LENGTH - 1; ++i) {
        token += charset[dis(gen)];
    }
    return token;
}

void render_form() {
    std::cout << "Content-Type: text/html\
\
";
    std::cout << "<html><body>";
    std::cout << "<h1>User Settings</h1>";
    std::cout << "<form method=\'post\' action=\'settings.cgi\'>";
    std::cout << "<input type=\'hidden\' name=\'csrf_token\' value=\'" << csrf_token << "\'>";
    std::cout << "Name: <input type=\'text\' name=\'name\'><br>";
    std::cout << "Email: <input type=\'email\' name=\'email\'><br>";
    std::cout << "<input type=\'submit\' value=\'Update\'>";
    std::cout << "</form>";
    std::cout << "</body></html>";
}

void update_settings(const std::string& name, const std::string& email) {
    std::cout << "Content-Type: text/html\
\
";
    std::cout << "<html><body>";
    std::cout << "<h1>Settings Updated</h1>";
    std::cout << "<p>Name: " << name << "</p>";
    std::cout << "<p>Email: " << email << "</p>";
    std::cout << "</body></html>";
}

std::string get_post_data() {
    std::string data;
    int content_length = 0;
    char* content_length_str = getenv("CONTENT_LENGTH");
    
    if (content_length_str != nullptr) {
        content_length = std::atoi(content_length_str);
        if (content_length > 0) {
            char* buffer = new char[content_length + 1];
            std::cin.read(buffer, content_length);
            buffer[content_length] = \'\\0\';
            data = buffer;
            delete[] buffer;
        }
    }
    
    return data;
}

void parse_post_data(const std::string& data, std::string& name, std::string& email, std::string& token) {
    size_t pos = 0;
    std::string pair;
    std::string post_data = data;
    
    while ((pos = post_data.find(\'&\')) != std::string::npos) {
        pair = post_data.substr(0, pos);
        size_t eq_pos = pair.find(\'=\');
        if (eq_pos != std::string::npos) {
            std::string key = pair.substr(0, eq_pos);
            std::string value = pair.substr(eq_pos + 1);
            if (key == "name") name = value;
            else if (key == "email") email = value;
            else if (key == "csrf_token") token = value;
        }
        post_data.erase(0, pos + 1);
    }
    
    size_t eq_pos = post_data.find(\'=\');
    if (eq_pos != std::string::npos) {
        std::string key = post_data.substr(0, eq_pos);
        std::string value = post_data.substr(eq_pos + 1);
        if (key == "name") name = value;
        else if (key == "email") email = value;
        else if (key == "csrf_token") token = value;
    }
}

int main() {
    std::string request_method = getenv("REQUEST_METHOD");
    
    if (request_method == "GET") {
        csrf_token = generate_csrf_token();
        render_form();
    } else if (request_method == "POST") {
        std::string post_data = get_post_data();
        if (!post_data.empty()) {
            std::string name, email, token;
            parse_post_data(post_data, name, email, token);
            
            if (token == csrf_token) {
                update_settings(name, email);
            } else {
                std::cout << "Content-Type: text/html\
\
";
                std::cout << "<html><body>";
                std::cout << "<h1>Error: Invalid CSRF Token</h1>";
                std::cout << "</body></html>";
            }
        }
    }
    
    return 0;
}
