
import cgi
import cgitb
cgitb.enable()

print("Content-Type: text/html\
")
print("<html><body>")

form = cgi.FieldStorage()

if "userInput" in form:
    user_input = form.getvalue("userInput")
    print("<h2>User Input:</h2>")
    print(f"<p>{user_input}</p>")
else:
    print("<h2>Enter your input:</h2>")
    print("<form method=\'post\'>")
    print("<input type=\'text\' name=\'userInput\'>")
    print("<input type=\'submit\' value=\'Submit\'>")
    print("</form>")

print("</body></html>")
