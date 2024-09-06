from flask import Flask, request

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        user_input = request.form['user_input']
        return f'<h1>You entered: {user_input}</h1>'
    return '''
        <form action="" method="post">
            <input type="text" name="user_input" placeholder="Enter something">
            <input type="submit" value="Submit">
        </form>
    '''

if __name__ == '__main__':
    app.run()