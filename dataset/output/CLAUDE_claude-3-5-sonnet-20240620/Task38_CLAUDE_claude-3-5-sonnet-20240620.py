
from flask import Flask, request, render_template_string

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def form():
    if request.method == 'POST':
        name = request.form.get('name')
        return render_template_string('<h1>Hello, {{ name }}!</h1>', name=name)
    return '''\n        <form method="post">\n            <input type="text" name="name">\n            <input type="submit" value="Submit">\n        </form>\n    '''

if __name__ == '__main__':
    app.run(debug=True)
