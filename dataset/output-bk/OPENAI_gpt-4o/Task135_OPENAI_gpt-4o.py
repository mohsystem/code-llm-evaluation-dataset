import os
import hmac
import hashlib
from flask import Flask, request, session, abort

app = Flask(__name__)
app.secret_key = os.urandom(24)

def generate_csrf_token():
    token = hmac.new(app.secret_key, os.urandom(24), hashlib.sha256).hexdigest()
    session['csrf_token'] = token
    return token

@app.before_request
def csrf_protect():
    if request.method == "POST":
        token = session.pop('csrf_token', None)
        if not token or token != request.form.get('_csrf_token'):
            abort(403)

@app.route('/form', methods=['GET', 'POST'])
def form():
    if request.method == 'POST':
        return 'Form submitted successfully!'
    token = generate_csrf_token()
    return '''
        <form method="post">
            <input type="hidden" name="_csrf_token" value="{}">
            <input type="submit" value="Submit">
        </form>
    '''.format(token)

if __name__ == '__main__':
    app.run(debug=True)