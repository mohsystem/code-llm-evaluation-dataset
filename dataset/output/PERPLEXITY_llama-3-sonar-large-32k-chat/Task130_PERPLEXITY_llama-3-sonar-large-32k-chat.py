code here:
from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/api/data', methods=['GET', 'OPTIONS'])
def get_data():
    if request.method == 'OPTIONS':
        return jsonify({'Allow': 'GET, OPTIONS'})
    return jsonify({'data': 'Hello, World!'})

if __name__ == '__main__':
    app.run(debug=True)