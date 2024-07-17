from flask import Flask, request

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        name = request.form['name']
        return '<h1>Hello, {}!</h1>'.format(name)
    return '''
        <form action="" method="post">
            <input type="text" name="name" placeholder="Enter your name">
            <input type="submit" value="Submit">
        </form>
    '''

if __name__ == '__main__':
    app.run()