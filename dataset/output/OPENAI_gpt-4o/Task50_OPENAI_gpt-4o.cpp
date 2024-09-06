// C++: Server to upload files using Boost.Beast and Boost.Asio
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;        
using tcp = net::ip::tcp;           
namespace fs = boost::filesystem;

const std::string UPLOAD_DIR = "uploads/";

int main() {
    try {
        if (!fs::exists(UPLOAD_DIR)) {
            fs::create_directory(UPLOAD_DIR);
        }

        auto const address = net::ip::make_address("0.0.0.0");
        const int port = 8080;
        net::io_context ioc{1};

        tcp::acceptor acceptor{ioc, {address, static_cast<unsigned short>(port)}};
        for (;;) {
            tcp::socket socket{ioc};
            acceptor.accept(socket);

            beast::flat_buffer buffer;
            http::request<http::string_body> req;
            http::read(socket, buffer, req);

            if (req.method() != http::verb::post) {
                socket.close();
                continue;
            }

            auto const& body = req.body();
            std::ofstream ofs(UPLOAD_DIR + "uploaded_file", std::ios::binary);
            ofs.write(body.data(), body.size());
            ofs.close();

            http::response<http::string_body> res{http::status::ok, req.version()};
            res.set(http::field::server, "Beast");
            res.set(http::field::content_type, "text/plain");
            res.body() = "File successfully uploaded";
            res.prepare_payload();
            http::write(socket, res);

            socket.shutdown(tcp::socket::shutdown_send);
        }
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}