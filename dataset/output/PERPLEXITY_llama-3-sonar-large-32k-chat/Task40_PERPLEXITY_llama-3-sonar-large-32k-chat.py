from flask import Flask, request, session, render_template_string
import uuid

app = Flask(__name__)
app.secret_key = 'secret_key_here'

@app.route('/update', methods=['GET', 'POST'])
def update_user_settings():
    if request.method == 'GET':
        csrf_token = str(uuid.uuid4())
        session['csrf_token'] = csrf_token
        html = '''
            <html><body>
            <form action="/update" method="post">
            <input type="hidden" name="csrf_token" value="{{ csrf_token }}">
            Username: <input type="text" name="username"><br>
            Email: <input type="email" name="email"><br>
            <input type="submit" value="Update">
            </form>
            </body></html>
        '''
        return render_template_string(html, csrf_token=csrf_token)
    elif request.method == 'POST':
        csrf_token = session.get('csrf_token')
        token_from_request = request.form.get('csrf_token')
        if csrf_token == token_from_request:
            # Update user settings
            username = request.form.get('username')
            email = request.form.get('email')
            # Update user settings logic here
            return 'User settings updated successfully!'
        else:
            return 'CSRF token is invalid!', 403

if __name__ == '__main__':
    app.run()