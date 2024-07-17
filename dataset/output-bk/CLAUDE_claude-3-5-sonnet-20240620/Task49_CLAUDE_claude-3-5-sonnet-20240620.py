
from http.server import HTTPServer, BaseHTTPRequestHandler
import sqlite3
from urllib.parse import parse_qs

class SimpleAPIHandler(BaseHTTPRequestHandler):
    def do_POST(self):
        if self.path.startswith(\'/api/user\'):
            content_length = int(self.headers[\'Content-Length\'])
            post_data = self.rfile.read(content_length).decode(\'utf-8\')
            params = parse_qs(post_data)
            
            name = params.get(\'name\', [\'\'])[0]
            email = params.get(\'email\', [\'\'])[0]
            
            try:
                self.store_user_data(name, email)
                self.send_response(200)
                self.send_header(\'Content-type\', \'text/plain\')
                self.end_headers()
                self.wfile.write(b\'User data stored successfully\')
            except Exception as e:
                self.send_response(500)
                self.send_header(\'Content-type\', \'text/plain\')
                self.end_headers()
                self.wfile.write(str(e).encode())
        else:
            self.send_response(404)
            self.send_header(\'Content-type\', \'text/plain\')
            self.end_headers()
            self.wfile.write(b\'Not Found\')

    def store_user_data(self, name, email):
        conn = sqlite3.connect(\'users.db\')
        c = conn.cursor()
        c.execute(\'\'\'CREATE TABLE IF NOT EXISTS users
                     (id INTEGER PRIMARY KEY AUTOINCREMENT,
                      name TEXT,
                      email TEXT)\'\'\')
        c.execute("INSERT INTO users (name, email) VALUES (?, ?)", (name, email))
        conn.commit()
        conn.close()

def run(server_class=HTTPServer, handler_class=SimpleAPIHandler, port=8000):
    server_address = (\'\', port)
    httpd = server_class(server_address, handler_class)
    print(f"Server running on port {port}")
    httpd.serve_forever()

if __name__ == \'__main__\':
    run()
