import sys

def redirect(user_input):
    if user_input == "home":
        print("Redirect to Home Page")
    elif user_input == "about":
        print("Redirect to About Page")
    elif user_input == "contact":
        print("Redirect to Contact Page")
    else:
        print("Page not found")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Please provide an argument.")
    else:
        redirect(sys.argv[1])