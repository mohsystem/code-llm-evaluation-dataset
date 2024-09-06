from flask import Flask, session
from flask_session import Session

app = Flask(__name__)
app.config['SESSION_TYPE'] = 'filesystem'
app.config['SECRET_KEY'] = 'super-secret-key'
Session(app)

@app.route('/login')
def login():
    session['username'] = 'user'
    return 'Logged in'

@app.route('/logout')
def logout():
    session.pop('username', None)
    return 'Logged out'