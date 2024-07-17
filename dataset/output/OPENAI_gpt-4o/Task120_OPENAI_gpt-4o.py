from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib

class DisplayInputHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        params = urllib.parse.parse_qs(urllib.parse.urlparse(self.path).query)
        user_input = params.get('userInput', [''])[0]
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(bytes(f"""
            <html><body>
            <h1>User Input:</h1>
            <p>{user_input}</p>
            </body></html>
        """, "utf-8"))

def run(server_class=HTTPServer, handler_class=DisplayInputHandler, port=8080):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print(f'Starting server on port {port}...')
    httpd.serve_forever()

if __name__ == '__main__':
    run()