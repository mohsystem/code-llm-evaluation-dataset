from flask import Flask, request, render_template_string

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        user_input = request.form['userInput']
        return render_template_string('<h1>You entered: {{ user_input }}</h1>', user_input=user_input)
    return '''
        <form method="post">
            <input type="text" name="userInput">
            <input type="submit">
        </form>
    '''

if __name__ == '__main__':
    app.run()