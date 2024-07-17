
#!/usr/bin/env python3
import cgi
import cgitb

cgitb.enable()

def print_html_header():
    print("Content-Type: text/html\
")
    print("<html><head><title>Form Results</title></head><body>")

def print_html_footer():
    print("</body></html>")

def main():
    print_html_header()

    form = cgi.FieldStorage()

    if "name" in form and "email" in form:
        name = form.getvalue("name")
        email = form.getvalue("email")
        print("<h2>Submitted Information:</h2>")
        print(f"<p>Name: {name}</p>")
        print(f"<p>Email: {email}</p>")
    else:
        print("<h2>User Input Form</h2>")
        print("<form method=\'post\'>")
        print("Name: <input type=\'text\' name=\'name\'><br>")
        print("Email: <input type=\'text\' name=\'email\'><br>")
        print("<input type=\'submit\' value=\'Submit\'>")
        print("</form>")

    print_html_footer()

if __name__ == "__main__":
    main()
