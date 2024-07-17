
import os
import cgi
import cgitb
import secrets
from http import cookies

cgitb.enable()

def generate_csrf_token():
    return secrets.token_urlsafe(32)

def set_csrf_cookie(token):
    cookie = cookies.SimpleCookie()
    cookie[\'csrf_token\'] = token
    cookie[\'csrf_token\'][\'httponly\'] = True
    cookie[\'csrf_token\'][\'samesite\'] = \'Strict\'
    print(cookie.output())

def get_csrf_cookie():
    cookie = cookies.SimpleCookie(os.environ.get(\'HTTP_COOKIE\'))
    return cookie.get(\'csrf_token\')

def render_form(csrf_token):
    print("Content-Type: text/html\
")
    print("<html><body>")
    print("<h1>User Settings</h1>")
    print("<form method=\'post\' action=\'settings.py\'>")
    print(f"<input type=\'hidden\' name=\'csrf_token\' value=\'{csrf_token}\'>")
    print("Name: <input type=\'text\' name=\'name\'><br>")
    print("Email: <input type=\'email\' name=\'email\'><br>")
    print("<input type=\'submit\' value=\'Update\'>")
    print("</form>")
    print("</body></html>")

def update_settings(name, email):
    print("Content-Type: text/html\
")
    print("<html><body>")
    print("<h1>Settings Updated</h1>")
    print(f"<p>Name: {name}</p>")
    print(f"<p>Email: {email}</p>")
    print("</body></html>")

def main():
    method = os.environ.get(\'REQUEST_METHOD\', \'GET\')

    if method == \'GET\':
        csrf_token = generate_csrf_token()
        set_csrf_cookie(csrf_token)
        render_form(csrf_token)
    elif method == \'POST\':
        form = cgi.FieldStorage()
        name = form.getvalue(\'name\', \'\')
        email = form.getvalue(\'email\', \'\')
        csrf_token = form.getvalue(\'csrf_token\', \'\')

        cookie_token = get_csrf_cookie()

        if cookie_token and cookie_token.value == csrf_token:
            update_settings(name, email)
        else:
            print("Content-Type: text/html\
")
            print("<html><body>")
            print("<h1>Error: Invalid CSRF Token</h1>")
            print("</body></html>")

if __name__ == "__main__":
    main()
