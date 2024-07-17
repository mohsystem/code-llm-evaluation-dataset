from flask import Flask, request, session

app = Flask(__name__)
app.secret_key = 'secret_key_here'

sessions = {}

@app.route('/session', methods=['GET'])
def manage_session():
    action = request.args.get('action')
    if action == 'create':
        create_session()
    elif action == 'terminate':
        terminate_session(request.args.get('sessionId'))
    return ''

def create_session():
    session_id = session.sid
    sessions[session_id] = session
    return ''

def terminate_session(session_id):
    if session_id in sessions:
        del sessions[session_id]
    return ''

if __name__ == '__main__':
    app.run(debug=True)