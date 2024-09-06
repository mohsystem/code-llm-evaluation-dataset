// C++ (Using CPP-HTTPLIB)
#include <httplib.h>
#include <fstream>

int main() {
    httplib::Server svr;

    svr.Post("/upload", [](const httplib::Request& req, httplib::Response& res) {
        if (req.has_file("file")) {
            auto file = req.get_file_value("file");
            std::ofstream out("/path/to/the/uploads/" + file.filename, std::ios::binary);
            out.write(file.content.c_str(), file.content.size());
            out.close();
            res.set_content("File uploaded successfully", "text/plain");
        } else {
            res.set_content("No file uploaded", "text/plain");
        }
    });

    svr.listen("localhost", 8080);
}