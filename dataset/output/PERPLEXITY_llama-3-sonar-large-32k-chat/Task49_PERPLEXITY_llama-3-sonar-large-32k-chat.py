from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)

conn = sqlite3.connect('users.db')
c = conn.cursor()
c.execute('''CREATE TABLE IF NOT EXISTS users (name TEXT, email TEXT)''')
conn.commit()
conn.close()

@app.route('/users', methods=['POST'])
def create_user():
    data = request.get_json()
    conn = sqlite3.connect('users.db')
    c = conn.cursor()
    c.execute("INSERT INTO users (name, email) VALUES (?, ?)", (data['name'], data['email']))
    conn.commit()
    conn.close()
    return jsonify({'message': 'User created successfully'})

if __name__ == '__main__':
    app.run(debug=True)