# Import the required modules for web framework
from flask import Flask, render_template_string, request, session

app = Flask(__name__)
app.secret_key = "supersecretkey"

# Route to display the form
@app.route('/settings', methods=['GET', 'POST'])
def settings():
    if request.method == 'POST':
        csrf_token = session.pop('_csrf_token', None)
        if not csrf_token or csrf_token != request.form.get('_csrf_token'):
            return "CSRF token is missing or incorrect", 403
        # Save settings logic here
        return "Settings updated!"
    
    # Render form with CSRF token
    session['_csrf_token'] = "aCSRFtoken"
    html_form = '''
    <form method="POST" action="/settings">
        <input type="hidden" name="_csrf_token" value="{{ csrf_token }}">
        <input type="text" name="username" placeholder="Username">
        <button type="submit">Save</button>
    </form>
    '''
    return render_template_string(html_form, csrf_token=session['_csrf_token'])

# Run the Flask application
if __name__ == "__main__":
    app.run(debug=True)