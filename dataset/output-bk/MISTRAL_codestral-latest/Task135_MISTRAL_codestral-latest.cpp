// C++ example using the Pistache library for HTTP
#include <pistache/http.h>
#include <pistache/endpoint.h>
#include <random>
#include <base64.h>

using namespace Pistache;
using namespace Pistache::Http;

class CSRFProtectionHandler : public Http::Handler {
public:
    HTTP_PROTOTYPE(CSRFProtectionHandler)

    void onRequest(const Http::Request& req, Http::ResponseWriter response) override {
        if (req.method() == Http::Method::Post) {
            auto session = req.cookies().get("session");
            if (session) {
                auto token = session->value();
                auto formToken = req.post().get("_csrf_token").get();
                if (token == formToken) {
                    // Process the funds transfer
                } else {
                    response.send(Http::Code::Forbidden);
                }
            } else {
                response.send(Http::Code::Forbidden);
            }
        } else if (req.method() == Http::Method::Get) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 255);
            std::string token(24, 0);
            for (auto& c : token) {
                c = dis(gen);
            }
            auto base64Token = base64_encode(reinterpret_cast<const unsigned char*>(token.data()), token.length());
            response.cookies().add(Http::Cookie("session", base64Token));
            // Render the form with the CSRF token
        }
    }
};