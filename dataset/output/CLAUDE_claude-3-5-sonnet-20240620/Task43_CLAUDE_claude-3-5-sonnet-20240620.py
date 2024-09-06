
import os
import time
from flask import Flask, request, session, jsonify
from werkzeug.security import generate_password_hash, check_password_hash

app = Flask(__name__)
app.secret_key = os.urandom(24)
app.config['PERMANENT_SESSION_LIFETIME'] = 1800  # 30 minutes

users = {}

@app.route('/register', methods=['POST'])
def register():
    username = request.json.get('username')
    password = request.json.get('password')
    if username in users:
        return jsonify({"error": "Username already exists"}), 400
    users[username] = generate_password_hash(password)
    return jsonify({"message": "User registered successfully"}), 201

@app.route('/login', methods=['POST'])
def login():
    username = request.json.get('username')
    password = request.json.get('password')
    if username not in users or not check_password_hash(users[username], password):
        return jsonify({"error": "Invalid credentials"}), 401
    session['username'] = username
    session['login_time'] = time.time()
    return jsonify({"message": "Logged in successfully"}), 200

@app.route('/logout', methods=['POST'])
def logout():
    session.pop('username', None)
    session.pop('login_time', None)
    return jsonify({"message": "Logged out successfully"}), 200

@app.route('/protected', methods=['GET'])
def protected():
    if 'username' not in session:
        return jsonify({"error": "Unauthorized"}), 401
    if time.time() - session['login_time'] > app.config['PERMANENT_SESSION_LIFETIME'].total_seconds():
        session.pop('username', None)
        session.pop('login_time', None)
        return jsonify({"error": "Session expired"}), 401
    return jsonify({"message": f"Hello, {session['username']}!"}), 200

if __name__ == '__main__':
    app.run(debug=True)
