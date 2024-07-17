
import os
from flask import Flask, request, render_template_string, session

app = Flask(__name__)
app.secret_key = os.urandom(24)

@app.route(\'/\', methods=[\'GET\', \'POST\'])
def index():
    if request.method == \'POST\':
        if request.form.get(\'csrf_token\') != session.get(\'csrf_token\'):
            return "CSRF token mismatch", 403
        return "Form submitted successfully"
    
    csrf_token = os.urandom(24).hex()
    session[\'csrf_token\'] = csrf_token
    
    form = \'\'\'
    <form method="post">
        <input type="hidden" name="csrf_token" value="{}">
        <input type="submit" value="Submit">
    </form>
    \'\'\'.format(csrf_token)
    
    return render_template_string(form)

if __name__ == \'__main__\':
    app.run(debug=True)
