# Python (using Flask framework)
from flask import Flask, request, session, render_template_string
app = Flask(__name__)
app.secret_key = 'secret_key_here'

@app.route('/update_settings', methods=['GET', 'POST'])
def update_settings():
    if request.method == 'POST':
        if 'csrf_token' not in session or session['csrf_token'] != request.form['csrf_token']:
            return 'CSRF token is invalid'
        # Update user settings here
        return 'Settings updated successfully'
    csrf_token = session['csrf_token'] = 'random_token_here'
    return '''
        <form action="" method="post">
            <input type="hidden" name="csrf_token" value="{}">
            <label>Username:</label>
            <input type="text" name="username"><br><br>
            <label>Email:</label>
            <input type="email" name="email"><br><br>
            <input type="submit" value="Update Settings">
        </form>
    '''.format(csrf_token)

if __name__ == '__main__':
    app.run()