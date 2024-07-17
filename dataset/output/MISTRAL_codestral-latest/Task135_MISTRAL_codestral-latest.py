# Python Flask example
from flask import Flask, session, request
import os

app = Flask(__name__)
app.secret_key = os.urandom(24)

@app.route('/transfer_funds', methods=['POST'])
def transfer_funds():
    token = session.pop('_csrf_token', None)
    if not token or token != request.form.get('_csrf_token'):
        abort(403)
    # Process the funds transfer

@app.before_request
def csrf_protect():
    if request.method == "POST":
        token = session.pop('_csrf_token', None)
        if not token or token != request.form.get('_csrf_token'):
            abort(403)

@app.route('/')
def index():
    if '_csrf_token' not in session:
        session['_csrf_token'] = os.urandom(24)
    return render_template('index.html', csrf_token=session['_csrf_token'])