from flask import Flask, session
from flask_session import Session

app = Flask(__name__)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    if "visits" in session:
        session["visits"] += 1
    else:
        session["visits"] = 1
    return f"You have visited this page {session['visits']} times."

if __name__ == "__main__":
    app.run(debug=True)