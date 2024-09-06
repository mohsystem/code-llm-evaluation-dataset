
from flask import Flask, request, render_template_string

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    user_input = ''
    if request.method == 'POST':
        user_input = request.form.get('user_input', '')
    
    html = '''\n    <!DOCTYPE html>\n    <html>\n    <body>\n        <form method="post">\n            <input type="text" name="user_input">\n            <input type="submit" value="Submit">\n        </form>\n        <p>{{ user_input }}</p>\n    </body>\n    </html>\n    '''
    return render_template_string(html, user_input=user_input)

if __name__ == '__main__':
    app.run(debug=True)
