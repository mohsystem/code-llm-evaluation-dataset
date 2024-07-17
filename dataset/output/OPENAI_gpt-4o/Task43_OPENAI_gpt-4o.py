# main.py

from flask import Flask, session, request
from flask.sessions import SecureCookieSessionInterface

app = Flask(__name__)
app.secret_key = 'supersecretkey'
sessions = {}

class CustomSessionInterface(SecureCookieSessionInterface):
    def save_session(self, *args, **kwargs):
        pass

app.session_interface = CustomSessionInterface()

@app.route('/', methods=['GET'])
def create_session():
    session_id = request.remote_addr
    session['user'] = session_id
    sessions[session_id] = session
    return f'Session created: {session_id}'

@app.route('/terminate', methods=['POST'])
def terminate_session():
    session_id = request.form.get('sessionId')
    if session_id in sessions:
        sessions.pop(session_id).clear()
        return f'Session terminated: {session_id}'
    else:
        return f'Session not found: {session_id}'

if __name__ == '__main__':
    app.run(debug=True)