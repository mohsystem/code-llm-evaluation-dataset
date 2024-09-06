
#include <crow.h>
#include <unordered_map>
#include <chrono>
#include <ctime>
#include <random>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

struct Session {
    std::string username;
    std::chrono::system_clock::time_point login_time;
};

std::unordered_map<std::string, std::string> users;
std::unordered_map<std::string, Session> sessions;
const int SESSION_TIMEOUT = 1800; // 30 minutes

std::string generate_session_id() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    const char* v = "0123456789abcdef";
    std::string res;
    for (int i = 0; i < 32; ++i) {
        res += v[dis(gen)];
    }
    return res;
}

std::string hash_password(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/register").methods("POST"_method)
    ([](const crow::request& req) {
        auto x = crow::json::load(req.body);
        if (!x) return crow::response(400, "Invalid JSON");
        
        std::string username = x["username"].s();
        std::string password = x["password"].s();
        
        if (users.find(username) != users.end()) {
            return crow::response(400, "Username already exists");
        }
        
        users[username] = hash_password(password);
        return crow::response(201, "User registered successfully");
    });

    CROW_ROUTE(app, "/login").methods("POST"_method)
    ([](const crow::request& req) {
        auto x = crow::json::load(req.body);
        if (!x) return crow::response(400, "Invalid JSON");
        
        std::string username = x["username"].s();
        std::string password = x["password"].s();
        
        if (users.find(username) == users.end() || users[username] != hash_password(password)) {
            return crow::response(401, "Invalid credentials");
        }
        
        std::string session_id = generate_session_id();
        sessions[session_id] = {username, std::chrono::system_clock::now()};
        
        crow::response res(200, "Logged in successfully");
        res.add_header("Set-Cookie", "session_id=" + session_id + "; HttpOnly; Path=/");
        return res;
    });

    CROW_ROUTE(app, "/logout").methods("POST"_method)
    ([](const crow::request& req) {
        auto session_id = req.get_header_value("Cookie");
        if (!session_id.empty()) {
            sessions.erase(session_id);
        }
        crow::response res(200, "Logged out successfully");
        res.add_header("Set-Cookie", "session_id=; HttpOnly; Path=/; Expires=Thu, 01 Jan 1970 00:00:00 GMT");
        return res;
    });

    CROW_ROUTE(app, "/protected").methods("GET"_method)
    ([](const crow::request& req) {
        auto session_id = req.get_header_value("Cookie");
        if (session_id.empty() || sessions.find(session_id) == sessions.end()) {
            return crow::response(401, "Unauthorized");
        }
        
        auto& session = sessions[session_id];
        auto now = std::chrono::system_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - session.login_time).count() > SESSION_TIMEOUT) {
            sessions.erase(session_id);
            return crow::response(401, "Session expired");
        }
        
        return crow::response(200, "Hello, " + session.username + "!");
    });

    app.port(8080).multithreaded().run();
    return 0;
}
