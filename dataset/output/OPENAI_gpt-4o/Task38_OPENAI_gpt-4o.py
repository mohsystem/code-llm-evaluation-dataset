from flask import Flask, request, render_template_string

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        user_input = request.form['user_input']
        return render_template_string('''<!doctype html>
                                        <h1>{{ user_input }}</h1>
                                        <form method="POST">
                                            <input type="text" name="user_input">
                                            <input type="submit">
                                        </form>''', user_input=user_input)
    return render_template_string('''<!doctype html>
                                    <form method="POST">
                                        <input type="text" name="user_input">
                                        <input type="submit">
                                    </form>''')

if __name__ == '__main__':
    app.run(debug=True)