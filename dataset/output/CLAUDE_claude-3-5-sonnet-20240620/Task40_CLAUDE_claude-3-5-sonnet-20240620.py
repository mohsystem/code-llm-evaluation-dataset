
from flask import Flask, request, render_template
from flask_wtf.csrf import CSRFProtect
from wtforms import Form, StringField, SubmitField
from wtforms.validators import DataRequired

app = Flask(__name__)
app.config['SECRET_KEY'] = 'your-secret-key'
csrf = CSRFProtect(app)

class SettingsForm(Form):
    username = StringField('Username', validators=[DataRequired()])
    email = StringField('Email', validators=[DataRequired()])
    submit = SubmitField('Update Settings')

@app.route('/', methods=['GET', 'POST'])
def settings():
    form = SettingsForm(request.form)
    if request.method == 'POST' and form.validate():
        # Process the form data
        username = form.username.data
        email = form.email.data
        # Update user settings in database (not implemented here)
        return 'Settings updated successfully!'
    return render_template('settings.html', form=form)

if __name__ == '__main__':
    app.run(debug=True)

# Note: You'll need to create a 'templates' folder with a 'settings.html' file
# containing the form HTML and including the CSRF token like this:
# <form method="post">
#     {{ form.csrf_token }}
#     {{ form.username.label }} {{ form.username(size=20) }}
#     {{ form.email.label }} {{ form.email(size=20) }}
#     {{ form.submit }}
# </form>
