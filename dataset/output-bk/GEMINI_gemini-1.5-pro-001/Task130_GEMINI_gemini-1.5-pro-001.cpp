#include <iostream>

#include <cpp-httplib/httplib.h>

using namespace std;
using namespace httplib;

int main(void) {
  Server svr;

  svr.Get("/api/data", [](const Request& req, Response& res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_content("{\"name\": \"John Doe\", \"age\": 30}", "application/json");
  });

  cout << "Server started at http://localhost:8080" << endl;
  svr.listen("localhost", 8080);

  return 0;
}