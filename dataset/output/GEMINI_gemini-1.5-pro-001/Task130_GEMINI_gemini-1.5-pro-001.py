from flask import Flask, jsonify, request

app = Flask(__name__)

@app.route('/api/data')
def get_data():
    data = {'name': 'John Doe', 'age': 30}
    response = jsonify(data)
    response.headers.add('Access-Control-Allow-Origin', '*')
    return response

if __name__ == '__main__':
    app.run()