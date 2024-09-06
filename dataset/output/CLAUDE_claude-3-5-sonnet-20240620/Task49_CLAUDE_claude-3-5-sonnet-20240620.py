
from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)

@app.route('/api/users', methods=['POST'])
def create_user():
    data = request.json
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS users\n                      (id INTEGER PRIMARY KEY AUTOINCREMENT,\n                       name TEXT NOT NULL,\n                       email TEXT NOT NULL UNIQUE)''')
    cursor.execute('INSERT INTO users (name, email) VALUES (?, ?)',
                   (data['name'], data['email']))
    conn.commit()
    user_id = cursor.lastrowid
    conn.close()
    return jsonify({'id': user_id, 'message': 'User created successfully'}), 201

if __name__ == '__main__':
    app.run(debug=True)
