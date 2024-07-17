import os
import secrets

from flask import Flask, session, render_template_string, request, redirect, url_for

app = Flask(__name__)
app.secret_key = os.urandom(24)

@app.route('/settings', methods=['GET', 'POST'])
def settings():
    if 'user_id' not in session:
        return redirect(url_for('login'))  # Replace with your login route

    if request.method == 'POST':
        # Verify CSRF token
        if not _verify_csrf_token(request.form.get('csrf_token')):
            return "Invalid CSRF token", 403

        # Process user settings update
        # ...

        return "Settings updated successfully!"

    # Generate and store CSRF token in the session
    csrf_token = _generate_csrf_token()
    session['csrf_token'] = csrf_token
    return render_template_string(
        """
        <form method="post">
            <input type="hidden" name="csrf_token" value="{{ csrf_token }}">
            <!-- Your settings form fields here -->
            <button type="submit">Update Settings</button>
        </form>
        """,
        csrf_token=csrf_token
    )

def _generate_csrf_token():
    return secrets.token_hex(16)

def _verify_csrf_token(token):
    if token is None:
        return False
    return token == session.get('csrf_token')

@app.route('/login')
def login():
    # Simulate login for demonstration
    session['user_id'] = 1
    return redirect(url_for('settings'))

if __name__ == '__main__':
    app.run(debug=True)