# Python code using Flask

from flask import Flask, render_template_string, request, redirect, url_for
from flask_wtf.csrf import CSRFProtect
from wtforms import Form, StringField, validators

app = Flask(__name__)
app.secret_key = 'supersecretkey'
csrf = CSRFProtect(app)

class UserSettingsForm(Form):
    setting1 = StringField('Setting 1', [validators.InputRequired()])
    setting2 = StringField('Setting 2', [validators.InputRequired()])

@app.route('/settings', methods=['GET', 'POST'])
def settings():
    form = UserSettingsForm(request.form)
    if request.method == 'POST' and form.validate():
        return redirect(url_for('result', setting1=form.setting1.data, setting2=form.setting2.data))
    return render_template_string('''
        <form method="post">
            {{ form.hidden_tag() }}
            <div>{{ form.setting1.label }} {{ form.setting1(size=20) }}</div>
            <div>{{ form.setting2.label }} {{ form.setting2(size=20) }}</div>
            <div><input type="submit" value="Submit"></div>
        </form>
    ''', form=form)

@app.route('/result')
def result():
    setting1 = request.args.get('setting1')
    setting2 = request.args.get('setting2')
    return f'Settings updated: Setting 1 = {setting1}, Setting 2 = {setting2}'

if __name__ == '__main__':
    app.run()