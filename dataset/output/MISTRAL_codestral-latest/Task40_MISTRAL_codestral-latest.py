from flask import Flask, request, session
from flask_wtf import CSRFProtect, FlaskForm
from wtforms import StringField, SubmitField

app = Flask(__name__)
app.config['SECRET_KEY'] = 'your-secret-key'
csrf = CSRFProtect(app)

class UpdateForm(FlaskForm):
    setting = StringField('Setting')
    submit = SubmitField('Update')

@app.route('/update', methods=['GET', 'POST'])
def update():
    form = UpdateForm()
    if form.validate_on_submit():
        # Update user settings here
        return 'Settings updated'
    return '''
        <form method="POST">
            {}<br>
            {}<br>
            <input type="submit" value="Update">
        </form>
    '''.format(form.setting(), form.csrf_token)