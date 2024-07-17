from flask import Flask, request
import sqlite3

app = Flask(__name__)

def store_data(data):
    conn = sqlite3.connect('userdata.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS Users (data TEXT)''')
    c.execute("INSERT INTO Users (data) VALUES (?)", (data,))
    conn.commit()
    conn.close()

@app.route('/store', methods=['POST'])
def store():
    data = request.data.decode('utf-8')
    store_data(data)
    return "Data stored successfully", 200

if __name__ == '__main__':
    app.run(port=8080)