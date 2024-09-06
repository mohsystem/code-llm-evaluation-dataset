// C++ has built-in support for IPv6 sockets
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

boost::asio::ssl::stream<boost::asio::ip::tcp::socket> createSSLClientSocket(boost::asio::io_context& io_context, const std::string& host, const std::string& port) {
    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::ssl::context ctx(boost::asio::ssl::context::tlsv12_client);
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket(io_context, ctx);

    boost::asio::connect(socket.lowest_layer(), resolver.resolve(host, port));
    socket.handshake(boost::asio::ssl::stream_base::client);

    return socket;
}