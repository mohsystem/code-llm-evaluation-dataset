# Python - Flask example
from flask import Flask, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/api', methods=['GET'])
def get_data():
    response = {
        'message': 'Hello from Flask API with CORS enabled!'
    }
    return jsonify(response)

if __name__ == '__main__':
    app.run(debug=True)