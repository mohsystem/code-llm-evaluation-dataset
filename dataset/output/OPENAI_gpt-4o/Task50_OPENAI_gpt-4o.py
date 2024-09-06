# Python: Server to upload files
from flask import Flask, request, jsonify
import os

app = Flask(__name__)
UPLOAD_FOLDER = 'uploads/'
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

@app.route('/upload', methods=['POST'])
def upload_file():
    if 'file' not in request.files:
        return jsonify({'message': 'No file part'})
    file = request.files['file']
    if file.filename == '':
        return jsonify({'message': 'No selected file'})
    file.save(os.path.join(UPLOAD_FOLDER, file.filename))
    return jsonify({'message': 'File successfully uploaded'})

if __name__ == '__main__':
    app.run(port=5000)