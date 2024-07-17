import re

email = input("Enter your email: ")

email_regex = "^[a-zA-Z0-9_+&*-]+(?:\\." +
              "[a-zA-Z0-9_+&*-]+)*@" +
              "(?:[a-zA-Z0-9-]+\\.)+[a-z" +
              "A-Z]{2,7}$"

if re.match(email_regex, email):
    print("Valid email address")
else:
    print("Invalid email address")