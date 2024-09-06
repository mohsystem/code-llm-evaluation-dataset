
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

using boost::asio::ip::tcp;
namespace ssl = boost::asio::ssl;

ssl::stream<tcp::socket> create_ssl_ipv6_socket(const std::string& host, const std::string& port) {
    boost::asio::io_context io_context;
    ssl::context ctx(ssl::context::sslv23);
    ctx.set_default_verify_paths();

    tcp::resolver resolver(io_context);
    tcp::resolver::query query(tcp::v6(), host, port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    ssl::stream<tcp::socket> socket(io_context, ctx);
    boost::asio::connect(socket.lowest_layer(), endpoint_iterator);
    socket.handshake(ssl::stream_base::client);

    return socket;
}

int main() {
    try {
        std::string host = "example.com";
        std::string port = "443";
        auto socket = create_ssl_ipv6_socket(host, port);
        // Use the socket here
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
