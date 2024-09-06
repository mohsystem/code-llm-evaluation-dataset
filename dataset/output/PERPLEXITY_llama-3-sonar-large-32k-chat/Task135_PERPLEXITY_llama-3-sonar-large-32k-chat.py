# Python code using Flask framework
from flask import Flask, request, session

app = Flask(__name__)
app.secret_key = 'secret_key_here'

@app.before_request
def csrf_protect():
    if request.method == 'POST':
        token = session.pop('_csrf_token', None)
        if not token or token != request.form.get('_csrf_token'):
            return 'CSRF token missing or invalid', 403

@app.route('/form', methods=['GET', 'POST'])
def form():
    if request.method == 'GET':
        token = session['_csrf_token'] = generate_token()
        return '''
            <form action="" method="post">
                <input type="hidden" name="_csrf_token" value="{}">
                <input type="submit" value="Submit">
            </form>
        '''.format(token)
    else:
        return 'Form submitted successfully'

def generate_token():
    return 'random_token_here'

if __name__ == '__main__':
    app.run()