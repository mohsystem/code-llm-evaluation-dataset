// C++ code using Boost
#include <boost/asio.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;
using namespace boost::serialization;

class MyService {
public:
    std::string getData() {
        return "Hello from server!";
    }

    void setData(const std::string& data) {
        std::cout << "Received data from client: " << data << std::endl;
    }
};

int main() {
    io_service io;
    ip::tcp::acceptor acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), 18861));
    ip::tcp::socket socket(io);

    acceptor.accept(socket);

    boost::archive::text_iarchive ia(&socket);
    boost::archive::text_oarchive oa(&socket);

    MyService service;
    std::string data;

    while (true) {
        ia >> data;
        service.setData(data);
        oa << service.getData();
    }

    return 0;
}