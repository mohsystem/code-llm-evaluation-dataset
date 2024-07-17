#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

void doSomething() {
    cout << "Doing something on the server..." << endl;
}

int main() {
    io_service io;
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080));

    tcp::socket socket(io);
    acceptor.accept(socket);

    string message;
    boost::system::error_code error;
    socket.read_some(buffer(message), error);

    if (!error) {
        cout << message << endl;
        doSomething();
        boost::asio::write(socket, buffer("Hello from server"));
        cout << "Hello message sent" << endl;
    } else {
        cout << "Error: " << error.message() << endl;
    }

    return 0;
}