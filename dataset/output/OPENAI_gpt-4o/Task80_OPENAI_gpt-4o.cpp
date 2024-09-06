#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

boost::asio::ssl::stream<boost::asio::ip::tcp::socket> create_ssl_client_socket(const std::string& host, const std::string& port) {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket(io_context, ctx);

    auto endpoints = resolver.resolve(boost::asio::ip::tcp::resolver::query(boost::asio::ip::tcp::v6(), host, port));
    boost::asio::connect(socket.lowest_layer(), endpoints);
    socket.handshake(boost::asio::ssl::stream_base::client);
    return socket;
}