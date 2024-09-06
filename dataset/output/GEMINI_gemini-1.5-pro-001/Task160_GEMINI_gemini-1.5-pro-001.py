import requests
from flask import Flask, request

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        url = request.form['url']
        try:
            response = requests.get(url)
            response.raise_for_status()  # Raise an exception for bad status codes
            return f"Request successful! Status code: {response.status_code}"
        except requests.exceptions.RequestException as e:
            return f"Request failed: {e}"
    else:
        return '''
            <form method="post">
                <label for="url">Enter URL:</label>
                <input type="text" id="url" name="url" required>
                <br>
                <button type="submit">Make Request</button>
            </form>
        '''

if __name__ == '__main__':
    app.run(debug=True)