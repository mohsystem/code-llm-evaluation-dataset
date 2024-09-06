from flask import Flask, render_template_string, request, session
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from wtforms.csrf.session import SessionCSRFProtect

app = Flask(__name__)
app.config['SECRET_KEY'] = 'your-secret-key'
csrf = SessionCSRFProtect(app)

class SettingsForm(FlaskForm):
    username = StringField('Username')
    submit = SubmitField('Update Settings')

@app.route('/', methods=['GET', 'POST'])
def settings():
    if 'user_id' not in session:
        return "Please log in to access settings."

    form = SettingsForm()
    if form.validate_on_submit():
        # Process user settings update here
        # ...

        return "Settings updated successfully!"

    return render_template_string('''
        <form method="POST">
            {{ form.hidden_tag() }}
            {{ form.username.label }} {{ form.username }}
            {{ form.submit }}
        </form>
    ''', form=form)

if __name__ == '__main__':
    app.run(debug=True)