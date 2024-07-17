
from flask import Flask, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route(\'/api/data\')
def get_data():
    return jsonify({"message": "This is CORS-enabled data"})

if __name__ == \'__main__\':
    app.run(port=5000)
