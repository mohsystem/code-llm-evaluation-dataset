# Python
from flask import Flask, request
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'
db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(50))
    email = db.Column(db.String(120))

@app.route('/user', methods=['POST'])
def add_user():
    user = User(name=request.json['name'], email=request.json['email'])
    db.session.add(user)
    db.session.commit()
    return 'User added successfully'

if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)