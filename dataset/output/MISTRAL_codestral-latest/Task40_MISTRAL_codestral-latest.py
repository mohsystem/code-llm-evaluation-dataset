# Flask example
from flask import Flask, request, session
from flask_wtf import CSRFProtect

app = Flask(__name__)
app.config['SECRET_KEY'] = 'your-secret-key'
csrf = CSRFProtect(app)

@app.route('/update_settings', methods=['POST'])
def update_settings():
    # Your code to update settings here
    return 'Settings updated'