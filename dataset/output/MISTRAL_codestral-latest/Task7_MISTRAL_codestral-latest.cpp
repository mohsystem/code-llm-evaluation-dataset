// C++ client
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string login() {
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    return "LOGIN|" + username + "|" + password;
}

int main(int argc, char* argv[]) {
    try {
        boost::asio::io_context io_context;
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        boost::asio::connect(socket, resolver.resolve("localhost", "12345"));

        std::string message = login();
        boost::asio::write(socket, boost::asio::buffer(message));

        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\n");
        std::cout.write(boost::asio::buffer_cast<const char*>(response.data()), response.size());
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}