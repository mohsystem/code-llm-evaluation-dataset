from flask import Flask, request

app = Flask(__name__)

@app.route('/')
def form():
    return '''
        <form method="post" action="/display">
            <input type="text" name="input_text">
            <input type="submit">
        </form>
    '''

@app.route('/display', methods=['POST'])
def display():
    user_input = request.form['input_text']
    return f'<h1>{user_input}</h1>'

if __name__ == '__main__':
    app.run(debug=True)