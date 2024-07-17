import os
import uuid
from flask import Flask, request, session

app = Flask(__name__)
app.secret_key = os.urandom(24)

@app.before_request
def csrf_protect():
    if request.method == "POST":
        token = session.pop('_csrf_token', None)
        if not token or token != request.form.get('_csrf_token'):
            return "CSRF token missing or invalid", 403

@app.route('/form', methods=['GET', 'POST'])
def index():
    if request.method == "GET":
        token = uuid.uuid4().hex
        session['_csrf_token'] = token
        return '''
            <form action="" method="post">
                <input type="hidden" name="_csrf_token" value="{}">
                <input type="submit" value="Submit">
            </form>
        '''.format(token)
    else:
        return "Form submitted successfully"

if __name__ == '__main__':
    app.run(debug=True)