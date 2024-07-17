
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    try {
        io_context io_context;
        ssl::context ctx(ssl::context::sslv23);
        ctx.set_default_verify_paths();

        ssl::stream<tcp::socket> socket(io_context, ctx);

        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("example.com", "https");

        connect(socket.lowest_layer(), endpoints);

        socket.handshake(ssl::stream_base::client);

        std::string request = "GET / HTTP/1.1\\r\
Host: example.com\\r\
\\r\
";
        write(socket, buffer(request));

        std::string response;
        boost::system::error_code error;

        do {
            char buf[1024];
            size_t len = socket.read_some(buffer(buf), error);
            response.append(buf, len);
        } while (!error);

        if (error != boost::asio::error::eof) {
            throw boost::system::system_error(error);
        }

        std::cout << response << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
