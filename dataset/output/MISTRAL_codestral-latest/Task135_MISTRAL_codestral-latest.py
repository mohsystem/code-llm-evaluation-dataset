from flask import Flask, request
from flask_wtf import CSRFProtect

app = Flask(__name__)
csrf = CSRFProtect(app)

@app.route('/transfer', methods=['POST'])
def transfer_funds():
    # Check the CSRF token
    if not csrf.validate_csrf(request.form.get('csrf_token')):
        return 'CSRF token validation failed', 400

    # Process the request
    # ...