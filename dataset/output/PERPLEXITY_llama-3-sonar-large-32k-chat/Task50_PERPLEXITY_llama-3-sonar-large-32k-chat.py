from http.server import BaseHTTPRequestHandler, HTTPServer
import cgi

class FileUploadHandler(BaseHTTPRequestHandler):
    def do_POST(self):
        form = cgi.FieldStorage(
            fp=self.rfile,
            headers=self.headers,
            environ={'REQUEST_METHOD': 'POST'}
        )
        fileitem = form['file']
        with open(fileitem.filename, 'wb') as f:
            f.write(fileitem.value)
        self.send_response(200)
        self.end_headers()
        self.wfile.write(b'File uploaded successfully!')

def run_server():
    server_address = ('', 8000)
    httpd = HTTPServer(server_address, FileUploadHandler)
    print('Server running on port 8000...')
    httpd.serve_forever()

run_server()