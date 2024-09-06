
from flask import Flask, request, session, render_template_string
import secrets

app = Flask(__name__)
app.secret_key = 'your_secret_key_here'

@app.before_request
def csrf_protect():
    if request.method == "POST":
        token = session.get('_csrf_token')
        if not token or token != request.form.get('_csrf_token'):
            return "CSRF token validation failed", 403

def generate_csrf_token():
    if '_csrf_token' not in session:
        session['_csrf_token'] = secrets.token_hex(16)
    return session['_csrf_token']

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        return "Form submitted successfully!"
    
    return render_template_string('''\n        <form method="post">\n            <input type="hidden" name="_csrf_token" value="{{ csrf_token() }}">\n            <input type="submit" value="Submit">\n        </form>\n    ''', csrf_token=generate_csrf_token)

if __name__ == '__main__':
    app.run(debug=True)
