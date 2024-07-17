from flask import Flask, request, jsonify
import mysql.connector

app = Flask(__name__)

@app.route('/users', methods=['POST'])
def create_user():
    data = request.get_json()
    name = data['name']
    email = data['email']

    db = mysql.connector.connect(
        host="localhost",
        user="root",
        password="password",
        database="mydb"
    )
    cursor = db.cursor()

    cursor.execute("INSERT INTO users (name, email) VALUES (%s, %s)", (name, email))
    db.commit()

    return jsonify({'message': 'User created successfully'})

if __name__ == '__main__':
    app.run(debug=True)