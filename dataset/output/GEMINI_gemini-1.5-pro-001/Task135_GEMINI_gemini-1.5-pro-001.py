from flask import Flask, render_template_string, request, session
from flask_wtf.csrf import CSRFProtect

app = Flask(__name__)
app.secret_key = 'your_secret_key'  # Replace with a strong, randomly generated key
csrf = CSRFProtect(app)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        # Process the form data here
        return 'Form submitted successfully!'
    else:
        return render_template_string('''
            <form method="post">
                <input type="hidden" name="csrf_token" value="{{ csrf_token() }}">
                <button type="submit">Submit</button>
            </form>
        ''')

if __name__ == '__main__':
    app.run(debug=True)