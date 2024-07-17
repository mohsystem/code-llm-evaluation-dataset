// main.cpp

#include <iostream>
#include <unordered_map>
#include "httplib.h"

std::unordered_map<std::string, std::string> sessions;

int main(void)
{
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res) {
        std::string session_id = req.remote_addr;
        sessions[session_id] = session_id;
        res.set_content("Session created: " + session_id, "text/plain");
    });

    svr.Post("/terminate", [](const httplib::Request &req, httplib::Response &res) {
        auto session_id = req.get_param_value("sessionId");
        if (sessions.find(session_id) != sessions.end())
        {
            sessions.erase(session_id);
            res.set_content("Session terminated: " + session_id, "text/plain");
        }
        else
        {
            res.set_content("Session not found: " + session_id, "text/plain");
        }
    });

    svr.listen("localhost", 8000);
    return 0;
}