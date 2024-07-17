#include <iostream>
#include <string>
#include <fcgio.h>

int main(void) {
    while (FCGI_Accept() >= 0) {
        std::cout << "Content-type: text/html\r
\r
";
        std::cout << "<html><body>";
        
        std::streambuf* cin_buf = std::cin.rdbuf();
        std::streambuf* cout_buf = std::cout.rdbuf();
        
        fcgi_streambuf cin_fcgi_buf(FCGI_stdin);
        std::cin.rdbuf(&cin_fcgi_buf);
        
        char* contentLength = getenv("CONTENT_LENGTH");
        int len = contentLength ? std::stoi(contentLength) : 0;
        
        if (len > 0) {
            std::string input(len, '\0');
            std::cin.read(&input[0], len);
            size_t pos = input.find("userInput=") + 10;
            std::string userInput = input.substr(pos);
            std::cout << "<h1>You entered: " << userInput << "</h1>";
        }
        
        std::cin.rdbuf(cin_buf);
        std::cout.rdbuf(cout_buf);
        
        std::cout << "</body></html>";
    }
    return 0;
}