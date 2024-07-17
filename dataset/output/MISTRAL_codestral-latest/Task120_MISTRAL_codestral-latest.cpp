// C++ (using Boost.Beast)
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

class session : public std::enable_shared_from_this<session> {
    // ... (rest of the class definition)
};

void do_listen(tcp::acceptor& acceptor, tcp::socket& socket) {
    acceptor.async_accept(socket,
        [&](beast::error_code ec) {
            if (!ec) {
                std::make_shared<session>(std::move(socket))->run();
            }
            do_listen(acceptor, socket);
        });
}

int main(int argc, char* argv[]) {
    try {
        auto const address = net::ip::make_address("0.0.0.0");
        unsigned short port = 8080;
        net::io_context ioc{1};
        tcp::acceptor acceptor{ioc, {address, port}};
        tcp::socket socket{ioc};
        do_listen(acceptor, socket);
        ioc.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}