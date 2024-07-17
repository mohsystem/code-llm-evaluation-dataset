from flask import Flask, request

app = Flask(__name__)

@app.route('/', methods=['GET'])
def get_user_input():
    user_input = request.args.get('userInput')
    return f"<html><body>You entered: {user_input}</body></html>"

if __name__ == '__main__':
    app.run()